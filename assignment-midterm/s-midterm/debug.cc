
#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include <future>


template <typename SeqContainer, typename UnaryPred>
SeqContainer & drop(SeqContainer & c, UnaryPred condition) {
  for (auto i = c.begin(); i != c.end(); ++i) {
    if (condition(*i)) {
      c.erase(i);
    }
  }
}

int main() {

  std::list<int> l;

  int x = 100;
  std::generate_n(
    std::back_inserter(l), 23,
    [&]() -> int { return ++x; }
  );

  for (auto e : l) {
    std::cout << e << " ";
  }
  std::cout << std::endl;

  auto f = std::async(
              std::launch::async,
              [&]() -> auto { 
                return drop(l, [](int x) -> bool {
                  return x % 3 == 0;
                });
              }
           );

  auto ld = f.get();

  return EXIT_SUCCESS;
}

