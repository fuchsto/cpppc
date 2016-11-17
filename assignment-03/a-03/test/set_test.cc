
#include "set_test.h"

#include <solution/tree_set.h>
#include <gtest/gtest.h>

/*
 * See: http://en.cppreference.com/w/cpp/container/set
 *
 */

TEST_F(SetTest, StandardConcept)
{
  LOG_MESSAGE("SetTest.StandardConcept: default ctor");
  TreeSet<int> t1;
  TreeSet<int> t2;

  LOG_MESSAGE("SetTest.StandardConcept: ==");
  ASSERT_EQ(t1, t1);
  ASSERT_EQ(t2, t2);
  ASSERT_EQ(t1, t2);

  auto t1_it = t1.insert(123);

  ASSERT_NE(t1, t2);

  LOG_MESSAGE("SetTest.StandardConcept: =");
  t2 = t1;
  ASSERT_EQ(t1, t2);

  TreeSet<int> t3(t1);
  ASSERT_EQ(t1, t3);
}

TEST_F(TreeTest, SetConcept)
{
  TreeSet<int> t;
  t.insert(123);

  ASSERT_NE(t.find(123), t.end());
}

