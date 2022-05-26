#pragma once

#include <iostream>

template<class T, class D>
struct AVLTree
{
	T key;
	D data;
	AVLTree* left;
	AVLTree* right;
	int height;
	AVLTree<T, D>() : left(nullptr), right(nullptr), height(0) {};

	AVLTree<T,D>(T k, D d) : data(d), key( k ), left( nullptr ), right( nullptr ), height( 1 ) {};
	~AVLTree<T,D>() {
		if (left != nullptr)
			delete left;
		if (right != nullptr)
			delete right;
		left = nullptr;
		right = nullptr;
	}
};

template<class T, class D>
unsigned int height(AVLTree<T, D>* root)
{
	if (root == nullptr)
		return 0;
	else
		return root->height;
}

template<class T, class D>
int bfactor(AVLTree<T, D>* root)
{
	return height(root->left) - height(root->right);
}

template<class T, class D>
void upHeight(AVLTree<T, D>* root)
{
	int lh = height(root->left), rh = height(root->right);
	if (lh > rh)
		root->height = lh + 1;
	else
		root->height = rh + 1;
}

template<class T,class D>
AVLTree<T, D>* rightRotation(AVLTree<T, D>* root)
{
	AVLTree<T, D>* tree = root->left;
	root->left = tree->right;
	tree->right = root;
	upHeight(root);
	upHeight(tree);
	return tree;
}

template<class T, class D>
AVLTree<T, D>* leftRotation(AVLTree<T, D>* root)
{
	AVLTree<T, D>* tree = root->right;
	root->right = tree->left;
	tree->left = root;
	upHeight(root);
	upHeight(tree);
	return tree;
}

template<class T, class D>
AVLTree<T, D>* balance(AVLTree<T, D>* root)
{
	if (bfactor(root) == 2)
	{
		if (bfactor(root->left) < 0)
			root->left = leftRotation(root->left);
		return rightRotation(root);
	}
	else if (bfactor(root) == -2)
	{
		if (bfactor(root->right) > 0)
			root->right = rightRotation(root->right);
		return leftRotation(root);
	}
	return root;
}

template<class T, class D>
AVLTree<T, D>* insert(AVLTree<T, D>* root, T key, D data)
{
	if (root == nullptr)
		return new AVLTree<T,D>(key, data);
	if (key < root->key)
		root->left = insert(root->left, key, data);
	else
		root->right = insert(root->right, key, data);
	return balance(root);
}

template<class T, class D>
AVLTree<T, D>* findmin(AVLTree<T, D>* root)
{
	if (root->left == nullptr)
		return root;
	else
		return findmin(root->left);
}

template<class T, class D>
void deleteElem(AVLTree<T, D>* root)
{
	root->right = nullptr;
	root->left = nullptr;
	delete root;
}

template<class T, class D>
AVLTree<T, D>* erasemin(AVLTree<T, D>* root)
{
	if (root->left == nullptr)
	{
		AVLTree<T, D>* dop = root->right;
		deleteElem(root);
		return dop;
	}
	else
		root->left = erasemin(root->left);
	return balance(root);
}

template<class T, class D>
AVLTree<T, D>* erase(AVLTree<T, D>* root, T key)
{
	if (root == nullptr)
		return nullptr;
	if (key < root->key)
		root->left = erase(root->left, key);
	else if (key == root->key)
	{
		AVLTree<T, D>* tree_left = root->left;
		AVLTree<T, D>* tree_right = root->right;
		deleteElem(root);
		if (tree_right == nullptr)
			return tree_left;
		AVLTree<T, D>* tree_min = findmin(tree_right);
		tree_min->right = erasemin(tree_right);
		tree_min->left = tree_left;
		return balance(tree_min);
	}
	else
		root->right = erase(root->right, key);
	return balance(root);
}

template<class T, class D>
std::ostream& operator<<(std::ostream& out, AVLTree<T,D>* root)
{
	if (root->left != nullptr)
		out << root->left;
	if (root != nullptr)
	{
		out << root->data << ' ';
	}
	if (root->right != nullptr)
		out << root->right;
	return out;
}

template<class T, class D>
D& get_by_key(AVLTree<T, D>* root, T key)
{
	if (root == nullptr)
		throw - 1;
	if (key == root->key)
		return root->data;
	if (key < root->key)
		return get_by_key(root->left,key);
	if (key > root->key)
		return get_by_key(root->right, key);
}