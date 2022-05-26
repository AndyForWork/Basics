#pragma once
#include <iostream>

using namespace std;

template<class T>
struct Node
{
	T x;
	int y, size;
	Node<T>* left;
	Node<T>* right;
	Node(T x) :x(x)
	{
		if (RAND_MAX == 32767)
			y = (rand() << 15) + rand();
		else
			y = rand();
		left = right = nullptr;
		size = 1;
	}
};

template<class T>
void size_update(Node<T>* root)
{
	root->size = 1;
	if (root->left != nullptr)
		root->size += root->left->size;
	if (root->right != nullptr)
		root->size += root->right->size;
}

template<class T>
bool exist(Node<T>* root, T x)
{
	if (root == nullptr)
		return false;
	if (root->x == x)
		return true;
	if (x < root->x)
		return exist(root->left, x);
	else
		return exist(root->right, x);
}

template<class T>
pair<Node<T>*, Node<T>*> split(Node<T>* root, int x)
{
	if (root == nullptr)
		return { nullptr, nullptr };
	if (root->x <= x)
	{
		auto res = split(root->right, x);
		root->right = res.first;
		size_update(root);
		return { root, res.second };
	}
	else
	{
		auto res = split(root->left, x);
		root->left = res.second;
		size_update(root);
		return { res.first, root };
	}
}

template<class T>
Node<T>* merge(Node<T>* root1, Node<T>* root2)
{
	if (root1 == nullptr) return root2;
	if (root2 == nullptr) return root1;
	if (root1->y < root2->y)
	{
		root1->right = merge(root1->right, root2);
		size_update(root1);
		return root1;
	}
	else
	{
		root2->left = merge(root1, root2->left);
		size_update(root2);
		return root2;
	}
}

template<class T>
Node<T>* insert(Node<T>* root, int x)
{
	if (exist(root, x)) return root;
	Node<T>* new_el = new Node<T>(x);
	auto res = split(root, x);
	return merge(merge(res.first, new_el), res.second);
}

template<class T>
Node<T>* erase(Node<T>* root, T x)
{
	if (!exist(root, x)) return root;
	auto res1 = split(root, x);
	auto res2 = split(res1.first, x - 1);
	delete res2.second;
	return merge(res2.first, res1.second);
}
template<typename T>
ostream& operator<<(ostream& out, Node<T>* root)
{
	if (root->left != nullptr)
		out << root->left;
	if (root != nullptr)
	{
		out << root->x<<' ';
	}
	if (root->right != nullptr)
		out << root->right;
	return out;
}

template<class T>
int depth(Node<T>* root)
{
	if (root == nullptr)
		return 0;
	return 1 + max(depth(root->left), depth(root->right));
}

template<typename T>
int height(Node<T>* root)
{
	if (root == nullptr)
		return 0;
	else
		return 1 + height(root->left) + height(root->right);
}

template<typename T>
int size(Node<T>* root)
{
	if (root == nullptr)
		return 0;
	else
		return root->size;
}

template<class T>
int get_by_index(Node<T>* root, int index)//нужно доделать и сделать поиск элемента по индексу
{
	if (root == nullptr)
		throw - 1;
	if (index == height(root->left))
		return root->x;
	if (index < height(root->left))
		return get_by_index(root->left, index);
	if (index > height(root->left))
		return get_by_index(root->right, index - height(root->left) - 1);
}