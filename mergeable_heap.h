#ifndef MERGEABLE_HEAP_H
#define MERGEABLE_HEAP_H

#include <optional>

/**
 * @class MergeableHeap
 *
 * @brief A constexpr-friendly interface for a mergeable heap data structure.
 *
 * @details A mergeable heap is a type of heap that supports the following operations:
 * 1. MAKE-HEAP creates a new (empty) heap.
 * 2. INSERT inserts a new element into the heap.
 * 3. MINIMUM returns the element with the minimum key in the heap.
 * 4. EXTRACT-MIN removes and returns the element with the minimum key in the heap.
 * 5. UNION merges two heaps into a single heap.
 *
 * @tparam T The type of the elements stored in the heap. `T` must be movable, as it is
 * moved into the heap in the insert method.
 */
template <typename T>
class MergeableHeap
{
public:
  /**
   * Constructs a new empty heap.
   */
  constexpr MergeableHeap() = default;

  /**
   * Destroys the heap.
   */
  constexpr virtual ~MergeableHeap() = default;

  /**
   * @brief Deleted special member functions.
   *
   * `MergeableHeap` objects should not be copied or moved.
   */
  constexpr MergeableHeap(const MergeableHeap &) = delete;
  constexpr MergeableHeap &operator=(const MergeableHeap &) = delete;
  constexpr MergeableHeap(MergeableHeap &&) = delete;
  constexpr MergeableHeap &operator=(MergeableHeap &&) = delete;

  /**
   * Inserts a key into the heap.
   */
  constexpr virtual void insert(T key) = 0;

  /**
   * Returns the minimum key in the heap.
   */
  constexpr virtual std::optional<std::reference_wrapper<const T>> minimum() const = 0;

  /**
   * Removes and returns the minimum key in the heap.
   */
  constexpr virtual std::optional<T> extract_min() = 0;

  /**
   * Merges another heap into this heap.
   */
  constexpr virtual void merge(MergeableHeap<T> &other) = 0;
};

#endif // MERGEABLE_HEAP_H