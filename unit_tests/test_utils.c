#include "unity.h"
#include "utils.h"
#include "unity_fixture.h"

TEST_GROUP(UtilTest);
TEST_SETUP(UtilTest){}
TEST_TEAR_DOWN(UtilTest){}

TEST(UtilTest, test_bit_sum_zero)
{
  unsigned char testbuf[4] = {0xff, 0xff, 0x00, 0x00};
  TEST_ASSERT_EQUAL(0, bit_sum(testbuf, 4));
}

TEST(UtilTest, test_bit_sum_neg16)
{
  unsigned char testbuf[2] = {0x00, 0x00};
  TEST_ASSERT_EQUAL(-16, bit_sum(testbuf, 2));
}

TEST(UtilTest, test_bit_sum_one)
{
  unsigned char testbuf[8] = {0x00, 0x00, 0xff, 0xff,
                              0xaa, 0xaa, 0xaa, 0xa7};
  TEST_ASSERT_EQUAL(2, bit_sum(testbuf, 8));
}


TEST(UtilTest, test_bit_count_8)
{
  TEST_ASSERT_EQUAL(8, bit_count(0xff));
}

TEST(UtilTest, test_bit_count_4)
{
  TEST_ASSERT_EQUAL(4, bit_count(0x0f));
}

TEST(UtilTest, test_bit_count_2)
{
  TEST_ASSERT_EQUAL(2, bit_count(0x03));
}

TEST(UtilTest, test_bit_count_1)
{
  TEST_ASSERT_EQUAL(1, bit_count(0x20));
}

TEST(UtilTest, test_bit_count_0)
{
  TEST_ASSERT_EQUAL(0, bit_count(0x00));
}

TEST(UtilTest, test_run_count_8)
{
    unsigned char testbuf[1] = {0x55};
    TEST_ASSERT_EQUAL(8, run_count(testbuf, 1));
}

TEST(UtilTest, test_run_count_16)
{
    unsigned char testbuf[2] = {0x55, 0x55};
    TEST_ASSERT_EQUAL(16, run_count(testbuf, 2));
}

TEST(UtilTest, test_run_count_1)
{
    unsigned char testbuf[2] = {0x00, 0xff};
    TEST_ASSERT_EQUAL(2, run_count(testbuf, 2));
}
