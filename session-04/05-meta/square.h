
// Talk by Peter Gottschling:
// https://www.youtube.com/watch?v=EkdfiHs78DY

template <typename T>
constexpr T square_ce(T val) { return x * x; }

// Q: Difference between these functions?

template <typename T>
T square(T val) { return x * x; }

// Q: Is there a difference?
//
//           long sq1 = square_ce(400);
// constexpr long sq2 = square_ce(400);
//
// Q: Is this allowed?
//
// int sq3 = square_ce(atoi(argv[0]));
