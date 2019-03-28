#include <gtest.h>
#include <Table.h>
//#include <polinom.h>

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