#pragma once
//模板化，可以接受任意类型
//构造方法，赋值一个指针
//析构方法，释放指针
//不标准的复制构造（转移内部指针控制权）
//不标准的复制赋值（转移内部指针控制权）
//reset() 释放之前的，获得新的指针
//release() 释放控制权，返回指针
//operator*() 模拟指针访问方法
//operator->()模拟箭头式访问方法
//get() 获得指针指向的指针

template<class T>
class _autoptr
{
	T*obj = nullptr;
public:
	_autoptr(T*ptr) :obj(ptr)
	{

	}

	_autoptr() = default;

	~_autoptr()
	{
		delete obj;
	}
	_autoptr(_autoptr<T>& ptr)
	{
		obj = ptr.obj;
		ptr.obj = nullptr;
	}
	_autoptr& operator=(_autoptr<T>& ptr)
	{
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}
	void reset(T* newptr)
	{
		delete obj;
		obj = newptr;
	}
	T*release()
	{
		auto tem = obj;
		obj = nullptr;
		return tem;
	}
	T& operator*()
	{
		return *obj;
	}
	T* operator->()
	{
		return obj;
	}
	T* get()
	{
		return *obj;
	}
};