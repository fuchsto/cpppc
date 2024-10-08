#ifndef CPPPC__A06__ARRAY_EXPR_H__INCLUDED
#define CPPPC__A06__ARRAY_EXPR_H__INCLUDED

#include "index_sequence.h"


namespace ce {

namespace detail {
  template <
    std::size_t    NDrop,
    class          ValueT,
    std::size_t    NElem,
    std::size_t... Is >
  constexpr std::array<ValueT, (NDrop > NElem) ? 0 : NElem - NDrop >
  drop_impl(
    const std::array<ValueT, NElem> & values,
    ce::index_sequence<Is...>) {
    return {{ std::get<NDrop + Is>(values)... }};
  }
} // namespace detail

/**
 * Drops \c d elements from a given sequence of \c N elements with indices
 * \c (0..d..N).
 */
template <
  std::size_t   NDrop,
  class         ValueT,
  std::size_t   NElem >
constexpr std::array<ValueT, (NDrop > NElem) ? 0 : NElem - NDrop >
drop(
  const std::array<ValueT, NElem> & values) {
  return detail::drop_impl<NDrop, ValueT, NElem>(
           values,
           ce::make_index_sequence<
             (NDrop > NElem) ? 0 : NElem - NDrop
           >());
}

// -------------------------------------------------------------------------
// tail = drop<1>
// -------------------------------------------------------------------------

/**
 * Tail of a sequence.
 */
template <
  class         ValueT,
  std::size_t   NElem >
constexpr auto
tail(
  const std::array<ValueT, NElem> & values)
->  decltype(drop<1>(values)) {
  return drop<1>(values);
}

// -------------------------------------------------------------------------
// take
// -------------------------------------------------------------------------

namespace detail {
  template <
    std::size_t    NTake,
    class          ValueT,
    std::size_t    NElem,
    std::size_t... Is >
  constexpr std::array<ValueT, (NTake > NElem) ? NElem : NTake >
  take_impl(
    const std::array<ValueT, NElem> & values,
    ce::index_sequence<Is...>) {
    return {{ std::get<Is>(values)... }};
  }
} // namespace detail

/**
 * Returns sequence of first \c t elements from a given sequence of size
 * \c N with indices \c (0..t..N).
 */
template <
  std::size_t   NTake,
  class         ValueT,
  std::size_t   NElem >
constexpr std::array<ValueT, (NTake > NElem) ? NElem : NTake >
take(
  const std::array<ValueT, NElem> & values) {
  return detail::take_impl<NTake, ValueT, NElem>(
           values,
           ce::make_index_sequence<
             (NTake > NElem) ? NElem : NTake
           >());
}

// -------------------------------------------------------------------------
// head = take<1>
// -------------------------------------------------------------------------

/**
 * Head of a sequence.
 */
template <
  class         ValueT,
  std::size_t   NElem >
constexpr auto
head(
  const std::array<ValueT, NElem> & values)
->  decltype(take<1>(values)) {
  return take<1>(values);
}

// -------------------------------------------------------------------------
// split
// -------------------------------------------------------------------------

template <
  class         ValueT,
  std::size_t   NElemLeft,
  std::size_t   NElemRight >
class split
{
  constexpr static std::size_t NElem = NElemLeft + NElemRight;
  const std::array<ValueT, NElem> _values;

public:
  constexpr split(
    const std::initializer_list<ValueT> & values)
    : _values(values)
  { }

  constexpr split(
    const std::array<ValueT, NElem> & values)
    : _values(values)
  { }

  constexpr std::array<ValueT, NElemLeft> left() const {
    return take<NElemLeft, ValueT, NElem>(_values);
  }

  constexpr std::array<ValueT, NElemRight> right() const {
    return drop<NElemLeft, ValueT, NElem>(_values);
  }
};

// -------------------------------------------------------------------------
// append
// -------------------------------------------------------------------------

namespace detail {
  template <
    class          ValueT,
    std::size_t    NElemLeft,
    std::size_t    NElemRight,
    std::size_t... LIs,
    std::size_t... RIs >
  constexpr std::array<ValueT, NElemLeft + NElemRight>
  append_impl(
    const std::array<ValueT, NElemLeft>  & left,
    const std::array<ValueT, NElemRight> & right,
    ce::index_sequence<LIs...>,
    ce::index_sequence<RIs...>) {
    return {
             ( std::get<LIs>(left)  )... ,
             ( std::get<RIs>(right) )...
           };
  }
} // namespace detail

/**
 * Concatenates two lists.
 */
template <
  class          ValueT,
  std::size_t    NElemLeft,
  std::size_t    NElemRight >
constexpr std::array<ValueT, NElemLeft + NElemRight>
append(
  const std::array<ValueT, NElemLeft>  & left,
  const std::array<ValueT, NElemRight> & right) {
  return detail::append_impl(
           left,
           right,
           ce::make_index_sequence<NElemLeft>(),
           ce::make_index_sequence<NElemRight>());
}

/**
 * Appends element to end of list.
 */
template <
  class          ValueT,
  std::size_t    NElemLeft >
constexpr std::array<ValueT, NElemLeft + 1>
append(
  const std::array<ValueT, NElemLeft>  & left,
  const ValueT                         & elem) {
  return detail::append_impl(
           left,
           std::array<ValueT, 1>({ elem }),
           ce::make_index_sequence<NElemLeft>(),
           ce::make_index_sequence<1>());
}

// -------------------------------------------------------------------------
// reverse
// -------------------------------------------------------------------------

/**
 * Reverse elements of a sequence
 */
template <
  class          ValueT,
  std::size_t    NElem >
constexpr std::array<ValueT, NElem>
reverse(
  const std::array<ValueT, NElem> & values) {
  //
  // NOTE:
  //
  // This is elegant, correct, of high didactic value and does
  // not scale well.
  // Should be implemented using index from parameter pack like
  //
  //   { (std::get<NElem - I>(values)... }
  //
  return (NElem > 1
          ? ( ce::append(
                ce::reverse(
                  ce::tail(values)),
                ce::head(values)) )
          : values);
}

// -------------------------------------------------------------------------
// replace_nth
// -------------------------------------------------------------------------

/**
 * Replaces element at specified index in given sequence.
 */
template <
  std::size_t    IElem,
  class          ValueT,
  std::size_t    NElem >
constexpr std::array<ValueT, NElem>
replace_nth(
  const ValueT                     & elem,
  const std::array<ValueT, NElem>  & values) {
  //
  // Note that std::array::operator[] is not constexpr in C++11
  // but std::get<Idx>(std::array) is.
  //
  // index: [ 0, 1, ..., i-1 ] : [   i  ] : [ i+1, i+2, ... ]
  // value: [  <unchanged>   ] : [ elem ] : [  <unchanged>  ]
  //
  return ce::append(
           ce::append(
             ce::take<IElem>(values),
             elem),
           ce::drop<IElem + 1>(values)
         );
}

} // namespace ce

#endif // CPPPC__A06__ARRAY_EXPR_H__INCLUDED