#ifndef CPPPC__03__STANDARD_SEMANTICS_TEST__IMPL_H__INCLUDED
#define CPPPC__03__STANDARD_SEMANTICS_TEST__IMPL_H__INCLUDED

#include <gtest/gtest.h>


template <typename ContainerType>
void StandardSemanticsTest::TestAssignment()
{
  container_t c0;
  container_t c1;

  c0.push_back(1);
  c0.push_back(2);

  c1 = c0;

  ASSERT_EQ(c0, c1);
}

#endif // CPPPC__03__STANDARD_SEMANTICS_TEST__IMPL_H__INCLUDED
