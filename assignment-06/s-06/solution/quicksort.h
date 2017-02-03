#ifndef MIDTERM_ASSIGNMENT_QUICKSORT_H
#define MIDTERM_ASSIGNMENT_QUICKSORT_H

#include "array_expr.h"

namespace ce {
    namespace detail {
        template<
                class ValueT,
                std::size_t NElem>
        const struct partition_result {
            const std::array<ValueT, NElem> values;
            const std::size_t middle;
        };

        template<
                class ValueT,
                class UnaryPredicate,
                std::size_t TrueElem = 0,
                std::size_t FalseElem = 0>
        constexpr partition_result<ValueT, TrueElem + FalseElem>
        partition_acc(
                const std::array<ValueT, 0> &values,
                UnaryPredicate predicate,
                const std::array<ValueT, TrueElem> &true_values = ce::empty<ValueT>(),
                const std::array<ValueT, FalseElem> &false_values = ce::empty<ValueT>()
        ) {
            return {ce::append(true_values, false_values), TrueElem};
        };

        template<
                class ValueT,
                std::size_t NElem,
                class UnaryPredicate,
                std::size_t TrueElem = 0,
                std::size_t FalseElem = 0>
        constexpr partition_result<ValueT, NElem + TrueElem + FalseElem>
        partition_acc(
                const std::array<ValueT, NElem> &values,
                UnaryPredicate predicate,
                const std::array<ValueT, TrueElem> &true_values = ce::empty<ValueT>(),
                const std::array<ValueT, FalseElem> &false_values = ce::empty<ValueT>()
        ) {
            const auto head = values.at(0);
            const auto tail = ce::tail(values);
            return predicate(head)
                   ? partition_acc(tail,
                                   predicate,
                                   ce::append(true_values, head),
                                   false_values)
                   : partition_acc(tail,
                                   predicate,
                                   true_values,
                                   ce::append(false_values, head));
        };

        template<
                class ValueT,
                std::size_t NElem,
                class UnaryPredicate>
        constexpr partition_result<ValueT, NElem>
        partition(
                const std::array<ValueT, NElem> &values,
                const std::size_t left,
                const std::size_t right,
                UnaryPredicate predicate
        ) {
            return {values, left};
        };

        template<
                class ValueT,
                std::size_t NElem>
        constexpr std::array<ValueT, NElem>
        quicksort_impl(
                const std::array<ValueT, NElem> &values,
                const std::size_t left_index,
                const std::size_t right_index
        ) {
            const auto left = values.at(left_index);
            const auto right = values.at(right_index);
            if (left == right) return values;
            const auto pivot = NElem / 2;
            const auto less_partition =
                    partition(values, left_index, right_index,
                              [pivot](const auto &em) { return em < pivot; });
            const auto middle_left_index = less_partition.middle;
            const auto greater_parition =
                    partition(less_partition.values,
                              middle_left_index,
                              right_index,
                              [pivot](const auto &em) { return !(pivot < em); });
            const auto middle_right_index = greater_parition.middle;
            return quicksort_impl(
                    quicksort_impl(greater_parition.values,
                                   left_index, middle_left_index),
                    middle_right_index, right_index
            );
        }
    } // namespace detail

    /**
     * Reverse elements of a sequence
     */
    template<
            class ValueT,
            std::size_t NElem>
    constexpr std::array<ValueT, NElem>
    quicksort(const std::array<ValueT, NElem> &values) {
        return NElem <= 1
               ? values
               : detail::quicksort_impl(values, 0, NElem - 1);
    }
} // namespace ce


#endif //MIDTERM_ASSIGNMENT_QUICKSORT_H
