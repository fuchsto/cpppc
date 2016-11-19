#ifndef CPPPC__S03__SPARSE_ARRAY_H__INCLUDED
#define CPPPC__S03__SPARSE_ARRAY_H__INCLUDED

#include <unordered_map>


namespace cpppc {

namespace detail {

template <class SparseArrayT>
class sparse_array_iterator
{
public:

  sparse_array_iterator(
    SparseArrayT & sparse_array,
    int            pos = 0)
  : _sparse_array(sparse_array),
    _pos(pos)
  { }

private:

  SparseArrayT & _sparse_array;
  int            _pos = 0;

};

template <class SparseArrayT>
class sparse_array_proxy_ref
{
};

} // namespace detail

template <class T, std::size_t N>
class sparse_array
{
  typedef sparse_array<T, N>                      self_t;
  typedef detail::sparse_array_proxy_ref<self_t>  proxy_reference;
  typedef int                                     index_t;

public:

  typedef detail::sparse_array_iterator<self_t>   iterator;
  typedef index_t                                 difference_type;

  friend iterator;

public:

  sparse_array(T default_value = T())
  : _default(default_value),
    _begin(*this, 0),
    _end(*this, N)
  { }

  iterator begin() const {
    return _begin;
  }

  iterator end() const {
    return _end;
  }

  proxy_reference operator[](int index) {
    return proxy_reference(*this, index);
  }

private:

  T                              _default = 0;
  std::unordered_map<index_t, T> _values;
  iterator                       _begin;
  iterator                       _end;

};

} // namespace cpppc

#endif // CPPPC__S03__SPARSE_ARRAY_H__INCLUDED
