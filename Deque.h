#pragma once

template<class T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
	Node()
	{
		next = nullptr;
		prev = nullptr;
	}
};

template<class T>
class deque
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	deque();
	deque(deque<T>&);
	deque<T>& operator=(deque<T>&);
	~deque();
	T& front();
	T& back();
	T& pop_back();
	T& pop_front();
	void push_back(T data);
	void push_front(T data);
	int size();
	bool isEmpty();
};

template<class T>
inline deque<T>::deque()
{
	head = nullptr;
	tail = nullptr;
}

template<class T>
deque<T>::deque(deque<T>& otherDeque)
{
	if (otherDeque.isEmpty())
		this->~deque();
	this->~deque();
	Node<T>* el = otherDeque.head;
	while (el != nullptr)
	{
		this->push_back(el->data);
		el = el->prev;
	}
}

template<class T>
inline deque<T>& deque<T>::operator=(deque<T>& otherDeque)
{
	if (otherDeque.isEmpty())
	{
		this->~deque();
		return *this;
	}
	this->~deque();
	Node<T>* el = otherDeque.head;
	while (el != nullptr)
	{
		this->push_back(el->data);
		el = el->prev;
	}
	return *this;
}

template<class T>
inline deque<T>::~deque()
{
	if (tail == nullptr)
		return;
	else
	{
		while (tail->next != nullptr)
		{
			Node<T>* el = tail->next;
			tail->prev = nullptr;
			tail->next = nullptr;
			delete tail;
			tail = el;
		}
		delete tail;
	}
}

template<class T>
inline T& deque<T>::front()
{
	if (head == nullptr)
		throw -1;
	return head->data;
}

template<class T>
inline T& deque<T>::back()
{
	if (tail == nullptr)
		throw -1;
	return tail->data;
}

template<class T>
inline T& deque<T>::pop_back()
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
		T res = tail->data;
		Node<T>* el = tail->next;
		el->prev = nullptr;
		tail->next = nullptr;
		delete tail;
		tail = el;
		return res;
	}
}

template<class T>
inline T& deque<T>::pop_front()
{
	if (head == nullptr)
		throw -1;
	if (head->prev == nullptr)
	{
		T res = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		return res;
	}
	else
	{
		T res = head->data;
		Node<T>* el = head->prev;
		el->next = nullptr;
		head->prev = nullptr;
		delete head;
		head = el;
		return res;
	}
}

template<class T>
inline void deque<T>::push_back(T data)
{
	if (tail == nullptr)
	{
		tail = new Node<T>();
		tail->data = data;
		head = tail;
	}
	else
	{
		Node<T>* new_el = new Node<T>();
		new_el->data = data;
		new_el->next = tail;
		tail->prev = new_el;
		tail = new_el;
	}
}

template<class T>
inline void deque<T>::push_front(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>();
		head->data = data;
		tail = head;
	}
	else
	{
		Node<T>* new_el = new Node<T>();
		new_el->data = data;
		new_el->prev = head;
		head->next = new_el;
		head = new_el;
	}
}

template<class T>
inline int deque<T>::size()
{
	if (tail == nullptr)
		return 0;
	else
	{
		int count = 1;
		Node<T>* el = tail;
		while (el->next != nullptr)
		{
			el = el->next;
			count++;
		}
		return count;
	}
}

template<class T>
inline bool deque<T>::isEmpty()
{
	if (tail == nullptr)
		return true;
	return false;
}
