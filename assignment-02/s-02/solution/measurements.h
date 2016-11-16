#ifndef CPPPC__A02__MEASUREMENTS_H__INCLUDED
#define CPPPC__A02__MEASUREMENTS_H__INCLUDED

#include <vector>
#include <cmath>

namespace cpppc {

template <typename T>
class Measurements
{

  typedef Measurements<T>                                   self_t;
  typedef T                                                value_t;

  typedef       T &                                      reference;
  typedef const T &                                const_reference;
  typedef typename std::vector<T>::iterator               iterator;
  typedef typename std::vector<T>::const_iterator   const_iterator;

public:

  inline bool operator==(const self_t & rhs) const
  {
    return _values == rhs._values;
  }

  inline iterator insert(const T & value)
  {
    _values.push_back(value);
    return _values.begin() + (_values.size() - 1);
  }

  template <typename Iter>
  void insert(const Iter & in_first, const Iter & in_last)
  {
    for (auto it = in_first; it != in_last; ++it) {
      _values.push_back(*it);
    }
  }

  inline int size() const
  {
    return _values.size();
  }

  inline bool empty() const
  {
    return size() == 0;
  }

  inline void clear()
  {
    _values.clear();
  }

  inline iterator begin()
  {
    return _values.begin();
  }

  inline const_iterator begin() const
  {
    return _values.begin();
  }

  inline iterator end()
  {
    return _values.end();
  }

  inline const_iterator end() const
  {
    return _values.end();
  }

  inline reference front()
  {
    return _values.front();
  }

  inline reference back()
  {
    return _values.back();
  }

  inline reference operator[](int index)
  {
    return _values[index];
  }

  inline const_reference operator[](int index) const
  {
    return _values[index];
  }

  T median() const
  {
    if (_values.size() == 0) {
      return 0;
    }
    std::vector<T> sorted_values(_values);
    std::sort(sorted_values.begin(), sorted_values.end());
    return sorted_values[sorted_values.size() / 2];
  }

  double mean() const
  {
    double mean_val = 0;
    if (_values.size() == 0) {
      return mean_val;
    }
    for (auto v : _values) {
      mean_val += v;
    }
    return mean_val / _values.size();
  }

  double variance() const
  {
    if (_values.size() == 0) {
      return 0;
    }
    double mean_val = mean();
    double var_acc  = 0;
    for (auto v : _values) {
      double v_dev = v - mean_val;
      var_acc += (v_dev * v_dev);
    }
    return var_acc / _values.size();
  }

  double sigma() const
  {
    if (_values.size() == 0) {
      return 0;
    }
    return sqrt(variance());
  }

private:

  std::vector<T> _values;

};

} // namespace cpppc

#endif // CPPPC__A02__MEASUREMENTS_H__INCLUDED
