#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(RandTest)
{
    RUN_TEST_CASE(RandTest, test_mono_freq_rand1);
    RUN_TEST_CASE(RandTest, test_mono_freq_rand2);
    
    RUN_TEST_CASE(RandTest, test_block_freq_rand1);
    RUN_TEST_CASE(RandTest, test_block_freq_rand2);
    RUN_TEST_CASE(RandTest, test_block_freq_not1);
    
    RUN_TEST_CASE(RandTest, test_runs_rand1);
    RUN_TEST_CASE(RandTest, test_runs_rand2);
    RUN_TEST_CASE(RandTest, test_runs_not1);
    
    RUN_TEST_CASE(RandTest, test_runs_one_block_rand1);
    RUN_TEST_CASE(RandTest, test_runs_one_block_rand2);
    RUN_TEST_CASE(RandTest, test_runs_one_block_not1);
}
