#include "check_head.h"
	
// Массив пуст
START_TEST(filter_empty_err)
{

	const int pb[] = { 0 };
	const int *pe = pb;
	int *pb_dst = NULL;
	int *pe_dst = NULL;
	int rc = key(pb, pe, &pb_dst, &pe_dst);
	ck_assert_int_eq(rc, ERR_RANGE_RES);
        free(pb_dst);
}
END_TEST

// Массив заполнен нулями

START_TEST(filter_zerofill_arr)
{
	const int pb[] = { 0, 0, 0, 0, 0, 0 };
	const int *pe = pb + 6;
	int *pb_dst = NULL;
	int *pe_dst = NULL;
        
	int rc = key(pb, pe, &pb_dst, &pe_dst);
	ck_assert_int_eq(rc, ERR_OK);
	ck_assert_mem_eq(pb, pb_dst, 6 * sizeof(int));
	free(pb_dst);
}
END_TEST

// Массив заполнен только натуральными числами

START_TEST(filter_nature_arr)
{
	const int pb[] = { 5, 4, 3, 2, 1 };
	const int *pe = pb + 5;
	int *pb_dst = NULL;
	int *pe_dst = NULL;
        
	int rc = key(pb, pe, &pb_dst, &pe_dst);
	ck_assert_int_eq(rc, ERR_OK);
	ck_assert_mem_eq(pb, pb_dst, 3 * sizeof(int));
	free(pb_dst);
}
END_TEST

// Массив заполнен только отрицательными числами

START_TEST(filter_negative_arr)
{
	const int pb[] = { -1, -2, -3, -4, -5 };
	const int *pe = pb + 5;
	int *pb_dst = NULL;
	int *pe_dst = NULL;

	int rc = key(pb, pe, &pb_dst, &pe_dst);
	ck_assert_int_eq(rc, ERR_OK);
	ck_assert_mem_eq(pb, pb_dst, 3 * sizeof(int));
	free(pb_dst);
}
END_TEST

Suite* filter_array(void)
{
	Suite *s;
	TCase *tc_neg = tcase_create("Negative Case");
	TCase *tc_pos = tcase_create("Positive Case");

	s = suite_create("Filter array");

	tcase_add_test(tc_neg, filter_empty_err);
	suite_add_tcase(s, tc_neg);

	tcase_add_test(tc_pos, filter_nature_arr);
	tcase_add_test(tc_pos, filter_zerofill_arr);
	tcase_add_test(tc_pos, filter_negative_arr);
	suite_add_tcase(s, tc_pos);

	return s;
}
