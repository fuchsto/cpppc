
#include "set_test.h"

#include <solution/tree_set.h>
#include <gtest/gtest.h>

/*
 * See:
 * - http://en.cppreference.com/w/cpp/container/set
 * - http://en.cppreference.com/w/cpp/language/dependent_name
 *
 */

TEST_F(TreeTest, StandardConcept)
{
  LOG_MESSAGE("TreeTest.StandardConcept: default ctor");
  TreeSet<int> t1;
  TreeSet<int> t2;

  LOG_MESSAGE("TreeTest.StandardConcept: ==");
  ASSERT_EQ(t1, t1);
  ASSERT_EQ(t2, t2);
  ASSERT_EQ(t1, t2);

  auto t1_it = t1.insert(123);

  ASSERT_NE(t1, t2);

  LOG_MESSAGE("TreeTest.StandardConcept: =");
  t2 = t1;
  ASSERT_EQ(t1, t2);

  TreeSet<int> t3(t1);
  ASSERT_EQ(t1, t3);
}

TEST_F(TreeTest, TreeConcept)
{
  TreeSet<int> t;
  t.insert(123);

  ASSERT_NE(t.find(123), t.end());
}

