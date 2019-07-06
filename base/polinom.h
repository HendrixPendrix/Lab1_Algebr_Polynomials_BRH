#ifndef __TPOLINOM_H__
#define __TPOLINOM_H__

#include<iostream>
#include "list.h"
#include <string>
#include <math.h>

using namespace std;

struct TMonom
{
	double k;
	int power[3];
	TMonom()
	{
		for (int i = 0; i < 3; i++)
			power[i] = 0;
		k = 1;
	}
	TMonom(TMonom &monom)
	{
		for (int i = 0; i < 3; i++)
			power[i] =monom.power[i];
		k = monom.k;
	}
	TMonom& operator =(TMonom &_mon)
	{
		k = _mon.k;
		for (int i = 0; i < 3; i++)
			power[i] = _mon.power[i];
		return *this;
	}
	bool operator>(TMonom &_mon)
	{
		if (power[0] > _mon.power[0])
			return true;
		else if (power[0] == _mon.power[0])
			if (power[1] > _mon.power[1])
				return true;
			else if (power[1] == _mon.power[1])
				if (power[2] > _mon.power[2])
					return true;
		return false;
	}
	bool operator <(TMonom &_mon)
	{
		if (power[0] < _mon.power[0])
			return true;
		else if (power[0] == _mon.power[0])
			if (power[1] < _mon.power[1])
				return true;
			else if (power[1] == _mon.power[1])
				if (power[2] < _mon.power[2])
					return true;
		return false;
	}
	bool operator==(TMonom &_mon)
	{
		if ((power[0] == _mon.power[0]) && (power[1] == _mon.power[1]) && (power[2] == _mon.power[2])) 
			return true;
		return false;
	}
	TMonom operator-(TMonom &_mon)
	{
		TMonom tmp=*this;
		for (int i = 0; i < 3; i++)
			tmp.power[i] = power[i] - _mon.power[i];
		return tmp;
	} //for power
	TMonom operator+(TMonom &_mon)
	{
		TMonom tmp = *this;
		for (int i = 0; i < 3; i++)
			tmp.power[i] = power[i] + _mon.power[i];
		return tmp;
	} // for power
};


class TPolinom
{
	TList<TMonom> monoms;
	string polinom;
public:
	friend ostream& operator << (std::ostream &out, TPolinom &pol);
	TPolinom();
	TPolinom(string _polinom);
	TPolinom(TPolinom &_TPolinom);
	TPolinom& operator=(TPolinom &_TPolinom);
	bool operator==(TPolinom &_TPolinom);
	TPolinom operator+(TPolinom &_TPolinom);
	TPolinom operator-(TPolinom &_TPolinom);
	TPolinom operator*(TPolinom &_TPolinom);
	TPolinom operator/(TPolinom &_TPolinom);
	TPolinom Integration(char var);
	TPolinom Differentiation(char var);
	void SetPolinom(string &_polinom);
	TList<TMonom> GetPolinom();
	string GetStrPolinom();
	double Calculate(const double &x, const double &y, const double &z);
	void strPolinom();
};

#endif 