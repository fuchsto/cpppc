
#include "macro.h"
#include "list.h"

#include <iostream>
#include <chrono>
#include <string>
#include <algorithm>
#include <iterator>

/* An instance of a functional data structure is conceptually immutable in
 * the scope of its operations.
 * As a consequence, there is no need for synchronization: an immutable
 * object cannot cause a race condition.
 * Instead of changing the state of the data structure (mutation), the
 * operation creates a modified clone of the immutable object.
 *
 * In principle, you could use std::vector as a functional data structure,
 * but this would require inefficient deep-copying in every operation.
 *
 * The principle idea of functional data structures is to share most data
 * with the cloned immutable object and represent the modification as a
 * delta record in the result object.
 *
 * Q: Outline how you would prove that operations based on this method are
 *    well-defined.
 *    Hint: use a binary tree as an example and try induction.
 *
 * Related work:
 *
 *   "Uniqueness and reference immutability for safe parallelism"
 *   CS Gordon, MJ Parkinson, J Parsons et al., 2012
 *   -> https://www.cs.drexel.edu/~csgordon/papers/oopsla12.pdf
 */

using std::cout;
using std::endl;

using namespace std::chrono;

List<char> test1()
{
  List<char> lst0;
  auto lst1 = lst0.pushed_front('a');
  // a: ref 1
  std::cout << lst1 << std::endl;
  auto lst2 = lst1.pushed_front('b');
  // b: ref 1
  // a: ref 2
  std::cout << lst2 << std::endl;
  return lst2;
  // lst1 is deleted decrementing ref count on a
}

List<char> test2()
{
  auto lst3 = test1(); // {b, a}
  // b: ref 1
  // a: ref 1
  std::cout << lst3 << std::endl;
  auto lst4 = lst3.insertedAt(1, 'x'); // {b, x, a}
  // x: ref 1
  // b: ref 2
  // a: ref 1
  std::cout << lst4 << std::endl;
  auto lst5 = concat(lst3, lst4);
  std::cout << lst5 << std::endl;
  return lst5;
}

void testLst()
{
  auto lst = test2();
  std::cout << lst << std::endl;
}

void testHigher()
{
  std::string str = "abcd";
  auto lst = fromIt(str.begin(), str.end());
  auto lst2 = fmap<char>(toupper, lst);
  std::cout << lst2 << std::endl;

  auto result = foldr([](char c, std::string str) {
    return str + c;
  }, std::string(), lst2);
  std::cout << result << std::endl;

  auto result2 = foldl([](std::string str, char c) {
    return str + c;
  }, std::string(), lst2);
  std::cout << result2 << std::endl;

  std::string mix = "TooMuchInformation";
  auto lst3 = filter(isupper, fromIt(mix.begin(), mix.end()));
  std::cout << lst3 << std::endl;
}

void try_consume(List<int> lst);

int main()
{
  List<int> lst = { 1, 2, 3 };
  printRaw(lst);

  // doesn't consume
  try_consume(lst);

  // consumes
  try_consume(std::move(lst));

  printRaw(lst);

  {
    List<int> lst1 { 10, 20, 30, 40, 50 };

    for (int x : lst1) {
      std::cout << x << " ";
    }
    std::cout << std::endl;

    OutListIter<int> out;
    auto it = std::transform(std::begin(lst1), std::end(lst1), out,
                             [](int i) { return ++i; });

    std::cout << it.getList() << std::endl;

    std::cout << lst1 << std::endl;
    auto lst2 = reversed(lst1);
    std::cout << lst2 << std::endl;
  }
  testLst();
  testHigher();

  return EXIT_SUCCESS;
}

void try_consume(List<int> lst)
{
  printRaw(lst);
  while (!lst.isEmpty()) {
    std::cout << lst.front();
    lst = lst.popped_front();
  }
  printRaw(lst);
}

