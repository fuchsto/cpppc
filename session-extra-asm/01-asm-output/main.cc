#include "macro.h"
#include "heap.h"

#include <iostream>
#include <cstdlib>


using cpppc::Heap;
using cpppc::HeapElement;

using std::cout;
using std::endl;

int main(int argc, char * argv[])
{
  wno_unused_(argc);
  wno_unused_(argv);

  // See constant folding in action;
  int const_val = 0x0f + 0xf0;

  Heap heap_0("pool_0", 0, 100.0);

  heap_0[0] = HeapElement { const_val * 310.0 };
  heap_0[1] = HeapElement { const_val * 320.0 };

  cout << heap_0 << endl;

  return EXIT_SUCCESS;
}
