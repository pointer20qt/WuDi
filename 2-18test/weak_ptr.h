#pragma once

template<class T> class Ref
{
	int r_count = 0;//当前资源计数
	int w_count = 0;//弱引用指针计数
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
	inline void increase_w()
	{
		w_count++;
	}
	inline void reduce()
	{
		r_count--;
		if (r_count == 0)//减到0的时候
		{
			delete object;//对象释放
			object = nullptr;
			if (w_count = 0)//w,r都为0时
			{
				delete this;//引用计数释放
			}
		}
	}
	inline void reduce_w()
	{
		w_count--;
		if (w_count ==0&&r_count==0)//减到0的时候
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
template<class T> class Weakptr;
template<class T> class LSharedPtr
{
	friend class Weakptr<T>;
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
	LSharedPtr(Ref<T> *newRef)
	{
		ref = newRef;
		if (ref)
		{
			ref->increase_w();
		}
	}
	LSharedPtr(T* newP)//传递指针构造
	{
		ref = new Ref<T>(newP);
	}
	LSharedPtr(const LSharedPtr<T>& other)//拷贝构造，指向同一个
	{
		ref = other.ref;
		if (ref)//当他不为空指针时。无参构造时为空指针，调用会出问题
		{
			ref->increase();
		}
	}
	LSharedPtr(LSharedPtr<T>&& other)//移动构造
	{
		swap(ref, other.ref);//ref一定是空的
	}
	LSharedPtr& operator=(const LSharedPtr<T>& other)//拷贝赋值，拷贝赋值出的新的应该和原来的指向同一个引用计数，原来的减一，新的加一
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
	LSharedPtr& operator=(LSharedPtr<T>&& other)//移动赋值
	{
		if (ref)
		{
			ref->reduce();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	void swap(LSharedPtr<T>& other)//交换
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
template<class T> class Weakptr
{
	Ref<T>* ref = nullptr;
public:
	Weakptr() = default;
	Weakptr(LSharedPtr<T>& other):ref(other.ref)//新创建一个waek_ptr，把shared_ptr传进去让新的weak_ptr指向shared_ptr指向的东西//ref=other.ref
	{
		if (ref)
		{
			ref->increase_w();
		}	
	}
	Weakptr(const Weakptr<T>& other) :ref(other.ref)//拷贝构造
	{
		if (ref)
		{
			ref->increase_w();
		}
	}
	Weakptr(Weakptr<T>&& other)//移动构造
	{
		swap(ref, other.ref);
	}
	Weakptr<T>& operator=(const Weakptr<T>&other)//拷贝赋值：把一个人里面的东西赋值给另一个人，另一个人原来连着的引用计数-1，连上的新的引用计数+1
	{
		if (ref)
		{
			ref->reduce_w();
		}
		ref = other.ref;
		if (ref)
		{
			ref->increase_w();
		}
		return *this;
	}
	Weakptr<T>& operator=(Weakptr<T>&& other)//移动赋值
	{
		if (ref)
		{
			ref->reduce_w();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	int use_count()//返回管理该对象的 shared_ptr 对象数量
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
	bool expired()//检查被引用的对象是否已删除
	{
		if (ref)
		{
			return ref->getCount() > 0;
		}
		else
		{
			return false;
		}
	}
	LSharedPtr<T> lock()//创建管理被引用的对象的shared_ptr
	{
		LSharedPtr<T> tem(ref);
		return tem;
	}
	void swap(Weakptr<T>& other)//交换
	{
		swap(ref, other.ref);
	}
	void reset()//销毁
	{
		ref->reduce_w;
		ref = nullptr;
	}
};