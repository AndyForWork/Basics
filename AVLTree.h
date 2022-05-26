#pragma once

template<class T>
struct AVLTree
{
	T key;
	AVLTree* left;
	AVLTree* right;
	int height;
	AVLTree<T>(T k) : key(k), left(nullptr), right(nullptr), height(1) {};
	~AVLTree<T>() {
		if (left != nullptr)
			delete left;
		if (right != nullptr)
			delete right;
		left = nullptr;
		right = nullptr;
	}
};
template<class T>
unsigned int height(AVLTree<T>* root)
{
	if (root == nullptr)
		return 0;
	else
		return root->height;
}

template<class T>
int bfactor(AVLTree<T>* root)
{
	return height(root->left) - height(root->right);
}

template<class T>
void upHeight(AVLTree<T>* root)
{
	int lh = height(root->left), rh = height(root->right);
	if (lh > rh)
		root->height = lh + 1;
	else
		root->height = rh + 1;
}

template<class T>
AVLTree<T>* rightRotation(AVLTree<T>* root)
{
	AVLTree<T>* tree = root->left;
	root->left = tree->right;
	tree->right = root;
	upHeight(root);
	upHeight(tree);
	return tree;
}

template<class T>
AVLTree<T>* leftRotation(AVLTree<T>* root)
{
	AVLTree<T>* tree = root->right;
	root->right = tree->left;
	tree->left = root;
	upHeight(root);
	upHeight(tree);
	return tree;
}

template<class T>
AVLTree<T>* balance(AVLTree<T>* root)
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

template<class T>
AVLTree<T>* insert(AVLTree<T>* root, int key)
{
	if (root == nullptr)
		return new AVLTree<T>(key);
	if (key < root->key)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return balance(root);
}

template<class T>
AVLTree<T>* findmin(AVLTree<T>* root)
{
	if (root->left == nullptr)
		return root;
	else
		return findmin(root->left);
}

template<class T>
void deleteElem(AVLTree<T>* root)
{
	root->right = nullptr;
	root->left = nullptr;
	delete root;
}

template<class T>
AVLTree<T>* erasemin(AVLTree<T>* root)
{
	if (root->left == nullptr)
	{
		AVLTree<T>* dop = root->right;
		deleteElem(root);
		return dop;
	}
	else
		root->left = erasemin(root->left);
	return balance(root);
}

template<class T>
AVLTree<T>* erase(AVLTree<T>* root, int key)
{
	if (root == nullptr)
		return nullptr;
	if (key < root->key)
		root->left = erase(root->left, key);
	else if (key == root->key)
	{
		AVLTree<T>* tree_left = root->left;
		AVLTree<T>* tree_right = root->right;
		deleteElem(root);
		if (tree_right == nullptr)
			return tree_left;
		AVLTree<T>* tree_min = findmin(tree_right);
		tree_min->right = erasemin(tree_right);
		tree_min->left = tree_left;
		return balance(tree_min);
	}
	else
		root->right = erase(root->right, key);
	return balance(root);
}

template<class T>
void updateValue(AVLTree<T>* root, int key, int new_key)
{
	if (root->key == key)
		root->key = new_key;
	else if (root->key > key)
		updateValue(root->left, key, new_key);
	else
		updateValue(root->right, key, new_key);
}