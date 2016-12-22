
template <long N>
struct fibonacci_tpl {
  static const long value = fibonacci_tpl<N-1>::value +
                            fibonacci_tpl<N-2>::value;
}

template <>
struct fibonacci_tpl<1> {
  static const long value = 1;
}

template <>
struct fibonacci_tpl<2> {
  static const long value = 1;
}


constexpr long fibonacci(long i) {
  return (i <= 1u) ? i : (fibonacci(i-1) + fibonacci(i-2));
}


int main(int argc, char * argv[])
{
  char int_values[fibonacci(6)] = { };

  constexpr long fib_9 = fibonacci(9);

  std::cout << sizeof(int_values) << std::endl;
  std::cout << fib_9              << std::endl;
  std::cout << fibonacci(argc)    << std::endl;

#if 0
  // Q: Why does this fail?
  std::cout << sizeof(std::array<char, fibonacci(argc)>) << '\n';

  // Q: Why does this fail and not fall back to run-time variant?
  constexpr long fib_arg = fibonacci(argc);
#endif
}

