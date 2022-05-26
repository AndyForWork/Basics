#pragma once

template <class T>
struct Node
{
	T val;
	Node<T>* next;
	Node<T>(T value) : val(value), next(nullptr) {};
};

template<class T>
class ListOD
{
private:
	Node<T>* head_;
	Node<T>* tail_;

public:
	ListOD<T>() : head_(nullptr), tail_(nullptr) {};
	ListOD<T>(ListOD<T>&);
	ListOD<T>& operator=(ListOD<T>&);
	bool is_empty();
	void push_back(T);
	void push_front(T);
	T pop_front();
	T pop_back();
	void remove(T);
	T front();
	T back();
	Node<T>* find(T);
	int find_index(T);
	void insert(T, int);

	T& operator[](const int);

	~ListOD<T>();
};

template<class T>
inline ListOD<T>& ListOD<T>::operator=(ListOD<T>& otherList)
{
	if (otherList.is_empty())
	{
		this->~ListOD();
		return *this;
	}
	this->~ListOD();
	Node<T>* el = otherList.head_;
	while (el != nullptr)
	{
		this->push_back(el->val);
		el = el->next;
	}
	return *this;
}

template<class T>
inline bool ListOD<T>::is_empty()
{
	if (head_ == nullptr)
		return true;
	return false;
}

template<class T>
inline void ListOD<T>::push_back(T data)
{
	Node<T>* new_el =  new Node<T>(data);
	if (this->is_empty())
	{
		head_ = new_el;
		tail_ = new_el;
		return;
	}
	tail_->next = new_el;
	tail_ = new_el;
	return;
}

template<class T>
inline void ListOD<T>::push_front(T data)
{
	Node<T>* new_el = new Node<T>(data);
	if (this->is_empty())
	{
		head_ = new_el;
		tail_ = new_el;
		return;
	}
	new_el->next = head_;
	head_ = new_el;
	return;
}

template<class T>
inline T ListOD<T>::pop_front()
{
	if (this->is_empty()) throw - 1;
	T value = head_->val;
	Node<T>* el = head_->next;
	delete head_;
	head_ = el;
	return value;
}

template<class T>
inline T ListOD<T>::pop_back()
{
	if (this->is_empty()) throw -1;	
	if (tail_ == head_)
	{
		return this->pop_front();
	}
	T value = tail_->val;
	Node<T>* el = head_;
	while (el->next != tail_) el = el->next;
	el->next = nullptr;
	delete tail_;
	tail_ = el;
	return value;
}

template<class T>
inline void ListOD<T>::remove(T value)
{
	if (this->is_empty()) return;
	if (head_->val == value)
	{
		this->pop_front();
		return;
	}
	if (tail_->val == value)
	{
		this->pop_back();
		return;
	}
	Node<T>* el = head_;
	Node<T>* el_next = head_->next;
	while (el_next->val != value and el_next != nullptr)
	{
		el = el->next;
		el_next = el_next->next;
	}
	if (el_next == nullptr)
		return ;
	if (el_next->val == value)
	{
		el->next = el_next->next;
		T value_ = el_next->val;
		delete el_next;
	}
	return;
}

template<class T>
inline T ListOD<T>::front()
{
	if (this->is_empty() or head_ == nullptr) throw -1;
	return head_->val;
}

template<class T>
inline T ListOD<T>::back()
{
	if (is_empty() or tail_ == nullptr) throw -1;
	return tail_->val;
}

template<class T>
inline Node<T>* ListOD<T>::find(T value)
{
	if (this->is_empty()) return nullptr;
	Node<T>* el = head_;
	while (el != nullptr and el->val != value) el = el->next;
	if (el == nullptr)
		return nullptr;
	else
		return el;
}

template<class T>
inline int ListOD<T>::find_index(T value)
{
	if (this->is_empty()) return -1;
	Node<T>* el = head_;
	int pos = 0;
	while (el != nullptr and el->val != value) 
	{
		el = el->next;
		pos++;
	}
	if (el == nullptr)
		return -1;
	else
		return pos;
}

template<class T>
inline void ListOD<T>::insert(T data, int index)
{
	Node<T>* new_el = new Node<T>(data);
	if (index == 0)
		return this->push_front(data);
	Node<T>* el = head_;
	Node<T>* el_next = head_->next;
	int pos = 1;
	while (el_next != nullptr and pos != index)
	{
		el_next = el_next->next;
		el = el->next;
		pos++;
	}
	if (el_next != nullptr and pos == index)
	{
		el->next = new_el;
		new_el->next = el_next;
		return;
	}
	else
	{
		if (el_next == nullptr and el == tail_ and index == pos)
		{
			this->push_back(data);
			return;
		}
		return;
	}

}

template<class T>
inline T& ListOD<T>::operator[](const int index)
{
	if (is_empty()) throw -1;
	int pos = 0;
	Node<T>* el = head_;
	while (el != nullptr and pos != index)
	{
		el = el->next;
		pos++;
	}
	if (el != nullptr and pos == index)
		return el->val;
	else
		throw -1;
}

template<class T>
inline ListOD<T>::ListOD( ListOD<T>& otherList)
{
	if (otherList.is_empty())
	{
		this->~ListOD();
		return;
	}
	this->~ListOD();
	Node<T>* el = otherList.head_;
	while (el != nullptr)
	{
		this->push_back(el->val);
		el = el->next;
	}
}

template<class T>
inline ListOD<T>::~ListOD()
{
	Node<T>* el = head_;
	while (head_ != nullptr)
	{
		el = el->next;
		delete head_;
		head_ = el;
	}
}
