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
class queue
{
private:
	Node<T>* tail;
	Node<T>* head;
public:
	queue();
	queue(const queue<T>& otherQueue);
	queue<T>& operator=(const queue<T>&);
	~queue();
	void push(T data);
	T& pop();
	T& back();
	bool isEmpty();
	int size();
};

template<class T>
inline queue<T>::queue()
{
	tail = nullptr;
	head = nullptr;
}

template<class T>
inline queue<T>::queue(const queue<T>& otherQueue)
{
	if (otherQueue.tail == nullptr)
		return;
	Node<T>* el = otherQueue.tail;
	while (el != nullptr)
	{
		this->push(el->data);
		el = el->next;
	}
}

template<class T>
inline queue<T>& queue<T>::operator=(const queue<T>& otherQueue)
{
	if (otherQueue.tail == nullptr)
	{
		this->~queue();
		return *this;
	}
	this->~queue();
	Node<T>* el = otherQueue.tail;
	while (el != nullptr)
	{
		this->push(el->data);
		el = el->next;
	}
	return *this;
}

template<class T>
inline queue<T>::~queue()
{
	if (tail == nullptr)
		return;
	Node<T>* el;
	while (tail != nullptr)
	{
		el = tail->next;
		tail->next = nullptr;
		delete tail;
		tail = el;
	}
}

template<class T>
inline void queue<T>::push(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>();
		head->data = data;
		tail = head;
		return;
	}
	Node<T>* new_el = new Node<T>();
	new_el->data = data;
	head->next = new_el;
	head = new_el;

}

template<class T>
inline T& queue<T>::pop()
{
	if (tail == nullptr)
		throw -1;
	if (tail->next == nullptr)
	{
		T res = tail->data;
		delete tail;
		tail = nullptr;
		head = nullptr;
		return res;
	}
	else
	{
		Node<T>* el = tail->next;
		T res = tail->data;
		tail->next = nullptr;
		delete tail;
		tail = el;
		return res;
	}
}

template<class T>
inline T& queue<T>::back()
{
	if (tail == nullptr)
		throw -1;
	return tail->data;
}

template<class T>
inline bool queue<T>::isEmpty()
{
	if (tail == nullptr or head == nullptr)
		return true;
	return false;
}

template<class T>
inline int queue<T>::size()
{
	if (tail == nullptr)
		return 0;
	Node<T>* el = tail;
	int count = 1;
	while (el->next != nullptr)
	{
		el = el->next;
		count++;
	}
	return count;
}
