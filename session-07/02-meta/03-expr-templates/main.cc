
#include <iostream>

// #include "vector_ops.h"
#include "vector_et_ops.h"

int main()
{
  cpppc::vector<int> v1 { 1, 2, 3, 4 };
  cpppc::vector<int> v2 { 5, 6, 7, 8 };
  cpppc::vector<int> v3 { 9, 0, 1, 2 };

  std::cout << "instantiate vector_sum:" << std::endl;
  auto vsum = v1 + v2;

  std::cout << "assign vector_sum:" << std::endl;
  v3 = vsum;

  for (auto e : v3) { std::cout << e << " "; }
  std::cout << std::endl;

  return 0;
}

