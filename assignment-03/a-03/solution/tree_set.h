#ifndef CPPPC__A02__TREE_SET_H__INCLUDED
#define CPPPC__A02__TREE_SET_H__INCLUDED

namespace cpppc {

namespace detail {

template <typename T>
class TreeSetIterator
{

};

} // namespace detail

template <typename T>
class TreeSet
{
  typedef TreeSet<T> self_t;

public:

  typedef       T                              value_type;

  typedef       detail::TreeSetIterator<T>       iterator;
  typedef const detail::TreeSetIterator<T> const_iterator;

public:

  TreeSet() = default;

  iterator begin() const
  {
  }

  const iterator end() const
  {
  }

private:

};

} // namespace cpppc

#endif // CPPPC__A02__TREE_SET_H__INCLUDED
