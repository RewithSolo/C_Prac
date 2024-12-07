#include "check_head.h"

// Массив состоит из одинаковых элементов
START_TEST(sort_nonuniqe_arr)
{
    int a[] = { 0, 0, 0, 0, 0, 0 };
    int b[] = { 0, 0, 0, 0, 0, 0 };

    int *pb_dst = a;
    int *pe_dst = pb_dst + 6;
    
    mysort(pb_dst, pe_dst - pb_dst, sizeof(int), cmp);
    
    ck_assert_mem_eq(b, pb_dst, 6 * sizeof(int));
    
}
END_TEST

// Массив состоит только из натуральных чисел
START_TEST(sort_nature_arr)
{
    int a[] = { 5, 4, 3, 2, 1 };
    int b[] = { 1, 2, 3, 4, 5 };

    int *pb_dst = a;
    int *pe_dst = pb_dst + 5;
    mysort(pb_dst, pe_dst - pb_dst, sizeof(int), cmp);
    
    ck_assert_mem_eq(b, pb_dst, 5 * sizeof(int));
    
}
END_TEST

// Массив состоит только из отрицательных чисел
START_TEST(sort_negative_arr)
{
    int a[] = { -1, -2, -3, -4, -5 };
    int b[] = { -5, -4, -3, -2, -1 };

    int *pb_dst = a;
    int *pe_dst = pb_dst + 5;
    mysort(pb_dst, pe_dst - pb_dst, sizeof(int), cmp);

    ck_assert_mem_eq(b, pb_dst, 5 * sizeof(int));
    
}
END_TEST

Suite* sort_array(void)
{
    Suite *s;
    TCase *tc_pos = tcase_create("Positive Case");

    s = suite_create("Sorting array");

    tcase_add_test(tc_pos, sort_nonuniqe_arr);
    tcase_add_test(tc_pos, sort_nature_arr);
    tcase_add_test(tc_pos, sort_negative_arr);
    suite_add_tcase(s, tc_pos);

    return s;
}
