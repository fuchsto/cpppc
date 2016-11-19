
#include "find_mean_rep_test.h"

#include <solution/find_mean_rep.h>

#include <gtest/gtest.h>

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>


TEST_F(FindMeanRepTest, RandomAccessIterators)
{
  LOG_MESSAGE("FindMeanRepTest.InputIterators");
  std::list<int> l_empty;
  ASSERT_EQ(l_empty.end(), find_mean_rep(l_empty.begin(), l_empty.end()));

  std::list<int> l1 { 5, 0, 10, 5 };
  ASSERT_EQ(l1.begin(), find_mean_rep(l1.begin(), l1.end()));


}

