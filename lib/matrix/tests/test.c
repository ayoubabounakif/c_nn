
#include "matrix.h"
#define ROWS 5
#define COLS 5

t_matrix *g_m;

void assert_eq(int eq, int a)
{
	if (eq != a)
		RAISE(TEST_FAILED_EXCEPTION);
}

void print_sp_line(char *l)
{
    printf("\n++++++++ testing %s +++++++++++++\n",l);
}

void test_init()
{
		g_m = new_matrix(ROWS , COLS);
		assert_eq(g_m != NULL, 1);
		assert_eq(g_m->cols == COLS, 1);
		assert_eq(g_m->rows == ROWS, 1);
    print_sp_line("init passed 1");
}
void test_put()
{
	assert_eq(g_m != NULL, 1);
	assert_eq(g_m->cols == COLS, 1);
	assert_eq(g_m->rows == ROWS, 1);
	for(int i = 0; i < ROWS; i++)
		for(int j = 0; j < COLS; j++)
			g_m->put(g_m, i, j, i * 12.123);
    print_sp_line("put passed 1");
}
void test_get()
{
	double value;

	assert_eq(g_m != NULL, 1);
	assert_eq(g_m->cols == COLS, 1);
	assert_eq(g_m->rows == ROWS, 1);
	for(int i = 0;i <ROWS; i++)
		for(int j = 0; j< COLS; j++)
		{
			value = g_m->get(g_m, i , j);
			assert_eq(value == i * 12.123, 1);
			printf("row: %d , cols: %d , value: %.4f\n", i , j, value);
		}
    print_sp_line("get passed 1");
}



void  test_add()
{
  double value;

  assert_eq(g_m != NULL, 1);
	assert_eq(g_m->cols == COLS, 1);
	assert_eq(g_m->rows == ROWS, 1);
  g_m->add(g_m, 4);
  for(int i = 0;i <ROWS; i++)
		for(int j = 0; j< COLS; j++)
		{
			value = g_m->get(g_m, i , j);
			assert_eq(value == (i * 12.123 + 4), 1);
			printf("row: %d , cols: %d , value: %.4f\n", i , j, value);
		}
    print_sp_line("add passed 1");
}

void main()
{
    print_sp_line("init");
		test_init();
    print_sp_line("put");
		test_put();
    print_sp_line("get");
		test_get();
    print_sp_line("add");
		test_add();
	//	test_for_eache();
}