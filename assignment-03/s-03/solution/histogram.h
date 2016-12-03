#ifndef CPPPC__S03__HISTOGRAM_H__INCLUDED
#define CPPPC__S03__HISTOGRAM_H__INCLUDED

#include <unordered_map>
#include <set>
#include <algorithm>
#include <iterator>


template <class Iter>
inline Iter histogram(Iter first, Iter last) {
    typedef typename std::iterator_traits<Iter>::value_type      value_t;
    typedef typename std::iterator_traits<Iter>::difference_type index_t;
    std::unordered_map<index_t, value_t> bins;
    std::for_each(first, last,
                  [&bins] (const value_t & e) {
                    bins[e]++;
                  });
    std::set<value_t> seen;
    auto ulast = std::remove_if(
                   first, last,
                   [&seen](const value_t & val) {
                     if (seen.find(val) != std::end(seen)) {
                       return true;
                     } else {
                       seen.insert(val);
                       return false;
                     }
                   });
    LOG_MESSAGE("histogram unique: %s",
                range_to_string(first, ulast).c_str());
    std::transform(first, ulast, first,
                  [&bins] (value_t & e) {
                    return static_cast<value_t>(bins[e]);
                  });
    return ulast;
}

#endif // CPPPC__S03__HISTOGRAM_H__INCLUDED
