#ifndef CPPPC__03__BUCKET_VECTOR__H__INCLUDED
#define CPPPC__03__BUCKET_VECTOR__H__INCLUDED

namespace cpppc {

template <typename ValueType>
class BucketVector
{

  typedef BucketVector<ValueType>      self_t;
  typedef ValueType                   value_t;

public:

  typedef ValueType                value_type;

public:

  BucketVector(int initial_size)
  : _elements(initial_size)
  { }

  ~BucketVector() { }

private:

  std::vector<ValueType>            _elememts;

};

} // namespace cpppc

#endif CPPPC__03__BUCKET_VECTOR__H__INCLUDED
