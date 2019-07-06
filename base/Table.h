#ifndef __TABLE_H__
#define __TABLE_H__

#include <string>
#include <vector>
#include "list.h"
#include "stdlib.h"
#include "stdio.h"

using namespace std;

const int MaxSize = 100;

template <class T> struct TRecord
{
	T data;
	int key;
	TRecord() {};
	TRecord(T _data, int _key) : data(_data), key(_key) {};
	TRecord& operator=(TRecord<T> &tmp)
	{
		data = tmp.data;
		key = tmp.key;
		return *this;
	}
};

template <class T> class TableLine
{
	TRecord <T> data[MaxSize];
	int count = 0;
public:
	void Insert(T _data, int _key)
	{
		if (count == 0)
		{
			data[count].key = _key;
			data[count].data = _data;
			count++;
		}
		else {
			for (int i = 0; i < count; i++)
			{
				if (_key == data[i].key)
					throw (string("Key is set"));
			}

			data[count].key = _key;
			data[count].data = _data;
			count++;

		}
	}
	void Delete(int _key)
	{
		bool flag = true;
		if (count == 0)
			throw(string("Table is empty"));
		else
		{
			if (count == 1)
			{
				count--;
				return;
			}
			for (int i = 0; i < count; i++)
			{
				if (data[i].key == _key)
				{
					data[i].key = data[count - 1].key;
					data[i].data = data[count - 1].data;
					flag = false;
				}
			}
			if (flag)
				throw(string("Key is not found!"));
			count--;
		}
	}
	T Search(int _key)
	{
		if (count == 0)
			throw(string("Table is empty"));
		else {
			for (int i = 0; i < count; i++)
				if (data[i].key == _key)
					return data[i].data;
			throw(string("Key isn`t found"));
		}
	}
	void PrintTable()
	{
		for (int i = 0; i < count; i++)
			cout << data[i].key << "|" << data[i].data << endl;
	}
};

template <class T> class TableSort
{
	TRecord<T>data[MaxSize];
	int count = 0;
public:
	void Sort(TRecord <T> *_data, int _count)
	{
		TRecord<T> tmp;
		int ind;
		for (int i = 1; i < _count; i++)
		{
			tmp = _data[i];
			ind = i - 1;
			while (ind >= 0 && _data[ind].key > tmp.key)
			{
				_data[ind + 1] = _data[ind];
				_data[ind] = tmp;
				ind--;
			}
		}
	}
	void Insert(T _data, int _key)
	{
		if (count == 0)
		{
			data[count].key = _key;
			data[count].data = _data;
			count++;
		}
		else {
			for (int i = 0; i < count; i++)
			{
				if (_key == data[i].key)
					throw ("Key is set");
			}
			data[count].key = _key;
			data[count].data = _data;
			count++;
		}
		Sort(data, count);
	}
	void Delete(int _key)
	{
		if (count == 0)
			throw("Table is empty");
		else
		{
			for (int i = 0; i < count; i++)
			{
				if (data[i].key == _key)
				{
					data[i].key = data[count - 1].key;
					data[i].data = data[count - 1].data;
				}
			}
			count--;
			Sort(data, count);
		}
	}
	T Search(int _key)
	{
		if (count == 0)
			throw("Table is empty");
		else
		{
			bool flag = false;
			int l = 0;
			int r = count;
			int mid;
			while ((l <= r) && (flag != true))
			{
				mid = (l + r) / 2;
				if (data[mid].key == _key)
					flag = true;
				if (data[mid].key > _key)
					r = mid - 1;
				else l = mid + 1;
			}
			if (flag == false)
				throw("Key isn`t found");
			return data[mid].data;
		}
	}
	void PrintTable()
	{
		for (int i = 0; i < count; i++)
			cout << data[i].key << "|" << data[i].data << endl;
	}
};

template <class T> class TableList
{
	TList<TRecord<T>> data;
public:
	void Insert(T _data, int _key)
	{
		TRecord<T> tmp;
		tmp.data = _data;
		tmp.key = _key;
		data.Push_back(tmp);
	}
	void Delete(int _key)
	{
		int count = 0;
		Node<TRecord<T>> *first = data.begin();
		while (first != nullptr)
		{
			if (first->key.key == _key)
			{
				data.DeleteEl(count);
				return;
			}
			count++;
			first = first->pNext;
		}
	}
	T Search(int _key)
	{
		Node<TRecord<T>> *first = data.begin();
		while (first != nullptr)
		{
			if (first->key.key == _key)
				return first->key.data;
			first = first->pNext;
		}
		throw("Keys isn`t found");
	}
	void Show()
	{
		for (int i = 0; i < data.GetSize(); i++)
		{
			cout << data[i].key << "|";
			cout << data[i].data << endl;
		}
	}
};

template <class T> struct node
{
	int key;
	int height;
	T data;
	node<T> *left;
	node<T> *right;
	node() : key(0), height(0), left(nullptr), right(nullptr) {};
};

template <class T> class AVL_tree
{
private:
	node<T> *root;

	void makeEmpty(node<T>* t)
	{
		if (t == nullptr)
			return;
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}

	node<T>* insert(T _data, int x, node<T>* t)
	{
		if (t == nullptr)
		{
			t = new node<T>;
			t->key = x;
			t->data = _data;
			t->height = 1;
			//t->left = t->right = nullptr;
		}
		else
			if (x < t->key)
			{
				t->left = insert(_data, x, t->left);
				t->height++;
				if (height(t->left) - height(t->right) == 2)
				{
					if (x < t->left->key)
						t = singleRightRotate(t);
					else
						t = doubleRightRotate(t);
				}
				t->data = _data;
			}
			else
				if (x > t->key)
				{
					t->right = insert(_data, x, t->right);
					t->height++;
					if (height(t->right) - height(t->left) == 2)
					{
						if (x > t->right->key)
							t = singleLeftRotate(t);
						else
							t = doubleLeftRotate(t);
					}
					t->data = _data;
				}

		if (height(t->left) > height(t->right))
			t->height = height(t->left) + 1;
		else
			t->height = height(t->right) + 1;
		
		return t;
	}

	node<T>* singleRightRotate(node<T>*t)
	{
		node<T>* u = t->left;
		t->left = u->right;
		u->right = t;
		t->height = (height(t->left) > height(t->right) ? height(t->left) : height(t->right)) + 1;
		//t->height = max(height(t->left), height(t->right)) + 1;
		u->height = (height(u->left) > t->height ? height(u->left) : t->height) + 1;
		//u->height = max(height(u->left), t->height) + 1;
		return u;
	}

	node<T>* singleLeftRotate(node<T>*t)
	{
		node<T>* u = t->right;
		t->right = u->left;
		u->left = t;
		if (height(t->left) > height(t->right))
			t->height = height(t->left) + 1;
		else
			t->height = height(t->right) + 1;
		u->height = (height(t->right) > t->height ? height(t->right) : t->height) + 1;
		//u->height = max(height(t->right), t->height) + 1;
		return u;
	}

	node<T>* doubleLeftRotate(node<T>* t)
	{
		t->right = singleRightRotate(t->right);
		return singleLeftRotate(t);
	}

	node<T>* doubleRightRotate(node<T>* t)
	{
		t->left = singleLeftRotate(t->left);
		return singleRightRotate(t);
	}

	node<T>* findMin(node<T>* t)
	{
		if (t == nullptr)
			return nullptr;
		else if (t->left == nullptr)
			return t;
		else
			return findMin(t->left);
	}

	node<T>* findMax(node<T>* t)
	{
		if (t == nullptr)
			return nullptr;
		else if (t->right == nullptr)
			return t;
		else
			return findMax(t->right);
	}

	node<T>* remove(int x, node<T>* t)
	{
		node<T>* temp;

		if (t == nullptr)
			return nullptr;
		// Element not found

		else if (x < t->key)
			t->left = remove(x, t->left);
		else if (x > t->key)
			t->right = remove(x, t->right);
		// Searching for element

		// Element found
		// With 2 children
		else if (t->left && t->right)
		{
			temp = findMin(t->right);
			t->key = temp->key;
			t->right = remove(t->key, t->right);
		}
		// With one or zero child
		else
		{
			temp = t;
			if (t->left == nullptr)
				t = t->right;
			else if (t->right == nullptr)
				t = t->left;
			delete temp;
		}
		if (t == nullptr)
			return t;
		if (height(t->left) > height(t->right))
			t->height = height(t->left) + 1;
		else
			t->height = height(t->right)+1;
		

		// If node is unbalanced
		// If left node is deleted, right case
		if (height(t->left) - height(t->right) == 2)
		{
			// right right case
			if (height(t->left->left) - height(t->left->right) == 1)
				return singleLeftRotate(t);
			// right left case
			else
				return doubleLeftRotate(t);
		}
		// If right node is deleted, left case
		else if (height(t->right) - height(t->left) == 2)
		{
			// left left case
			if (height(t->right->right) - height(t->right->left) == 1)
				return singleRightRotate(t);
			// left right case
			else
				return doubleRightRotate(t);
		}
		return t;
	}

	int height(node<T>* t)
	{
		if (t == nullptr)
			return -1;
		else
			return t->height;
	}

	int getBalance(node<T>* t)
	{
		if (t == nullptr)
			return 0;
		else
			return height(t->left) - height(t->right);
	}

	void inorder(node<T>* t)
	{
		if (t == nullptr)
			return;
		inorder(t->left);
		cout << t->key << "|" << t->data << "" << endl;
		inorder(t->right);
	}

public:
	AVL_tree()
	{
		root = NULL;
	}

	void Insert(T data, int x)
	{
		root = insert(data,x,root);
	}

	void Delete(int x)
	{
		root = remove(x, root);
	}

	void Print()
	{
		inorder(root);
		cout << endl;
	}
	
	T SearchByKey(int seek_key)
	{
		node<T> *cur_node = root;
		while (cur_node != nullptr && cur_node->key != seek_key)
		{
			if (seek_key < cur_node->key)
				cur_node = cur_node->left;
			else
				cur_node = cur_node->right;

		}
		if (cur_node->key != seek_key) //проверка на несущестование
		{
			throw "Not exist";
		}
		return cur_node->data;
	}
};

inline int Hash(int key)
{
	return key % MaxSize;
}

template <class T> class HashTable
{
private:
	TList<TRecord<T>> table[100];
public:
	void Delete(int key_)
	{
		int tmp = Hash(key_);
		for (int i = 0; i < table[tmp].GetSize(); i++)
		{
			if (table[tmp][i].key == key_)
			{
				table[tmp].DeleteEl(i);
				return;
			}
		}
		throw "Key is not found";
	}
	void Insert(T elem, int key_)
	{
		int tmp = Hash(key_);
		TRecord<T> El(elem, key_);
		table[tmp].Push_back(El);
	}
	T Search(int key_)
	{
		int tmp = Hash(key_);
		for (int i = 0; i < table[tmp].GetSize(); i++)
		{
			if (table[tmp][i].key == key_)
				return table[tmp][i].data;
		}
		throw "Key is not found";
	}
	void Show()
	{
		for (int i = 0; i < MaxSize; i++)
		{
			for (int j = 0; j < table[i].GetSize(); j++)
			{
				cout << table[i][j].key << "|" << table[i][j].data << endl;
			}
		}
	}
};
template <class T> struct tab
{
	int key;
	T rec;
	bool flag = false;
	tab() {};
};
template <class T> class Hash_Table
{
private:
	tab<T> table[MaxSize];
public:
	Hash_Table() {};
	void Delete(int key_)
	{
		int tmp = Hash(key_);
		if (table[tmp].key == key_ && table[tmp].flag)
		{
			table[tmp].flag = false;
			return;
		}
		else
		{
			while (table[tmp].key != key_ && table[tmp].flag)
			{
				tmp++;
				if (tmp == (MaxSize + 1))
					throw "Key is not found";
			}
			if (table[tmp].key == key_)
			{
				table[tmp].flag = false;
				return;
			}
		}
		throw "Key is not found";
	}
	void Insert(T elem, int key_)
	{
		int tmp = Hash(key_);
		while (table[tmp].flag)
		{
			tmp++;
		}
		if (!table[tmp].flag)
		{
			table[tmp].rec = elem;
			table[tmp].key = key_;
			table[tmp].flag = true;
		}
	}
	T Search(int key_)
	{
		int tmp = Hash(key_);
		while (table[tmp].flag)
		{
			if (table[tmp].key == key_)
				return table[tmp].rec;
			tmp++;
			if (tmp == (MaxSize + 1))
				throw "Key is not found";
		}
		if (!table[tmp].flag)
			throw "Key is not found";
	}
	void Show()
	{
		for (int i = 0; i < MaxSize; i++)
		{
			if (table[i].flag)
				cout << table[i].key << "|" << table[i].rec << "|" << endl;
		}
	}
};

#endif