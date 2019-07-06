#include "window.h"
#include "Table.h"
#include <Windows.h>

using namespace std;



void wstr()
{
  for(int i=0;i<1620;i++)
		cout<<"-";
}

void ShowTableLine(int count, TableLine &table)
{
	gotoxy(349,0);
	cout<<"key";
	gotoxy(1517,0);
	cout<<"polinom";
	gotoxy(349,1);
	wstr();
	
	
}

void ShowTableSort(int count)
{
}

void ShowTableList(int count)
{
}

void ShowTableTree(int count)
{
}

void ShowTableHashL(int count)
{
}

void ChangeTable()
{
}

void CreateMenu()
{
}

void Clear()
{
}
