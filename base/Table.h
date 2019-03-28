#include <cstring>
#include "polinom.h"
#include "list.h"

const int MaxSize = 100;
using namespace std;

template <class T, typename K> struct TRecord
{
	T data;
	K key;
};

template <class T> class TableLine
{
	TRecord <T, int> data[MaxSize];
	int count = 0;
public:
	TableLine() {};
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
				else {
					data[count].key = _key;
					data[count].data = _data;
					count++;
				}
			}
		}
	}
	void Delete(int _key)
	{
		if (count == 0)
			throw("Table is empty");
		else
		{
			if (count == 1)
			{
				count--;
			}
			for (int i = 0; i < count; i++)
			{
				if (data[i].key == _key)
				{
					data[i].key = data[count].key;
					data[i].data = data[count].data;
				}
			}
			count--;
		}
	}
	T Search(int _key)
	{
		if (count == 0)
			throw("Table is empty");
		else {
			for (int i = 0; i < count; i++)
				if (data[i].key == _key)
					return data[i].data;
			throw("Key isn`t found");
		}
	}
	void Show()
	{
		for (int i = 0; i < MaxSize; i++)
		{
			if (data[i].key != 0)
				cout << data[i].key << "|";
			if (data[i].data != NULL)
				cout << data[i].data << "|" << endl;
			else
			{
				cout << "-" << endl;
			}
		}
	}
};


template <class T> class TableSort
{
	TRecord <T, int> data[MaxSize];
	int count = 0;
public:
	TableSort() {};
	void Sort(TRecord <T, int> *_data, int _count)
	{
		TRecord<T, int> tmp;
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
				else {
					data[count].key = _key;
					data[count].data = _data;
					count++;
				}
			}
			Sort(data, count);
		}
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
					data[i].key = data[count].key;
					data[i].data = data[count].data;
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
	void Show()
	{
		for (int i = 0; i < MaxSize; i++)
		{
			if (data[i].key != 0)
				cout << data[i].key << "|";
			if (data[i].data != NULL)
				cout << data[i].data << "|" << endl;
			else
			{
				cout << "-" << endl;
			}
		}
	}
};

template <class T> class TableList
{
	TList<TRecord<T, int>> data;
public:
	void CreateRing()
	{
		Node<TRecord<T, int>> *first = data.begin();
		if (first == nullptr)
			return;
		while (first->pNext != nullptr)
			first = first->pNext;
		first->pNext = data.begin();
		data.begin()->pPrev = first;
	}
	TableList()
	{
		CreateRing();
	}
	void Insert(T _data, int _key)
	{
		TRecord<T, int> tmp;
		tmp.data = _data;
		tmp.key = _key;
		data.Push_back(tmp);
		CreateRing();
	}
	void Delete(int _key)
	{
		int count = 0;
		Node<TRecord<T, int>> *first = data.begin();
		while (first->pNext != data.begin())
		{
			count++;
			if (first->pNext->key.key == _key)
				data.DeleteEl(count);
			first = first->pNext;
		}
	}
	T Search(int _key)
	{
		Node<TRecord<T, int>> *first = data->begin();
		while (first->pNext != data->begin())
		{
			if (first->key->key == _key)
				return first->key->key;
			first = first->pNext;
		}
		throw("Keys isn`t found");
	}
	void Show()
	{
		Node<TRecord<T, int>> *first = data->begin();
		while (first->pNext != data->begin())
		{
			cout << data[count].key << "|";
			cout << data[count].data << "|" << endl;
			first = first->pNext;
		}
	}
};
//
//template <class T> class TableTree
//{
//	//Cell<T, string>data[MaxSize];
//public:
//	void Insert(T _data, string _key);
//	void Delete(string _key);
//	T Search(string _key);
//};
//
//template <class T> class TableHashList
//{
//	<T, string>data[MaxSize];
//public:
//	void Insert(T _data, string _key);
//	void Delete(string _key);
//	T Search(string _key);
//};
//
//template <class T> class TableHash
//{
//	Cell<T, string>data[MaxSize];
//public:
//	void Insert(T _data, string _key);
//	void Delete(string _key);
//	T Search(string _key);
//};
//
//template<class T>
//inline void TableLine<T>::Insert(T _data, string _key)
//{
//}
