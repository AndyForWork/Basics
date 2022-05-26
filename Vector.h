#pragma once

template<typename T>
class vector
{
private:
	T* mass;
	int size;
	int capacity;
	void upCapacity();
public:
	vector(int len);
	vector();
	~vector();
	vector(vector<T>&);
	void push_back(T data);
	T& operator[] (int pos);
	const T& operator[] (int pos) const;
	vector<T>& operator= (const vector<T>& otherVector);
	void clear();
	T pop_back();
	void erase_by_index(int pos);
	void erase(T data);
	void insert(T data, int pos);
	int find(T data);
	int count(T data);
	int len();
	bool isEmpty();


	T* begin();
	const T* begin() const;
	T* end();
	const T* end() const;

};

template<typename T>
void vector<T>::upCapacity()
{
	capacity *= 2;
	T* new_mass = mass;
	mass = new T[capacity];
	for (int i = 0; i < size; i++)
		mass[i] = new_mass[i];
	delete[] new_mass;
}

template<typename T>
vector<T>::vector<T>(int len)
{
	capacity = len;
	this->size = len;
	mass = new T[capacity];
}

template<typename T>
vector<T>::vector<T>()
{
	capacity = 1;
	size = 0;
	mass = new T[1];
}

template<typename T>
vector<T>::~vector()
{
	delete[] mass;
}

template<typename T>
vector<T>::vector(vector<T>& other)
{
	if (this != &other)
	{
		delete[] mass;
		mass = new T[other.size];
		size = other.size;
		capacity = other.capacity;
		for (int i = 0; i < size; i++)
			mass[i] = other.mass[i];
	}
}

template<typename T>
void vector<T>::push_back(T data)
{
	if (size < capacity)
	{
		mass[size] = data;
		size++;
	}
	else
	{
		this->upCapacity();
		mass[size] = data;
		size++;
	}
}

template<typename T>
T& vector<T>::operator[](int pos)
{
	return mass[pos];
}

template<typename T>
const T& vector<T>::operator[](int pos) const
{
	return mass[pos];
}

template<typename T>
vector<T>& vector<T>::operator=(const vector<T>& otherVector)
{
	capacity = otherVector.capacity;
	size = otherVector.size;
	delete[] mass;
	mass = new T[capacity];
	for (int i = 0; i < size; i++)
		mass[i] = otherVector.mass[i];
	return *this;
}

template<typename T>
void vector<T>::clear()
{
	delete[] mass;
	capacity = 1;
	size = 0;
	mass = new T[capacity];
}

template<typename T>
T vector<T>::pop_back()
{
	size--;
	return mass[size];
}

template<typename T>
void vector<T>::erase_by_index(int pos)
{
	for (int i = pos; i < size - 1; i++)
		mass[i] = mass[i + 1];
	size--;
}

template<typename T>
void vector<T>::erase(T data)
{
	int shift = 0;
	for (int i = 0; i < size; i++)
	{
		if (mass[i] == data)
		{
			shift++;
		}
		else
		{
			mass[i - shift] = mass[i];
		}
	}
	size -= shift;
}

template<typename T>
void vector<T>::insert(T data, int pos)
{
	if (size < pos or pos < 0)
		return;
	if (size + 1 == capacity)
	{
		this->upCapacity();
	}
	size++;
	for (int i = size; i > pos; i--)
	{
		mass[i] = mass[i - 1];

	}
	mass[pos] = data;
}

template<typename T>
int vector<T>::find(T data)
{
	for (int i = 0; i < size; i++)
	{
		if (mass[i] == data)
			return i;
	}
	return -1;
}

template<typename T>
int vector<T>::count(T data)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (mass[i] == data)
			count++;
	}
	return count;
}

template<typename T>
int vector<T>::len()
{
	return size;
}

template<typename T>
bool vector<T>::isEmpty()
{
	if (size == 0)
		return true;
	return false;
}

template<typename T>
T* vector<T>::begin()
{
	return &mass[0];
}

template<typename T>
const T* vector<T>::begin() const
{
	return &mass[0];
}

template<typename T>
T* vector<T>::end()
{
	return &mass[size - 1];
}

template<typename T>
const T* vector<T>::end() const
{
	return &mass[size - 1];
}


