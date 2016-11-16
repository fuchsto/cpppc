#ifndef CPPPC__A02__TREE_TEST_H__INCLUDED
#define CPPPC__A02__TREE_TEST_H__INCLUDED

#include <gtest/gtest.h>
#include "TestBase.h"

class TreeTest : public ::testing::Test {

public:

  TreeTest() {
    LOG_MESSAGE("Opening test suite: TreeTest");
  }

  virtual ~TreeTest() {
    LOG_MESSAGE("Closing test suite: TreeTest");
  }

  virtual void SetUp() {
  }

  virtual void TearDown() {
  }

};

#endif // CPPPC__A02__TREE_TEST_H__INCLUDED
