#pragma once

template<class T>
struct Node
{
	T val;
	Node<T>* prev;
	Node<T>* next;
	Node(T value) : val(value), next(nullptr), prev(nullptr) {};
};

template<class T>
class ListTD
{
private:
	Node<T>* head_;
	Node<T>* tail_;

public:
	ListTD<T>() : head_(nullptr), tail_(nullptr) {};
	ListTD<T>(ListTD<T>&);
	ListTD<T>& operator=(ListTD<T>&);
	bool is_empty();
	void push_front(T);
	void push_back(T);
	T pop_front();
	T pop_back();
	T front();
	T back();
	void remove(T);
	Node<T>* find(T);
	int find_index(T);
	void insert(T, int);

	T& operator[](const int);


	~ListTD()
	{
		Node<T>* el = head_;
		while (head_ != nullptr)
		{
			el = el->next;
			head_->prev = nullptr;
			head_->next = nullptr;
			delete head_;
			head_= el;
		}
	};

};

template<class T>
inline ListTD<T>& ListTD<T>::operator=(ListTD<T>& otherList)
{
	if (otherList.is_empty())
	{
		this->~ListTD();
		return *this;
	}
	this->~ListTD();
	Node<T>* el = otherList.head_;
	while (el != nullptr)
	{
		this->push_back(el->val);
		el = el->next;
	}
	return *this;
}

template<class T>
inline bool ListTD<T>::is_empty()
{
	if (head_ == nullptr)
		return true;
	return false;
}

template<class T>
inline void ListTD<T>::push_front(T data)
{
	Node<T>* new_el = new Node<T>(data);
	if (this->is_empty())
	{
		head_ = new_el;
		tail_ = new_el;
		return;
	}
	head_->prev = new_el;
	new_el->next = head_;
	head_ = new_el;
	return;

}

template<class T>
inline void ListTD<T>::push_back(T data)
{
	Node<T>* new_el = new Node<T>(data);
	if (this->is_empty())
	{
		head_ = new_el;
		tail_ = new_el;
		return;
	}
	tail_->next = new_el;
	new_el->prev = tail_;
	tail_ = new_el;
	return;

}

template<class T>
inline T ListTD<T>::pop_front()
{
	if (this->is_empty()) throw -1;
	if (tail_ == head_)
	{
		T value = head_->val;
		delete head_;
		head_ = nullptr;
		tail_ = nullptr;
		return value;
	}
	Node<T>* el = head_->next;
	T value = head_->val;
	el->prev = nullptr;
	head_->next = nullptr;
	delete head_;
	head_ = el;
	return value;
}

template<class T>
inline T ListTD<T>::pop_back()
{
	if (this->is_empty()) throw -1;
	if (tail_ == head_)
	{
		T value = head_->val;
		delete head_;
		head_ = nullptr;
		tail_ = nullptr;
		return value;
	}
	Node<T>* el = tail_->prev;
	el->next = nullptr;
	T value = tail_->val;
	tail_->prev = nullptr;
	delete tail_;
	tail_ = el;
	return value;
}

template<class T>
T ListTD<T>::front()
{
	if (head_ == nullptr) throw -1;
	return head_->val;
}

template<class T>
inline T ListTD<T>::back()
{
	if (tail_ == nullptr) throw -1;
	return tail_->val;
}

template<class T>
inline void ListTD<T>::remove(T data)
{
	if (this->is_empty()) return;
	if (head_->val == data)
	{
		this->pop_front();
		return;
	}
	if (tail_->val == data)
	{
		this->pop_back();
		return;
	}
	Node<T>* el = head_;
	while (el != nullptr and el->val != data)
		el = el->next;
	if (el == nullptr)
		return;
	Node<T>* neigbour = el->prev;
	neigbour->next = el->next;
	neigbour = el->next;
	neigbour->prev = el->prev;
	el->prev = nullptr;
	el->next = nullptr;
	delete el;
	return;
}


template<class T>
Node<T>* ListTD<T>::find(T data)
{
	if (this->is_empty()) return nullptr;
	Node<T>* el = head_;
	while (el != nullptr and el->val != data)
		el = el->next;
	if (el != nullptr and el->val == data)
		return el;
	else
		return nullptr;
}

template<class T>
inline int ListTD<T>::find_index(T data)
{
	if (this->is_empty()) return -1;
	int pos = 0;
	Node<T>* el = head_;
	while (el != nullptr and el->val != data)
	{
		el = el->next;
		pos++;
	}
	if (el != nullptr and el->val == data)
		return pos;
	else
		return -1;
}

template<class T>
inline void ListTD<T>::insert(T data, int index)
{
	Node<T>* new_el = new Node<T>(data);
	if (index == 0)
		return this->push_front(new_el);
	Node<T>* el = head_;
	int pos = 0;
	while (el != nullptr and pos != index)
	{
		pos++;
		el = el->next;
	}
	if (el != nullptr and index == pos)
	{
		new_el->next = el;
		new_el->prev = el->prev;
		Node<T>* dop = el->prev;
		dop->next = new_el;
		el->prev = new_el;
	}
	else
	{
		if (index == pos)
			return this->push_back(new_el);
		return;
	}
}

template<class T>
inline T& ListTD<T>::operator[](const int index)
{
	if (this->is_empty()) throw -1;
	int pos = 0;
	Node<T>* el = head_;
	while (el != nullptr and pos != index)
	{
		el = el->next;
		pos++;
	}
	if (el != nullptr and pos == index)
		return el->val;
	throw -1;
}

template<class T>
inline ListTD<T>::ListTD(ListTD<T>& otherList)
{
	if (otherList.is_empty())
	{
		this->~ListTD();
		return;
	}
	this->~ListTD();
	Node<T>* el = otherList.head_;
	while (el != nullptr)
	{
		this->push_back(el->val);
		el = el->next;
	}
}
