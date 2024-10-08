#ifndef CPPPC__A06__FUNCTIONAL_EXPR_H__INCLUDED
#define CPPPC__A06__FUNCTIONAL_EXPR_H__INCLUDED

#include <functional>
#include <type_traits>

#include "index_sequence.h"

namespace ce {

template <typename T, typename... Ts>
struct are_integral
    : std::integral_constant<
        bool,
        std::is_integral<T>::value && are_integral<Ts...>::value> {};

template <typename T>
struct are_integral<T> : std::is_integral<T> { };

/**
 * Compile-time equivalent to `std::plus()`
 */
template <typename T>
constexpr T
plus(const T x, const T y) {
  return x + y;
}

/**
 * Compile-time equivalent to `std::minus()`
 */
template <typename T>
constexpr T
minus(const T x, const T y) {
  return x - y;
}

/**
 * Compile-time equivalent to `std::multiplies()`
 */
template <typename T>
constexpr T
multiplies(const T x, const T y) {
  return x * y;
}

/**
 * Compile-time equivalent to `std::divides()`
 */
template <typename T>
constexpr T
divides(const T x, const T y) {
  return x / y;
}

/**
 * Compile-time equivalent to `std::accumulate()`
 */
template <typename T,            ///< result type
          size_t   N,            ///< array length
          typename ReduceOp >    ///< binary reduce operation
constexpr T accumulate(
    const std::array<T, N> &arr, ///< array to accumulate
    const size_t first,          ///< start index for accumulation
    const size_t length,         ///< number of values to accumulate
    const T initialValue,        ///< initial accumulation value
    const ReduceOp & op          ///< binary operation
  ) {
  return (first < (first + length))
             ? op(arr[first],
                  ce::accumulate(
                    arr,
                    first  + 1,   length - 1,
                    initialValue, op))
             : initialValue;
}

/**
 * Compile-time equivalent to `std::inner_product()`.
 */
template <typename T,       ///< result type
          typename T_1,     ///< first array type
          size_t   N_1,     ///< size of first array
          typename T_2,     ///< second array type
          size_t   N_2,     ///< size of second array
          typename SumOp,   ///< summation operation type
          typename MulOp    ///< multiplication operation type
>
constexpr T inner_product(
    /// array to calculate inner product
    const std::array<T_1, N_1> & arr_1,
    /// start index in first array
    const size_t                 first_1,
    /// second array
    const std::array<T_2, N_2> & arr_2,
    /// start index in second array
    const size_t                 first_2,
    /// number of elements to use in both arrays
    const size_t                 length,
    /// summation initial value
    const T                      initialValue,
    /// summation operator
    const SumOp                & op_sum,
    /// multiplication operator
    const MulOp                & op_prod) {
  return (first_1 < (first_1 + length))
             ? op_sum(op_prod(
                        arr_1[first_1],
                        arr_2[first_2]),
                      ce::inner_product(
                        arr_1, first_1 + 1,
                        arr_2, first_2 + 1,
                        length - 1,
                        initialValue,
                        op_sum,
                        op_prod))
             : initialValue;
}

} // namespace ce

#endif // CPPPC__A06__FUNCTIONAL_EXPR_H__INCLUDED