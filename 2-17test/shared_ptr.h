#pragma once


//����һ�����ü�����
template<class T> class Ref
{
	int r_count = 0;//��ǰ��Դ����
	T* object = nullptr;//����
public:
	Ref(T* target) :object(target)
	{
		++r_count;
	}
	inline void increase()//��������������һ������ֱ��չ����������
	{
		r_count++;
	}
	inline void reduce()
	{
		r_count--;
		if (r_count == 0)//����0��ʱ��
		{
			delete object;//�����ͷ�
			delete this;//���ü����ͷ�
		}
	}
	//��ö�Ӧ�Ķ���
	T* get()
	{
		return object;
	}
	int getCount(){
		return r_count;
	}
};
//shared����ָ����Ҫ�ķ���
/*
�޲ι��죬����ָ�빹�죬�������죬�ƶ����죬������ֵ���ƶ���ֵ,��������������
reset(T*)�滻���� reset() ���ٶ���
operator*() operator->()
get()�����ָ��
use_count() ������ü���
unique() �жϵ�ǰ�Ƿ�Ψһ  use_count()==1
operator bool() �Ƿ��������
*/

//����ָ����
template<class T> class LSharedPtr
{
	Ref<T>* ref = nullptr;//�ڲ�ָ�����ü���
public:
	LSharedPtr() = default;//�޲ι���
	~LSharedPtr()
	{
		if (ref)
		{
			ref->reduce();
		}
	}
	LSharedPtr(T* newP)//����ָ�빹��
	{
		ref = new Ref<T>(newP);
	}
	LSharedPtr(const LSharedPtr& other)//�������죬ָ��ͬһ��
	{
		ref = other.ref;
		if (ref)//������Ϊ��ָ��ʱ���޲ι���ʱΪ��ָ�룬���û������
		{
			ref->increase();
		}
	}
	LSharedPtr(LSharedPtr&& other)//�ƶ�����
	{
		swap(ref, other.ref);//refһ���ǿյ�
	}
	LSharedPtr& operator=(const LSharedPtr& other)//������ֵ��������ֵ�����µ�Ӧ�ú�ԭ����ָ��ͬһ�����ü�����ԭ���ļ�һ���µļ�һ
	{
		if (ref)
		{
			ref->reduce();
		}
		ref = other.ref;//��ֵ���µ�
		if (ref)
		{
			ref->increase();
		}
		return *this;
	}
	LSharedPtr& operator=(LSharedPtr&& other)//�ƶ���ֵ
	{
		if (ref)
		{
			ref->reduce();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	void swap(LSharedPtr& other)//����
	{
		swap(ref, other.ref);
	}
	void reset(T* target = nullptr)//reset(T*)�滻����reset() ���ٶ���
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
	//�жϵ�ǰֻ��ָ���Ƿ�Ͷ������
	operator bool()
	{
		return ref != nullptr;
	}
};