#pragma once


//建立一个引用计数类
template<class T> class Ref
{
	int r_count = 0;//当前资源计数
	T* object = nullptr;//对象
public:
	Ref(T* target) :object(target)
	{
		++r_count;
	}
	inline void increase()//内连函数：函数一旦内连直接展开到函数里
	{
		r_count++;
	}
	inline void reduce()
	{
		r_count--;
		if (r_count == 0)//减到0的时候
		{
			delete object;//对象释放
			delete this;//引用计数释放
		}
	}
	//获得对应的对象
	T* get()
	{
		return object;
	}
	int getCount(){
		return r_count;
	}
};
//shared智能指针需要的方法
/*
无参构造，传递指针构造，拷贝构造，移动构造，拷贝赋值，移动赋值,交换，析构函数
reset(T*)替换对象。 reset() 销毁对象
operator*() operator->()
get()获得裸指针
use_count() 获得引用计数
unique() 判断当前是否唯一  use_count()==1
operator bool() 是否关联对象
*/

//智能指针类
template<class T> class LSharedPtr
{
	Ref<T>* ref = nullptr;//内部指向引用计数
public:
	LSharedPtr() = default;//无参构造
	~LSharedPtr()
	{
		if (ref)
		{
			ref->reduce();
		}
	}
	LSharedPtr(T* newP)//传递指针构造
	{
		ref = new Ref<T>(newP);
	}
	LSharedPtr(const LSharedPtr& other)//拷贝构造，指向同一个
	{
		ref = other.ref;
		if (ref)//当他不为空指针时。无参构造时为空指针，调用会出问题
		{
			ref->increase();
		}
	}
	LSharedPtr(LSharedPtr&& other)//移动构造
	{
		swap(ref, other.ref);//ref一定是空的
	}
	LSharedPtr& operator=(const LSharedPtr& other)//拷贝赋值，拷贝赋值出的新的应该和原来的指向同一个引用计数，原来的减一，新的加一
	{
		if (ref)
		{
			ref->reduce();
		}
		ref = other.ref;//赋值成新的
		if (ref)
		{
			ref->increase();
		}
		return *this;
	}
	LSharedPtr& operator=(LSharedPtr&& other)//移动赋值
	{
		if (ref)
		{
			ref->reduce();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	void swap(LSharedPtr& other)//交换
	{
		swap(ref, other.ref);
	}
	void reset(T* target = nullptr)//reset(T*)替换对象，reset() 销毁对象
	{
		if (ref)
		{
			ref->reduce();
		}
		if (target != nullptr)
		{
			ref = new Ref<T>(target);
		}
		else
		{
			ref = nullptr;
		}
	}
	T& operator*()
	{
		if (ref)
		{
			return *ref->get();
		}
		else{
			return *(T*)nullptr;
		}
	}
	T* operator->(){
		if (ref){
			return ref->get();
		}
		else{
			return (T*)nullptr;
		}
	}
	T* get()
	{
		if (ref)
		{
			return ref->get();
		}
		else
		{
			return (T*)nullptr;
		}
	}
	int use_count()
	{
		if (ref)
		{
			return ref->getCount();
		}
		else
		{
			return 0;
		}
	}
	bool unique()
	{
		if (ref)
		{
			return ref->getCount() == 1;
		}
		else
		{
			return false;
		}
	}
	//判断当前只能指针是否和对象关联
	operator bool()
	{
		return ref != nullptr;
	}
};