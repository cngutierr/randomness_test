#include "unity_fixture.h"

static void RunAllTests(void)
{
    RUN_TEST_GROUP(UtilTest);
    RUN_TEST_GROUP(RandTest);
}

int main(int argc, const char* argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
