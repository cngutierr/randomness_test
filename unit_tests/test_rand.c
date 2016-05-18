#include "rand_tests.h"
#include "unity_fixture.h"

TEST_GROUP(RandTest);
TEST_SETUP(RandTest){}
TEST_TEAR_DOWN(RandTest){}

TEST(RandTest, test_mono_freq_rand1)
{
  unsigned char testbuf[2] = {0xff, 0x00};
  TEST_ASSERT_EQUAL(1.0, freq_monobit(testbuf, 2));
}

TEST(RandTest, test_mono_freq_rand2)
{
  unsigned char testbuf[2] = {0xf0, 0xa7};
  TEST_ASSERT_FLOAT_WITHIN(0.01, 0.61, freq_monobit(testbuf, 2));
}

TEST(RandTest, test_block_freq_rand1)
{
  unsigned char testbuf[16] = {0xc1, 0xaf, 0x5d, 0xdd,
                               0xd9, 0x61, 0x03, 0xc9,
                               0x54, 0x87, 0xd7, 0x61,
                               0x13, 0xf2, 0x63, 0x20};
  TEST_ASSERT_FLOAT_WITHIN(0.01, 0.69, freq_block(testbuf, 16, 3));
}

TEST(RandTest, test_block_freq_rand2)
{
  unsigned char testbuf[16] = {0xc1, 0xaf, 0x5d, 0xdd,
                               0xd9, 0x61, 0x03, 0xc9,
                               0x54, 0x87, 0xd7, 0x61,
                               0x13, 0xf2, 0x63, 0x20};
  TEST_ASSERT_FLOAT_WITHIN(0.01, 0.45, freq_block(testbuf, 16, 4));
}

TEST(RandTest, test_block_freq_not1)
{
  unsigned char testbuf[16] = {0xff, 0xaf, 0xff, 0xff,
                              0xff, 0xff, 0xff, 0xff,
                              0xff, 0xff, 0xff, 0xff,
                              0xff, 0xff, 0xff, 0xff};
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0.0, freq_block(testbuf, 16, 4));
}

TEST(RandTest, test_runs_rand1)
{
  unsigned char testbuf[16] = {0xc1, 0xaf, 0x5d, 0xdd,
                               0xd9, 0x61, 0x03, 0xc9,
                               0x54, 0x87, 0xd7, 0x61,
                               0x13, 0xf2, 0x63, 0x20};
  TEST_ASSERT_FLOAT_WITHIN(0.1, 0.48, runs(testbuf, 16));
}

TEST(RandTest, test_runs_rand2)
{
  unsigned char testbuf[16] = {0x1e, 0xbf, 0xeb, 0x16,
                               0xd8, 0x25, 0xdb, 0xc4,
                               0x02, 0x6a, 0x2f, 0x49,
                               0x14, 0x91, 0x1c, 0x51};
  TEST_ASSERT_FLOAT_WITHIN(0.1, 0.35, runs(testbuf, 16));
}

TEST(RandTest, test_runs_not1)
{
  unsigned char testbuf[16] = {0xaa, 0xaa, 0xbb, 0xff,
                               0x9f, 0xff, 0xff, 0x00,
                               0xff, 0xff, 0xff, 0x00,
                               0xaa, 0xaa, 0x00, 0x00};
  TEST_ASSERT_FLOAT_WITHIN(0.1, 0.01, runs(testbuf, 16));
}



TEST(RandTest, test_runs_one_block_rand1)
{
  unsigned char testbuf[16] = {0xc1, 0xaf, 0x5d, 0xdd,
                               0xd9, 0x61, 0x03, 0xc9,
                               0x54, 0x87, 0xd7, 0x61,
                               0x13, 0xf2, 0x63, 0x20};
  TEST_ASSERT_FLOAT_WITHIN(0.01, 0.63, runs_one_block(testbuf, 16, 1));
}

TEST(RandTest, test_runs_one_block_rand2)
{
  unsigned char testbuf[16] = {0x1e, 0xbf, 0xeb, 0x16,
                               0xd8, 0x25, 0xdb, 0xc4,
                               0x02, 0x6a, 0x2f, 0x49,
                               0x14, 0x91, 0x1c, 0x51};
  TEST_ASSERT_FLOAT_WITHIN(0.01, 0.42, runs_one_block(testbuf, 16,1));
}

TEST(RandTest, test_runs_one_block_not1)
{
  unsigned char testbuf[16] = {0xaa, 0xaa, 0xbb, 0xff,
                               0x9f, 0xff, 0xff, 0x00,
                               0xff, 0xff, 0xff, 0x00,
                               0xaa, 0xaa, 0x00, 0x00};
  TEST_ASSERT_FLOAT_WITHIN(0.1, 0.0001, runs_one_block(testbuf, 16,1));
}
