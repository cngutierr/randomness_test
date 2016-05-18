#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(UtilTest)
{
    RUN_TEST_CASE(UtilTest, test_bit_sum_zero);
    RUN_TEST_CASE(UtilTest, test_bit_sum_neg16);
    RUN_TEST_CASE(UtilTest, test_bit_sum_one);
    RUN_TEST_CASE(UtilTest, test_bit_count_0);
    RUN_TEST_CASE(UtilTest, test_bit_count_1);
    RUN_TEST_CASE(UtilTest, test_bit_count_2);
    RUN_TEST_CASE(UtilTest, test_bit_count_4);
    RUN_TEST_CASE(UtilTest, test_bit_count_8);
    RUN_TEST_CASE(UtilTest, test_run_count_8);
    RUN_TEST_CASE(UtilTest, test_longest_one_run_0);
    RUN_TEST_CASE(UtilTest, test_longest_one_run_1);
    RUN_TEST_CASE(UtilTest, test_longest_one_run_2);
    RUN_TEST_CASE(UtilTest, test_longest_one_run_4);
    RUN_TEST_CASE(UtilTest, test_longest_one_run_8);
    RUN_TEST_CASE(UtilTest, test_longest_one_run_16);
}
