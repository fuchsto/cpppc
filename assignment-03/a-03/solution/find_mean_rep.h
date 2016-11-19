#ifndef CPPPC__S03__FIND_MEAN_REP_H__INCLUDED
#define CPPPC__S03__FIND_MEAN_REP_H__INCLUDED

#include <algorithm>
#include <numeric>
#include <vector>


template <class Iter>
Iter find_mean_rep(Iter first, Iter last) {
  typedef typename Iter::value_type value_t;
  auto len  = std::distance(first, last);
  if (len == 0) { return last; }
  auto mean = std::accumulate(first, last, 0) / len;
  std::vector<value_t> diffs;
  std::for_each(first, last,
                [&](const value_t & val) {
                  diffs.push_back(std::abs(val - mean));
               });
  auto result(first);
  std::advance(
    result,
    std::distance(diffs.begin(),
                  std::min_element(diffs.begin(), diffs.end())));
  return result;
}

#endif // CPPPC__S03__FIND_MEAN_REP_H__INCLUDED
