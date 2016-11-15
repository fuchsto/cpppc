#ifndef CPPPC__03__VECTOR_H__INCLUDED
#define CPPPC__03__VECTOR_H__INCLUDED

#include <exception>
#include <stdexcept>
#include <cstring>
#include <cstdlib>


namespace cpppc {

template <typename ElementType>
class Vector
{
  typedef Vector<ElementType> self_t;
  typedef ElementType         value_t;

  static const int            _chunk_size = 2;

public:

  typedef value_t            value_type;

  typedef value_t *          iterator;
  typedef value_t * const    const_iterator;
  typedef value_t &          reference;

public:

  Vector() noexcept
  { }

  Vector(const self_t & other)
  {
    resize(other._capacity);
    _size = other._size;
    memcpy(_elements, other._elements, _size * sizeof(value_t));
  }

  ~Vector() noexcept
  {
    clear();
  }

  Vector & operator=(const self_t & rhs)
  {
    clear();
    resize(rhs._capacity);
    _size = rhs._size;
    memcpy(_elements, rhs._elements, _size * sizeof(value_t));

    return *this;
  }

  bool operator==(const self_t & rhs) const noexcept
  {
    if (_size != rhs._size) {
      return false;
    }
    for (int i = 0; i < _size; i++) {
      if (_elements[i] != rhs._elements[i]) {
        return false;
      }
    }
    return true;
  }

  int  size() const noexcept
  {
    return _size;
  }

  bool empty() const noexcept
  {
    return 0 == _size;
  }

  void clear()
  {
    // Q: Are destructors of elements called? Why (not)?
    free(_elements);
    _elements = nullptr;
    _size     = 0;
    _capacity = 0;
  }

  void resize(int new_size)
  {
    if (new_size <= _capacity) {
      return;
    }
    value_t * resized_elements = static_cast<value_t *>(
                                   realloc(_elements,
                                           sizeof(value_t) * new_size));
    if (nullptr != resized_elements) {
      _elements = resized_elements;
      _capacity = new_size;
    } else {
      throw std::runtime_error("realloc failed in cpppc::Vector.resize()");
    }
  }

  void push_back(const value_t & value)
  {
    if (_size >= _capacity) {
      resize(_capacity + _chunk_size);
    }
    _elements[_size] = value;
    _size++;
  }

  // Q: Could we return a reference here? Compare with std::vector!
  value_type pop_back()
  {
    if (_size <= 0) {
      throw std::runtime_error("cpppc::Vector.pop_back(): vector empty");
    }

    _size--;

    if (_capacity - _size > _chunk_size) {
      value_t * resized_elements = static_cast<value_t *>(
                                     realloc(_elements,
                                             sizeof(value_t) * _size));
      if (nullptr != resized_elements) {
        _elements = resized_elements;
        _capacity = _size;
      }
    }

    return _elements[_size];
  }

  iterator begin() const
  {
    return &(_elements[0]);
  }

  iterator end() const
  {
    return &(_elements[_size]);
  }

  reference operator[](int offset) const
  {
    return _elements[offset];
  }

  reference at(int offset) const
  {
    return _elements[offset];
  }

private:

  value_t * _elements = nullptr;
  int       _size     = 0;
  int       _capacity = 0;

};

} // namespace cpppc

#endif // CPPPC__03__VECTOR_H__INCLUDED
