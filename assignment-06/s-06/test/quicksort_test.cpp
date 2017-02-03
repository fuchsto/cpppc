#include "quicksort_test.h"

#include <solution/quicksort.h>

constexpr bool is_negative(const std::size_t &value) {
    return value < 0;
}

TEST_F(QuicksortTest, EmptySequence) {
    LOG_MESSAGE("QuicksortTest.EmptySequence");
    EXPECT_EQ(0, ce::empty<int>().size());
}

TEST_F(QuicksortTest, partition_acc) {
    LOG_MESSAGE("QuicksortTest.partition_acc");
    {
        const auto values = ce::empty<int>();
        const auto result = ce::detail::partition_acc(values, is_negative);
        EXPECT_EQ(0, result.middle);
        EXPECT_EQ(ce::empty<int>(), result.values);
    }
    {
        const std::array<int, 1> values {-1};
        const auto result = ce::detail::partition_acc(values, is_negative);
        EXPECT_EQ(1, result.middle);
        EXPECT_EQ(values, result.values);
    }
}

TEST_F(QuicksortTest, Empty) {
    LOG_MESSAGE("QuicksortTest.Empty");
    const std::array<int, 0> unsorted {};
    const std::array<int, 0> sorted {};
    EXPECT_EQ(sorted, ce::quicksort(unsorted));
}

TEST_F(QuicksortTest, SingleElement) {
    LOG_MESSAGE("QuicksortTest.SingleElement");
    const std::array<int, 1> unsorted {1};
    const std::array<int, 1> sorted {1};
    EXPECT_EQ(sorted, ce::quicksort(unsorted));
}

TEST_F(QuicksortTest, TwoElements) {
    LOG_MESSAGE("QuicksortTest.TwoElements");
    const std::array<int, 2> unsorted {2, 1};
    const std::array<int, 2> sorted {1, 2};
    EXPECT_EQ(sorted, ce::quicksort(unsorted));
}

TEST_F(QuicksortTest, ThreeElements) {
    LOG_MESSAGE("QuicksortTest.ThreeElements");
    const std::array<int, 3> unsorted {2, 3, 1};
    const std::array<int, 3> sorted {1, 2, 3};
    EXPECT_EQ(sorted, ce::quicksort(unsorted));
}

TEST_F(QuicksortTest, QuicksortExample) {
    LOG_MESSAGE("QuicksortTest.QuicksortExample");
    const std::array<int, 9> unsorted {4, 1, 9, 8, 5, 6, 3, 7, 2};
    const std::array<int, 9> sorted {1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(sorted, ce::quicksort(unsorted));
}

