#pragma once
//ģ�廯�����Խ�����������
//���췽������ֵһ��ָ��
//�����������ͷ�ָ��
//����׼�ĸ��ƹ��죨ת���ڲ�ָ�����Ȩ��
//����׼�ĸ��Ƹ�ֵ��ת���ڲ�ָ�����Ȩ��
//reset() �ͷ�֮ǰ�ģ�����µ�ָ��
//release() �ͷſ���Ȩ������ָ��
//operator*() ģ��ָ����ʷ���
//operator->()ģ���ͷʽ���ʷ���
//get() ���ָ��ָ���ָ��

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