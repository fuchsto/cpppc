#include "macro.h"

#include "vector.h"
//#include "stack.h"
//#include "deque.h"

//#include "standard_semantics_test.h"
//#include "deque_semantics_test.h"
//#include "vector_semantics_test.h"
//#include "stack_semantics_test.h"

#include <iostream>
#include <cstdlib>
#include <cassert>


using std::cout;
using std::endl;

// using cpppc::Stack;
using cpppc::Vector;
// using cpppc::Deque;

// using cpppc::StandardSemanticsTest;
// using cpppc::StackSemanticsTest;
// using cpppc::VectorSemanticsTest;
// using cpppc::DequeSemanticsTest;

template <typename SeqContainerType>
void print_values(const SeqContainerType & sc)
{
  std::cout << "{ ";
  for (auto it = sc.begin(); it != sc.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "}" << std::endl;
}

int main(int argc, char * argv[])
{
  wno_unused_(argc);
  wno_unused_(argv);

  Vector<int> v0;
  Vector<int> v1;

  assert(v0 == v1 && v1 == v0);

  assert(v0.size() == 0 && v0.empty());
  assert(v1.size() == 0 && v1.empty());

  v0.push_back(1);
  v0.push_back(2);
  v0.push_back(3);
  print_values(v0);

  assert(v0.size() == 3 && !v0.empty());
  assert(v0.at(0) == 1);
  assert(v0.at(1) == 2);
  assert(v0.at(2) == 3);

  v1 = v0;
  print_values(v1);

  assert(v0 == v1 && v1 == v0);

  assert(v0.at(0) == v1.at(0));
  assert(v0.at(1) == v1.at(1));
  assert(v0.at(2) == v1.at(2));

  Vector<int> v2(v1);
  v2.push_back(4);
  v2.push_back(5);
  v2.push_back(6);
  print_values(v2);

//StandardSemanticsTest<Stack>::run();
//StandardSemanticsTest<Vector>::run();
//StandardSemanticsTest<Deque>::run();

//StackSemanticsTest<Stack>::run();
//StackSemanticsTest<Vector>::run();
//StackSemanticsTest<Deque>::run();

//VectorSemanticsTest<Vector>::run();
//VectorSemanticsTest<Deque>::run();

//DequeSemanticsTest<Deque>::run();

  return EXIT_SUCCESS;
}
