
// Also see:
// http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html

class ArrayWrapper {
 public:
  ArrayWrapper()
    : _p_vals(new int[64]), _size(64) { }

  ArrayWrapper(int n)
    : _p_vals(new int[n]),  _size(n)  { }

  // move constructor
  ArrayWrapper(ArrayWrapper&& other)
      : _p_vals(other._p_vals),
        _size(other._size) {
    other._p_vals = NULL;
    other._size   = 0;
  }

  // copy constructor
  ArrayWrapper(const ArrayWrapper& other)
      : _p_vals(new int[other._size]),
        _size(other._size) {
    for (int i = 0; i < _size; ++i) {
      _p_vals[i] = other._p_vals[i];
    }
  }
  ~ArrayWrapper() { delete[] _p_vals; }

 private:
  int* _p_vals;
  int  _size;
};
