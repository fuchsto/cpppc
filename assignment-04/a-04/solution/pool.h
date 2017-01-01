#ifndef ASSIGNMENT__A04__POOL_H__INCLUDED
#define ASSIGNMENT__A04__POOL_H__INCLUDED

#include <thread>
#include <mutex>
#include <atomic>


namespace cpppc {

/**
 * Note that type \c ElementT must be default-constructible.
 */
template <class ElementT>
class Pool
{

public:

  Pool(size_t capacity)
  : _elements(static_cast<typename std::vector<ElementT>::size_type>(
                capacity)),
    _size(capacity)
  { }

  template <class Iter>
  Pool(const Iter & first, const Iter & last)
  : _size(std::distance(first, last)) {
    _elements.insert(_elements.begin(), first, last);
  }

  inline size_t size() const {
    return _size;
  }

  inline bool empty() const {
    return _size == 0;
  }

  /**
   * Take element from pool. Element is reserved for calling thread and
   * not available to other threads.
   */
  ElementT acquire() {
    std::lock_guard<std::mutex> lg(__mx);

    ElementT result(_elements.back());
    _elements.pop_back();
    return result;
  }

  /**
   * Put element back into pool and make it available to other threads
   * again.
   */
  void release(const ElementT & element) {
    std::lock_guard<std::mutex> lg(__mx);

    _elements.push_back(element);
  }

private:

  std::vector<ElementT> _elements;
  size_t                _size      = 0;

private:

  static std::mutex    __mx;

};

} // namespace cpppc

template <class T>
std::mutex cpppc::Pool<T>::__mx;

#endif // ASSIGNMENT__A04__POOL_H__INCLUDED
