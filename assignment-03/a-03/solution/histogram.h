#ifndef CPPPC__S03__HISTOGRAM_H__INCLUDED
#define CPPPC__S03__HISTOGRAM_H__INCLUDED

template <class Iter>
inline void histogram(Iter first, Iter last) {
    typedef typename Iter::value_type value_t;
    size_t bmax = 0; // max bin
    std::vector<value_t> h;
    for_each(first, last,
             [&h, &bmax] (const value_t & e) {
                 h[e]++;
                 bmax = std::max(bmax, h[e]);
             });
    return h;
}

#endif // CPPPC__S03__HISTOGRAM_H__INCLUDED
