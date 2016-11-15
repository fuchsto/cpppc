#ifndef CPPPC__03__STANDARD_SEMANTICS_TEST__H__INCLUDED
#define CPPPC__03__STANDARD_SEMANTICS_TEST__H__INCLUDED

namespace cpppc {

template <typename ContainerType>
class StandardSemanticsTest
{

  typedef StandardSemanticsTest<ContainerType>  self_t;
  typedef ContainerType                         container_t;

public:

  static void run()
  {
    self_t test_suite;
    test_suite.TestAssignment();
  }

protected:

  void TestAssignment();

};

} // namespace cpppc

#include "standard_semantics_test.impl.h"

#endif // CPPPC__03__STANDARD_SEMANTICS_TEST__H__INCLUDED
