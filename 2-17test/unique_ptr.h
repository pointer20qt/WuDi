#pragma once


template<class T> class L_uniquePtr
{
	T* obj = nullptr;
public:
	L_uniquePtr(T* ptr) :obj(ptr)
	{

	}
	L_uniquePtr(const T&) = delete;
	L_uniquePtr() = default;
	~L_uniquePtr()
	{
		delete obj;
	}
	L_uniquePtr& operator=(const L_uniquePtr<T>&) = delete;
	L_uniquePtr(L_uniquePtr<T>&& ptr) :obj(ptr.release())
	{

	}
	L_uniquePtr& operator=(L_uniquePtr<T>&& ptr)
	{
		obj = ptr.release();
		return *this;
	}
	void reset(T* newPtr = nullptr)
	{
		delete obj;
		obj = newPtr;
	}
	T* release()
	{
		auto temP = obj;
		obj = nullptr;
		return temP;
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
		return obj;
	}
};