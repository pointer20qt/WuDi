#pragma once

template<class T> class Ref
{
	int r_count = 0;//��ǰ��Դ����
	int w_count = 0;//������ָ�����
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
	inline void increase_w()
	{
		w_count++;
	}
	inline void reduce()
	{
		r_count--;
		if (r_count == 0)//����0��ʱ��
		{
			delete object;//�����ͷ�
			object = nullptr;
			if (w_count = 0)//w,r��Ϊ0ʱ
			{
				delete this;//���ü����ͷ�
			}
		}
	}
	inline void reduce_w()
	{
		w_count--;
		if (w_count ==0&&r_count==0)//����0��ʱ��
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
template<class T> class Weakptr;
template<class T> class LSharedPtr
{
	friend class Weakptr<T>;
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
	LSharedPtr(Ref<T> *newRef)
	{
		ref = newRef;
		if (ref)
		{
			ref->increase_w();
		}
	}
	LSharedPtr(T* newP)//����ָ�빹��
	{
		ref = new Ref<T>(newP);
	}
	LSharedPtr(const LSharedPtr<T>& other)//�������죬ָ��ͬһ��
	{
		ref = other.ref;
		if (ref)//������Ϊ��ָ��ʱ���޲ι���ʱΪ��ָ�룬���û������
		{
			ref->increase();
		}
	}
	LSharedPtr(LSharedPtr<T>&& other)//�ƶ�����
	{
		swap(ref, other.ref);//refһ���ǿյ�
	}
	LSharedPtr& operator=(const LSharedPtr<T>& other)//������ֵ��������ֵ�����µ�Ӧ�ú�ԭ����ָ��ͬһ�����ü�����ԭ���ļ�һ���µļ�һ
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
	LSharedPtr& operator=(LSharedPtr<T>&& other)//�ƶ���ֵ
	{
		if (ref)
		{
			ref->reduce();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	void swap(LSharedPtr<T>& other)//����
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
template<class T> class Weakptr
{
	Ref<T>* ref = nullptr;
public:
	Weakptr() = default;
	Weakptr(LSharedPtr<T>& other):ref(other.ref)//�´���һ��waek_ptr����shared_ptr����ȥ���µ�weak_ptrָ��shared_ptrָ��Ķ���//ref=other.ref
	{
		if (ref)
		{
			ref->increase_w();
		}	
	}
	Weakptr(const Weakptr<T>& other) :ref(other.ref)//��������
	{
		if (ref)
		{
			ref->increase_w();
		}
	}
	Weakptr(Weakptr<T>&& other)//�ƶ�����
	{
		swap(ref, other.ref);
	}
	Weakptr<T>& operator=(const Weakptr<T>&other)//������ֵ����һ��������Ķ�����ֵ����һ���ˣ���һ����ԭ�����ŵ����ü���-1�����ϵ��µ����ü���+1
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
	Weakptr<T>& operator=(Weakptr<T>&& other)//�ƶ���ֵ
	{
		if (ref)
		{
			ref->reduce_w();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	int use_count()//���ع���ö���� shared_ptr ��������
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
	bool expired()//��鱻���õĶ����Ƿ���ɾ��
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
	LSharedPtr<T> lock()//�����������õĶ����shared_ptr
	{
		LSharedPtr<T> tem(ref);
		return tem;
	}
	void swap(Weakptr<T>& other)//����
	{
		swap(ref, other.ref);
	}
	void reset()//����
	{
		ref->reduce_w;
		ref = nullptr;
	}
};