#include "polinom.h"
#include "cstdlib"

using namespace std;

TPolinom::TPolinom()
{
	polinom = "";
}

TPolinom::TPolinom(string _polinom)
{
	SetPolinom(_polinom);
}

TPolinom::TPolinom(TPolinom &_TPolinom)
{
	polinom = _TPolinom.polinom;
	monoms = _TPolinom.monoms;
}

TPolinom& TPolinom::operator=(TPolinom &_TPolinom)
{
	if (this == &_TPolinom)
		return *this;
	monoms = _TPolinom.monoms;
	polinom = _TPolinom.polinom;
	return *this;
}

TPolinom TPolinom::operator+(TPolinom &_Polinom)
{
	TPolinom tmp;
	TMonom monom;
	int i = 0, j = 0;
	while ((i < monoms.GetSize()) && (j < _Polinom.monoms.GetSize()))
	{
		if (monoms[i] > _Polinom.monoms[j])
		{
			tmp.monoms.Push_back(monoms[i]);
			i++;
		}
		if (monoms[i] < _Polinom.monoms[j])
		{
			tmp.monoms.Push_back(_Polinom.monoms[j]);
			j++;
		}
		if ((monoms[i].k + _Polinom.monoms[j].k) != 0)
		{
			monom.k = monoms[i].k + _Polinom.monoms[j].k;
			for (int h = 0; h < 3; h++)
				monom.power[h] = monoms[i].power[h];
			tmp.monoms.Push_back(monom);
			i++;
			j++;
		}
		else
		{
			i++;
			j++;
		}
	}
	if (i == monoms.GetSize())
		while (j < _Polinom.monoms.GetSize())
		{
			tmp.monoms.Push_back(_Polinom.monoms[j]);
			j++;
		}
	else
		while (i < _Polinom.monoms.GetSize())
		{
			tmp.monoms.Push_back(monoms[i]);
			i++;
		}
	tmp.strPolinom();
	return tmp;
}

TPolinom TPolinom::operator-(TPolinom &_Polinom)
{
	TPolinom tmp;
	tmp = _Polinom;
	for (int i = 0; i < tmp.monoms.GetSize(); i++)
		tmp.monoms[i].k = -1 * tmp.monoms[i].k;
	tmp = *this + tmp;
	return tmp;
}

TPolinom TPolinom::operator*(TPolinom &_Polinom)
{

	TPolinom emp;
	TMonom t;
	for (int i = 0; i < monoms.GetSize(); i++)
	{
		for (int j = 0; j < _Polinom.monoms.GetSize(); j++)
		{
			t.k = _Polinom.monoms[i].k * monoms[i].k;
			for (int h = 0; h < 3; h++)
				t.power[h] = _Polinom.monoms[i].power[h] + monoms[j].power[h];
		}
	}
	emp.monoms.Push_back(t);
	for (int i = 0; i < emp.monoms.GetSize() - 1; i++)
	{
		for (int j = i + 1; j < emp.monoms.GetSize(); j++)
		{
			if (emp.monoms[i] == emp.monoms[j])
			{
				emp.monoms[i].k += emp.monoms[j].k;
				emp.monoms.DeleteEl(j);
			}
		}
	}
	return emp;
}

TPolinom TPolinom::operator/(TPolinom &_Polinom)
{
	TPolinom div;
	return div;
}

TPolinom TPolinom::Integration(char var)
{
	TPolinom _Polinom=*this;
	for (int i = 0; i < _Polinom.monoms.GetSize(); i++)
	{
		switch (var)
		{
		case 'x':
			_Polinom.monoms[i].power[0]++;
			_Polinom.monoms[i].k = _Polinom.monoms[i].k / _Polinom.monoms[i].power[0];
			break;
		case 'y':
			_Polinom.monoms[i].power[1]++;
			_Polinom.monoms[i].k = _Polinom.monoms[i].k / _Polinom.monoms[i].power[1];
			break;
		case 'z':
			_Polinom.monoms[i].power[2]++;
			_Polinom.monoms[i].k = _Polinom.monoms[i].k / _Polinom.monoms[i].power[2];
			break;
		}
	}
	_Polinom.strPolinom();
	return _Polinom;
}

TPolinom TPolinom::Differentiation(char var)
{
	TPolinom _Polinom=*this;
	for (int i = 0; i < _Polinom.monoms.GetSize(); i++)
	{
		switch (var)
		{
		case 'x':
		{
			_Polinom.monoms[i].k = _Polinom.monoms[i].k * _Polinom.monoms[i].power[0];
			_Polinom.monoms[i].power[0]--;
			
			break;
		}
		case 'y':
		{
			_Polinom.monoms[i].k = _Polinom.monoms[i].k * _Polinom.monoms[i].power[1];
			_Polinom.monoms[i].power[1]--;
			break;
		}
		case 'z':
		{
			_Polinom.monoms[i].k = _Polinom.monoms[i].k * _Polinom.monoms[i].power[2];
			_Polinom.monoms[i].power[2]--;
			break;
		}
		}
	}
	_Polinom.strPolinom();
	return _Polinom;
}

double TPolinom::Calculate(const double &x, const double &y, const double &z)
{
	double res = 0;
	double monom = 1;
	for (int i = 0; i < monoms.GetSize(); i++)
		for (int h = 0; h < 3; h++)
		{
			if (monoms[i].power[h] != 0)
				monom *= pow(z, monoms[i].power[h]);
			if (monoms[i].power[h] != 0)
				monom *= pow(y, (monoms[i].power[h]));
			if (monoms[i].power[h] != 0)
				monom *= pow(x, monoms[i].power[h]);
			res += monom * monoms[i].k;
			monom = 1;
		}
	return res;
}

void TPolinom::SetPolinom(string &_polinom)
{
	TMonom monom;
	int flag = 0;
	int sign = 1;
	int i = 0;
	string str;
	polinom = _polinom;
	while (i < _polinom.length())
	{
		while ((i != _polinom.length()) && _polinom[i] != '-' && _polinom[i] != '+')
		{
			while ((_polinom[i] >= '0'&&_polinom[i] <= '9') || _polinom[i] == '.')
				str += _polinom[i++];
			switch (flag) {
			case 0: monom.k = atof(str.c_str())*sign; str = ""; flag = -1; break;
			case 1: monom.power[0] = atoi(str.c_str())/* * 100*/; str = ""; flag = -1; break;
			case 2: monom.power[1] = atoi(str.c_str()) /** 10*/; str = ""; flag = -1; break;
			case 3: monom.power[2] = atoi(str.c_str());  str = ""; flag = -1; break;
			}
			if (_polinom[i] == 'x')
			{
				i++;
				flag = 1;
				continue;
			}
			if (_polinom[i] == 'y')
			{
				i++;
				flag = 2;
				continue;
			}
			if (_polinom[i] == 'z')
			{
				i++;
				flag = 3;
				continue;
			}
		}
		if (_polinom[i] != '-')
			sign = 1;
		else
		{
			sign = -1;
			if (i == 0)
			{
				i++;
				continue;
			}
		}
		i++;
		if (monoms.GetSize() == 0)
			monoms.Push_back(monom);
		else if (monom.power > monoms[0].power)
			monoms.Push_begin(monom);
		else if (monom.power < monoms[monoms.GetSize() - 1].power)
			monoms.Push_back(monom);
		else
			for (int z = 1; z < monoms.GetSize(); z++)
				if (monoms[z].power < monom.power)
				{
					monoms.Insert(z, monom);
					break;
				}
		flag = 0;
		for (int i = 0; i < 2; i++)
			monom.power[i] = 0;
		monom.k = 0;
	}
}

TList<TMonom> TPolinom::GetPolinom()
{
	return monoms;
}

string TPolinom::GetStrPolinom()
{
	return polinom;
}


ostream & operator<<(std::ostream & out, TPolinom & pol)
{
	out << pol.GetStrPolinom();
	return out;
}

void TPolinom::strPolinom()
{
	polinom = "";
	polinom += to_string(monoms[0].k);
	if (monoms[0].power[0] != 0)
		polinom = polinom + "x" + to_string(monoms[0].power[0]);
	if (monoms[0].power[1] != 0)
		polinom = polinom + "y" + to_string((monoms[0].power[1]));
	if (monoms[0].power[2] != 0)
		polinom = polinom + "z" + to_string(monoms[0].power[2]);
	for (int i = 1; i < monoms.GetSize(); i++)
	{
		if (monoms[i].k > 0)
			polinom += "+";
		polinom += to_string(monoms[i].k);
		if (monoms[i].power[0] != 0)
			polinom = polinom + "x" + to_string(monoms[i].power[0]);
		if (monoms[i].power[1] != 0)
			polinom = polinom + "y" + to_string(monoms[i].power[1]);
		if (monoms[i].power[2] != 0)
			polinom = polinom + "z" + to_string(monoms[i].power[2]);
	}
}