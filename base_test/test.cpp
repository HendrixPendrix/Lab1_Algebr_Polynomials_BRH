#include <gtest.h>
#include "Table.h"
#include "polinom.h"


TEST(HashTable, can_insert_element)
{
	HashTable<int> tab;
	ASSERT_NO_THROW(tab.Insert(1, 1));
}
TEST(HashTable, can_delete_element)
{
	HashTable<int> tab;
	tab.Insert(1, 1);
	ASSERT_NO_THROW(tab.Delete(1));
}
TEST(HashTable, cant_delete_without_right_key)
{
	HashTable<int> tab;
	tab.Insert(1, 1);
	ASSERT_ANY_THROW(tab.Delete(2));
}
TEST(HashTable, can_search_element)
{
	HashTable<int> tab;
	tab.Insert(1, 1);
	ASSERT_NO_THROW(tab.Search(1));
}
TEST(HashTable, can_get_element)
{
	HashTable<int> tab;
	tab.Insert(1, 1);
	EXPECT_EQ(1, tab.Search(1));
}
TEST(HashTable, cant_get_element_without_right_key)
{
	HashTable<int> tab;
	tab.Insert(1, 1);
	ASSERT_ANY_THROW(tab.Search(2));
}

TEST(Hash_Table, can_insert_element)
{
	Hash_Table<int> tab;
	ASSERT_NO_THROW(tab.Insert(1, 1));
}
TEST(Hash_Table, can_delete_element)
{
	Hash_Table<int> tab;
	tab.Insert(1, 1);
	ASSERT_NO_THROW(tab.Delete(1));
}
TEST(Hash_Table, cant_delete_without_right_key)
{
	Hash_Table<int> tab;
	tab.Insert(1, 1);
	ASSERT_ANY_THROW(tab.Delete(2));
}
TEST(Hash_Table, can_search_element)
{
	Hash_Table<int> tab;
	tab.Insert(1, 1);
	ASSERT_NO_THROW(tab.Search(1));
}
TEST(Hash_Table, can_get_element)
{
	Hash_Table<int> tab;
	tab.Insert(1, 1);
	EXPECT_EQ(1, tab.Search(1));
}
TEST(Hash_Table, cant_get_element_without_right_key)
{
	Hash_Table<int> tab;
	tab.Insert(1, 1);
	ASSERT_ANY_THROW(tab.Search(2));
}
TEST(TableLine, can_create_table)
{
	ASSERT_NO_THROW(TableLine <int>  tmp);
}
TEST(TableLine, can_insert_in_table)
{
	TableLine <int> tmp;
	int h = 9;
	ASSERT_NO_THROW(tmp.Insert(h, 1));
}
TEST(Table, can_insert_existing_cell)
{
	TableLine <int> tmp;
	int pol = 9;
	int pol1 = 6;
	tmp.Insert(pol, 1);
	ASSERT_ANY_THROW(tmp.Insert(pol1, 1));
}
TEST(TableLine, can_delete_cell)
{
	TableLine <int> tmp;
	int pol = 9;
	tmp.Insert(pol, 1);
	ASSERT_NO_THROW(tmp.Delete(1));
}
TEST(TableLine, cant_delete_empty_table)
{
	TableLine <int> tmp;
	ASSERT_ANY_THROW(tmp.Delete(1));
}
TEST(TableLine, can_search_cell)
{
	TableLine <int> tmp;
	int pol = 9;
	tmp.Insert(pol, 1);
	ASSERT_NO_THROW(tmp.Search(1));
}
TEST(TableLine, can_search_in_empty_table)
{
	TableLine <int> tmp;
	ASSERT_ANY_THROW(tmp.Search(1));
}
//TableSort
TEST(TableSort, can_create_table)
{
	ASSERT_NO_THROW(TableSort <int> tmp);
}
TEST(TableSort, can_insert_in_table)
{
	TableSort <int> tmp;
	int pol = 9;
	ASSERT_NO_THROW(tmp.Insert(pol, 1));
}
TEST(TableSort, can_insert_existing_cell)
{
	TableSort <int>  tmp;
	int pol = 9;
	int pol1 = 6;
	tmp.Insert(pol, 1);
	ASSERT_ANY_THROW(tmp.Insert(pol1, 1));
}
TEST(TableSort, can_delete_cell)
{
	TableLine <int> tmp;
	int pol = 9;
	tmp.Insert(pol, 1);
	ASSERT_NO_THROW(tmp.Delete(1));
}
TEST(TableSort, cant_delete_empty_table)
{
	TableSort<int> tmp;
	ASSERT_ANY_THROW(tmp.Delete(1));
}
TEST(TableSort, can_search_cell)
{
	TableSort <int> tmp;
	int pol = 9;
	tmp.Insert(pol, 1);
	ASSERT_NO_THROW(tmp.Search(1));
}
TEST(TableSort, can_search_in_empty_table)
{
	TableSort <int> tmp;
	ASSERT_ANY_THROW(tmp.Search(1));
}
//TableList
TEST(TableList, can_create_table)
{
	ASSERT_NO_THROW(TableList <int>  tmp);
}
TEST(TableList, can_insert_in_table)
{
	TableList <int> tmp;
	int h = 9;
	ASSERT_NO_THROW(tmp.Insert(h, 1));
}
TEST(TableList, can_delete_cell)
{
	TableList <int> tmp;
	int pol = 9;
	tmp.Insert(pol, 1);
	ASSERT_NO_THROW(tmp.Delete(1));
}

//TEST(TPolinom, can_create_polinom)
//{
//	ASSERT_NO_THROW(TPolinom p);
//}
//TEST(TPolinom, can_set_polinom)
//{
//	ASSERT_NO_THROW(TPolinom p("x^2*y^1*z^4+x^1*y^3*z^1"));
//}
//TEST(TPolinom, can_create_copy)
//{
//	TPolinom p("x2*y1*z4+x1*y3*z1");
//	TPolinom k(p);
//	EXPECT_EQ(p.GetPolinom(), k.GetPolinom());
//}
////TEST(TPolinom, can_equate)
////{
////	TPolinom p("x2*y1*z4+x1*y3*z1");
////	TPolinom k("x1*y1*z2+x4*y2*z1");
////	ASSERT_NO_THROW(k = p);
////}
//TEST(TPolinom, can_addition)
//{
//	TPolinom p("x2*y1*z4+x1*y3*z1");
//	TPolinom k(p);
//	ASSERT_NO_THROW(p + k);
//}
//TEST(TPolinom, can_subtract)
//{
//	TPolinom p("x2*y1*z4+x1*y3*z1");
//	TPolinom k("x2*y1*z4");
//	ASSERT_NO_THROW(p - k);
//}
//TEST(TPolinom, can_multiply)
//{
//	TPolinom p("x2*y1*z4+x1*y3*z1");
//	TPolinom k("x2*y1*z4");
//	ASSERT_NO_THROW(p*k);
//}
//TEST(TPolinom, can_integration)
//{
//	TPolinom p("x2*y1*z4+x1*y3*z1");
//	ASSERT_NO_THROW(p.Integration(p, 'x'));
//}
//TEST(TPolinom, can_differtiation)
//{
//	TPolinom p("x2*y1*z4+x1*y3*z1");
//	ASSERT_NO_THROW(p.Differentiation(p, 'x'));
//}
//TEST(TPolinom, can_calculate)
//{
//	TPolinom p("x2*y1*z4+x1*y3*z1");
//	ASSERT_NO_THROW(p.Calculate(1, 2, 3));
//}