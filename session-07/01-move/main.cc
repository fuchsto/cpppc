
#include "array_wrapper.h"
#include "array_maker.h"

#include <algorithm>
#include <tuple>
#include <iostream>
#include <sstream>
#include <random>


template <class Iter>
std::ostream & operator<<(
  std::ostream                & os,
  const std::tuple<Iter,Iter> & rg)
{
  std::ostringstream ss;
  auto it  = std::get<0>(rg);
  auto end = std::get<1>(rg);
  for (; it != end; ++it) {
    ss << *it << " ";
  }
  os << ss.str();
  return os;
}

template <class Iter, class Val>
Iter fill_rand(
  Val  min,
  Iter begin,
  Iter end) {
  // Q: How random is this really? We'll discuss
  //    this in detail next week
  std::fill(begin, end, min + std::rand() % 15);
  return end;
}


using std::cout;
using std::endl;

int main()
{
  ArrayWrapper<int> a(123, "A");
  fill_rand(10, a.begin(), a.end());
  LOG("main", std::make_tuple(a.begin(), a.begin()+7));
  LOG("main", "-------------------------------------"); 

  ArrayWrapper<int> b(455, "B");
  fill_rand(20, b.begin(), b.end());
  LOG("main", std::make_tuple(b.begin(), b.begin()+7));
  LOG("main", "-------------------------------------"); 

  ArrayWrapper<int> a2(a);
  fill_rand(30, a2.begin(), a2.end());
  LOG("main", std::make_tuple(a2.begin(), a2.begin()+7));
  LOG("main", "-------------------------------------"); 

  ArrayWrapper<int> e(ArrayWrapper<int>(130, "E"));
  fill_rand(50, e.begin(), e.end());
  LOG("main", std::make_tuple(e.begin(), e.begin()+7));
  LOG("main", "-------------------------------------"); 

  ArrayWrapper<int> m = return_array_by_value(145, "M");
  fill_rand(40, m.begin(), m.end());
  LOG("main", std::make_tuple(m.begin(), m.begin()+7));
  LOG("main", "-------------------------------------"); 
  
  LOG("main", "*PFWOOOHFFF* -> " <<
      accept_array_by_value(
        return_array_by_value(234, "X")
      ));

  return 0;
}

