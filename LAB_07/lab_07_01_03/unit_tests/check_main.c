#include "check_head.h"

int main(void)
{
    int failed = 0;
    Suite *filter, *sort;
    SRunner *run_filter, *run_sort;

    filter = filter_array();
    run_filter = srunner_create(filter);

    sort = sort_array();
    run_sort = srunner_create(sort);

    srunner_run_all(run_filter, CK_VERBOSE);
    failed += srunner_ntests_failed(run_filter);
    srunner_free(run_filter);

    srunner_run_all(run_sort, CK_VERBOSE);
    failed += srunner_ntests_failed(run_sort);
    srunner_free(run_sort);

    if (failed)
        return ERROR;
    
    return ERR_OK;
}
