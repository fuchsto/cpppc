#ifndef CPPPC__S03__FIND_MEAN_REP_H__INCLUDED
#define CPPPC__S03__FIND_MEAN_REP_H__INCLUDED

#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>

namespace cpppc {

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
  LOG_MESSAGE("find_mean_rep: diffs:{ %s }",
              range_to_string(diffs.begin(), diffs.end()).c_str());
  auto result(first);
  auto mean_rep_pos = std::distance(diffs.begin(),
                                    std::min_element(diffs.begin(),
                                                     diffs.end()));
  LOG_MESSAGE("find_mean_rep: pos:%d", mean_rep_pos);
  std::advance(result, mean_rep_pos);
  return result;
}

} // namespace cpppc

#endif // CPPPC__S03__FIND_MEAN_REP_H__INCLUDED
