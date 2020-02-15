#include<iostream>
#include<vector>
using namespace std;


template<class T> class L_stack{
	std::vector<T> arr;
public:
	void push(T&& obj){
		arr.push_back(obj);
	}
	void pop(){
		arr.pop_back();
	}
	T& top(){
		return arr.back();
	}
	size_t size(){
		return arr.size();
	}
	bool empty(){
		return arr.empty();
	}
};

int main()
{
	L_stack<int>l;
	l.push(6);
	l.push(7);
	l.push(8);
	l.push(9);
	l.push(10);
	cout << l.top() << endl;//10
	l.pop();
	cout << l.top() << endl;//9
	cout << l.size() << endl;//4
}