
#include <functional>
#include <iterator>
#include <iostream>
#include <algorithm>


template <class T>
class LazySequence
{

public:

  class iterator {
    typedef iterator self_t;
  public:
    iterator() = delete;

    iterator(
      const LazySequence<T>       & seq,
      const std::function<T(int)> & gen,
      int                           pos)
    : _seq(seq), _gen(gen), _pos(pos)
    { }

    T operator*() const {
      return _gen(_pos);
    }

    self_t & operator++() {
      _pos++;
      return *this;
    }

    self_t & operator--() {
      _pos--;
      return *this;
    }

    self_t operator++(int) const {
      return self_t(_seq, _gen, _pos+1);
    }

    self_t operator--(int) const {
      return self_t(_seq, _gen, _pos-1);
    }

    bool operator==(const self_t & rhs) const {
      return _pos == rhs._pos;
    }

    bool operator!=(const self_t & rhs) const {
      return not (*this == rhs);
    }

  private:
    const LazySequence<T>       & _seq;
    const std::function<T(int)>   _gen;
    int                           _pos;
  };

public:

  LazySequence(
    size_t                size,
    std::function<T(int)> gen)
    : _size(size), _gen(gen)
  { }

  iterator begin() const {
    return iterator(*this, _gen, 0);
  }

  iterator end() const {
    return iterator(*this, _gen, _size);
  }

private:
  size_t                _size;
  std::function<T(int)> _gen;
};


int main()
{
  LazySequence<int> seq(10,
                        [](int i) {
                          return (100 + i * i);
                        });

  for (auto e : seq) {
    std::cout << e << " ";
  }
  std::cout << std::endl;

  return 0;
}
