#ifndef __LIST_H__
#define __LIST_H__


using namespace std;

template<class ValType>
struct Node
{
	ValType key;
	Node *pNext;
	Node *pPrev;
	Node *pLast;
	Node() : pNext(nullptr), pPrev(nullptr), pLast(nullptr) {};
};

template <class ValType>
class TList
{
	Node<ValType> *pFirst;
	Node<ValType> *pLast;
	int size;
public:
	TList();
	TList(const ValType &_key);
	~TList();
	TList(const TList &_TList);
	TList& operator=(const TList &_TList);
	ValType& operator[](int pos);
	Node<ValType>* begin();
	bool IsEmpty();
	void Push_back(const ValType &_key);
	void Push_begin(const ValType &_key);
	//void Push_next(Node *tmp, const ValType &_key); //вставить в следующую ячейку относительно переданного звена.
	void Insert(int pos, ValType _key);
	void DeleteEl(int pos);
	void Clear();
	int GetSize();

};

template <class ValType> TList<ValType>::TList()
{
	pFirst = nullptr;
	pLast = nullptr;
	size = 0;
}

template <class ValType> TList<ValType>::TList(const ValType &_key)
{
	pFirst = new Node<ValType>;
	pFirst->key = _key;
	size = 1;
	pLast = pFirst;
}

template <class ValType> TList<ValType>::~TList()
{
	Clear();
}

template <class ValType> TList<ValType>::TList(const TList &_TList) //Конструктор копирования.
{
	size = _TList.size;
	Node<ValType> *tmp = pFirst;
	Node<ValType> *tmp1 = _TList.pFirst;
	if (size != 0)
	{
		tmp = new Node<ValType>;
		tmp->key = tmp1->key;
		while (tmp1->pNext != nullptr)
		{
			tmp->pNext = new Node<ValType>;
			tmp->pNext->pPrev = tmp;
			tmp = tmp->pNext;
			tmp1 = tmp1->pNext;
			tmp->key = tmp1->key;
		}
		tmp->key = tmp1->key;
		pLast = tmp;
	}
	else
	{
		pFirst = nullptr;
		pLast = nullptr;
	}
}

template <class ValType> TList<ValType> &TList<ValType>::operator=(const TList &_TList)//оператор присваивания
{
	if (this == &_TList)
		return *this;
	if (_TList.size == 0)
	{
		Clear();
		return *this;
	}
	if (IsEmpty())
		pFirst = new Node<ValType>;
	Node<ValType> *tmp = pFirst;
	Node<ValType> *tmp1 = _TList.pFirst;
	if (size == _TList.size)
	{
		while (tmp1->pNext != nullptr)
		{
			tmp->key = tmp1->key;
			tmp = tmp->pNext;
			tmp1 = tmp1->pNext;
		}
		tmp->key = tmp1->key;
		pLast = tmp;

	}
	if (size > _TList.size)
	{
		while (tmp1 != nullptr)
		{
			tmp->key = tmp1->key;
			tmp = tmp->pNext;
			tmp1 = tmp1->pNext;
		}
		pLast = tmp;
		while (tmp->pNext != nullptr)
		{
			tmp = tmp->pNext;
			delete tmp->pPrev;
		}
		delete tmp;
	}
	else
	{
		while (tmp->pNext != nullptr)
		{
			tmp->key = tmp1->key;
			tmp = tmp->pNext;
			tmp1 = tmp1->pNext;
		}
		tmp->key = tmp1->key;
		while (tmp1->pNext != nullptr)
		{
			tmp->pNext = new Node<ValType>;
			tmp->pNext->pPrev = tmp;
			tmp = tmp->pNext;
			tmp1 = tmp1->pNext;
			tmp->key = tmp1->key;
		}
		pLast = tmp;
	}
	size = _TList.size;
	return *this;
}

template <class ValType> ValType& TList<ValType>::operator[](int pos)
{
	if (IsEmpty())
		throw("IsEmpty");
	if (pos >= size && pos < 0)
		throw("Index Error");
	Node<ValType> *tmp = pFirst;
	for (int i = 0; i < pos; i++)
		tmp = tmp->pNext;
	return tmp->key;
}

template <class ValType> bool TList<ValType>::IsEmpty()
{
	return pFirst == nullptr;
}

template <class ValType> void TList<ValType>::Push_back(const ValType &_key)
{
	if (IsEmpty())
	{
		pFirst = new Node<ValType>;
		pFirst->key = _key;
		size++;
		pLast = pFirst;
		return;
	}
	else
	{
		pLast->pNext = new Node<ValType>;
		pLast->pNext->pPrev = pLast;
		pLast = pLast->pNext;
		pLast->key = _key;
		size++;
	}
}

template <class ValType> void TList<ValType>::Push_begin(const ValType &_key)
{
	if (IsEmpty())
	{
		pFirst = new Node<ValType>;
		pFirst->key = _key;
		size++;
	}
	pFirst->pPrev = new Node<ValType>;
	pFirst->pPrev->pNext = pFirst;
	pFirst = pFirst->pPrev;
	pFirst->key = _key;
	size++;
}

//template <class ValType> void TList<ValType>::Push_next(Node *tmp, const ValType &_key)
//{
//	if (tmp == nullptr)
//		throw("nullptr Node")
//		if (tmp->pNext == nullptr)
//		{
//			tmp->pNext = new Node<ValType>;
//			tmp->pNext->pPrev = tmp;
//			tmp->pNext->key = _key;
//		}
//		else
//		{
//			Node<ValType> *tmp1 = new Node<ValType>;
//			tmp1->key = _key;
//			tmp->pNext->pPrev = tmp1;
//			tmp->pNext = tmp1;
//		}
//	size++;
//}

template <class ValType> void TList<ValType>::Insert(int pos, ValType _key)
{
	if (pos < 0 || pos >= size)
		throw("Index error");
	if (pos == 0)
	{
		Push_begin(_key);
		return;
	}
	if (pos == size - 1)
	{
		pLast->pNext = new Node<ValType>;
		pLast->pNext->key = pLast->key;
		pLast->key = _key;
		pLast->pNext->pPrev = pLast;
		pLast = pLast->pNext;
		size++;
		return;
	}
	Node<ValType> *tmp = pFirst;
	Node<ValType> *ins = new Node<ValType>;
	for (int i = 0; i < pos; i++)
	{
		tmp = tmp->pNext;
	}
	ins->pNext = tmp;
	ins->pPrev = tmp->pPrev;
	ins->pPrev->pNext = ins;
	tmp->pPrev = ins;
	ins->key = _key;
	size++;
}

template <class ValType> void TList<ValType>::DeleteEl(int pos)
{
	if (IsEmpty())
		throw("IsEmpty");
	if (pos >= size || pos < 0)
		throw("Index Error");
	Node<ValType> *tmp = pFirst;
	if (pos == 0)
	{
		if (pFirst->pNext == nullptr)
		{
			delete pFirst;
			pFirst = nullptr;
		}
		else
		{
			pFirst = pFirst->pNext;
			delete pFirst->pPrev;
			pFirst->pPrev = nullptr;
		}
		size--;
		return;
	}
	if (pos == size - 1)
	{
		tmp = pLast;
		tmp->pPrev->pNext = nullptr;
		pLast = pLast->pPrev;
		delete tmp;
		size--;
		return;
	}
	for (int i = 0; i < pos; i++)
		tmp = tmp->pNext;
	tmp->pNext->pPrev = tmp->pPrev;
	tmp->pPrev->pNext = tmp->pNext;
	delete tmp;
	size--;
}

template <class ValType> void TList<ValType>::Clear()
{
	if (IsEmpty())
		return;
	int tmp = size;
	for (int i = 0; i < tmp; i++)
		DeleteEl(0);
	pFirst = nullptr;
}

template <class ValType> int TList<ValType>::GetSize()
{
	return size;
}

template <class ValType> Node<ValType>* TList<ValType>::begin()
{
	return pFirst;
}

#endif
