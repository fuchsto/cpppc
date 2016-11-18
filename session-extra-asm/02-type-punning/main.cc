#include "macro.h"

#include <cinttypes>
#include <iostream>
#include <cstdlib>
#include <cstring> // For absurd reasons, memcpy is defined in string.h

using std::cout;
using std::endl;

typedef uint64_t pun_t;

static_assert(sizeof(double) == sizeof(pun_t), "Incompatible pun type");

// Type punning!
//
// Extremely important in the real world, and not taught to kids any more
// these days.
//
// See:
//   https://en.wikipedia.org/wiki/Type_punning
//
// Hell of a cool use case:
//   https://en.wikipedia.org/wiki/Fast_inverse_square_root
//
//
// NOTE: These examples have been chosen for simplicity and are by no means
//       production-ready implementations!
//       In particular, consider pointer aliasing:
//       http://cellperformance.beyond3d.com/articles/2006/06/understanding-strict-aliasing.html

int main(int argc, char * argv[])
{
  wno_unused_(argc);
  wno_unused_(argv);

  cout << "  Hank the Hacker claims that type punning is best done" << endl
       << "  using reinterpret_cast in C++11 because compilers" << endl
       << "  are clever and better than us." << endl
       << "  Bob the Bullshitter objects that it has some overhead" << endl
       << "  compared to a C-style-cast and memcpy, C being low-level" << endl
       << "  and all and easier for compilers to optimize." << endl
       << "  Is Bob right?" << endl
       << endl;


  double double_value    = 1.0e+2;
  pun_t  punned_value_mc = 0;
  pun_t  punned_value_rc = 0;

  // BEGIN MEMCPY VARIANT {
  double * punned_dest_mc = (double *)(&punned_value_mc);
  memcpy(punned_dest_mc,
         &double_value,
         sizeof(double));
  // } END MEMCPY VARIANT

  cout << "Using memcpy:            ";
  cout << punned_value_mc << endl;

  // BEGIN REINTERPRET_CAST VARIANT {
  pun_t  * punned_dest_rc = reinterpret_cast<pun_t *>(&double_value);
  punned_value_rc = *punned_dest_rc;
  // } END REINTERPRET_CAST VARIANT

  cout << "Using reinterprest_cast: ";
  cout << punned_value_rc << endl;

  // Bonus question:
  // What if we are punning an array of values?

  return EXIT_SUCCESS;
}

