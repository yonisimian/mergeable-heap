#include <gtest/gtest.h>
#include "lazy.h"

// g++ -std=c++2b -o test test.cc -lgtest -lpthread

using Heap = LazyBinomialHeap<int>;

TEST(HeapTest, Insert)
{
  Heap h{};
  h.insert(10);
  h.insert(5);
  h.insert(15);
  ASSERT_EQ(h.minimum(), 5);
}

TEST(HeapTest, ExtractMin)
{
  Heap h{};
  h.insert(10);
  h.insert(5);
  h.insert(15);
  ASSERT_EQ(h.extract_min(), 5);
  ASSERT_EQ(h.extract_min(), 10);
  ASSERT_EQ(h.extract_min(), 15);
  ASSERT_EQ(h.extract_min(), std::nullopt);
}

TEST(HeapTest, Merge)
{
  Heap h1{};
  h1.insert(10);
  h1.insert(5);
  Heap h2{};
  h2.insert(15);
  h2.insert(20);
  h1.merge(h2);
  ASSERT_EQ(h1.minimum(), 5);
  ASSERT_EQ(h1.extract_min(), 5);
  ASSERT_EQ(h1.extract_min(), 10);
  ASSERT_EQ(h1.extract_min(), 15);
  ASSERT_EQ(h1.extract_min(), 20);
  ASSERT_EQ(h1.extract_min(), std::nullopt);
}

TEST(HeapTest, EmptyHeap)
{
  Heap h{};
  ASSERT_EQ(h.minimum(), std::nullopt);
  ASSERT_EQ(h.extract_min(), std::nullopt);
}

TEST(HeapTest, LargeHeap)
{
  Heap h{};
  for (int i = 1000; i > 0; --i)
  {
    h.insert(i);
  }
  ASSERT_EQ(h.minimum(), 1);
  ASSERT_EQ(h.extract_min(), 1);
  ASSERT_EQ(h.extract_min(), 2);
  ASSERT_EQ(h.extract_min(), 3);
  ASSERT_EQ(h.extract_min(), 4);
}

TEST(HeapTest, MergeEmpty)
{
  Heap h1{};
  Heap h2{};
  h1.merge(h2);
  ASSERT_EQ(h1.minimum(), std::nullopt);
  ASSERT_EQ(h1.extract_min(), std::nullopt);
}

TEST(HeapTest, ComplexTest)
{
  Heap h1{};
  h1.insert(10);
  h1.insert(5);
  h1.insert(15);
  h1.insert(20);
  h1.insert(25);
  h1.insert(30);
  h1.insert(35);
  h1.insert(40);
  h1.insert(45);
  h1.insert(50);
  ASSERT_EQ(h1.minimum(), 5);
  ASSERT_EQ(h1.extract_min(), 5);
  ASSERT_EQ(h1.extract_min(), 10);

  Heap h2{};
  h2.insert(1);
  h2.insert(2);
  h2.insert(3);
  h2.insert(4);
  h2.insert(15);
  h2.insert(6);
  h2.insert(7);
  h2.insert(18);
  h2.insert(9);
  h2.insert(10);
  ASSERT_EQ(h2.minimum(), 1);
  ASSERT_EQ(h2.extract_min(), 1);
  ASSERT_EQ(h2.extract_min(), 2);

  h1.merge(h2);

  ASSERT_EQ(h1.minimum(), 3);
  ASSERT_EQ(h1.extract_min(), 3);
  ASSERT_EQ(h1.extract_min(), 4);
  ASSERT_EQ(h1.extract_min(), 6);
  ASSERT_EQ(h1.extract_min(), 7);
  ASSERT_EQ(h1.extract_min(), 9);
  ASSERT_EQ(h1.extract_min(), 10);
  ASSERT_EQ(h1.extract_min(), 15);
  ASSERT_EQ(h1.extract_min(), 15);
  ASSERT_EQ(h1.extract_min(), 18);
  ASSERT_EQ(h1.extract_min(), 20);
  ASSERT_EQ(h1.extract_min(), 25);
  ASSERT_EQ(h1.extract_min(), 30);
  ASSERT_EQ(h1.extract_min(), 35);
  ASSERT_EQ(h1.extract_min(), 40);
  ASSERT_EQ(h1.extract_min(), 45);
  ASSERT_EQ(h1.extract_min(), 50);
  ASSERT_EQ(h1.extract_min(), std::nullopt);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}