#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"
#include "Table.h"
#include "polinom.h"

using namespace std;

class TPostfix
{
	string infix;
	string postfix;
	int count = 0;
	int Compare(char _t1);
	bool CorrectRecord();
	bool IsOperations(char s);
	bool IsOperand(char s);
public:
	TPostfix();
	TPostfix(string str);
	void SetInfix(string _infix);
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	void ToPostfix();
	//double Calculate(double x, double y, double z);
	TPolinom CalcPol(TableLine<TPolinom> &table);
	TPolinom CalcPol(TableSort<TPolinom>& table);
	TPolinom CalcPol(TableList<TPolinom>& table);
	TPolinom CalcPol(HashTable<TPolinom>& table);
	TPolinom CalcPol(Hash_Table<TPolinom>& table);
	//TPolinom CalcPol(AVL_tree<TPolinom>& table);
};

#endif