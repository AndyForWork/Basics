#pragma once

template<class T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>()
	{
		data = T();
		next = nullptr;
	}
};

template<class T>
class stack
{
	Node<T>* top;
public:
	stack();
	stack(const stack<T>&);
	stack<T>& operator=(const stack<T>& otherStack);
	~stack();
	void push(T data);
	T& front();
	T& pop();
	int size();
	bool isEmpty();


};


template<class T>
inline stack<T>::stack()
{
	this->top = nullptr;
}

template<class T>
inline stack<T>::stack(const stack<T>& otherStack)
{
	if (otherStack.top == nullptr)
		return;
	Node<T>* el = otherStack.top;
	stack<T> st;
	while (el != nullptr)
	{
		st.push(el->data);
		el = el->next;
	}
	el = st.top;
	while (el != nullptr)
	{
		this->push(el->data);
		el = el->next;
	}
	st.~stack();

}

template<class T>
inline stack<T>& stack<T>::operator=(const stack<T>& otherStack)
{
	if (otherStack.top == nullptr)
	{
		this->~stack();
		return *this;
	}
	this->~stack();
	Node<T>* el = otherStack.top;
	stack<T> st;
	while (el != nullptr)
	{
		st.push(el->data);
		el = el->next;
	}
	el = st.top;
	while (el != nullptr)
	{
		this->push(el->data);
		el = el->next;
	}
	st.~stack();
	return *this;


}

template<class T>
inline stack<T>::~stack()
{
	if (top == nullptr)
		return;
	while (top != nullptr)
	{
		Node<T>* el = top->next;
		top->next = nullptr;
		delete top;
		top = el;
	}
}

template<class T>
inline void stack<T>::push(T data)
{
	Node<T>* new_el = new Node<T>();
	new_el->data = data;
	new_el->next = top;
	top = new_el;
}

template<class T>
inline T& stack<T>::front()
{
	if (top == nullptr)
		throw -1;
	return top->data;
}

template<class T>
inline T& stack<T>::pop()
{
	if (top == nullptr)
		throw -1;
	Node<T>* el = top->next;
	top->next = nullptr;
	T res = top->data;
	delete top;
	top = el;
	return res;
}

template<class T>
inline int stack<T>::size()
{
	if (top == nullptr)
		return 0;
	Node<T>* el = top;
	int count = 1;

	while (el->next != nullptr)
	{
		el = el->next;
		count++;
	}
	return count;
}

template<class T>
inline bool stack<T>::isEmpty()
{
	if (top == nullptr)
		return true;
	return false;
}
