# Overview

This project provides an implementation of the **mergeable heap** interface. The implementation uses the lazy binomial heap data structure, and is crafted with attention to detail and professionalism; for example, it leverage modern C++ features such as [compile-time heap allocations](http://wg21.link/P0784R1) and [constexpr virtual functions](https://wg21.link/P1064) to ensure efficiency and maintainability.

> The project is my submission to a [Data Structures](https://github.com/yonisimian-cs-degree/20407-Data-Structures-and-Introduction-to-Algorithms) university course assignment which I took in 2024 at The Open University of Israel.

## Mergeable Heaps

In computer science, a **mergeable heap** (also called a meldable heap) is an abstract data type that supports a merge operation. Mergeable heaps are particularly useful in applications where dynamic sets of elements need to be managed efficiently, such as in Dijkstra's algorithm.

Mergeable heaps support five main operations: MAKE-HEAP, INSERT, MINIMUM, EXTRACT-MIN, and UNION. The MINIMUM and EXTRACT-MIN operations can be symmetrically replaced with MAXIMUM and EXTRACT-MAX. The operations' time complexity are described in the [Documentation](#documentation) section.

The mergeable heap interface is declared in [mergeable_heap.h](https://github.com/yonisimian/mergeable-heap/blob/main/mergeable_heap.h).

## Implementation

My implementation of the mergeable heap interface is available via [lazy.h](https://github.com/yonisimian/mergeable-heap/blob/main/lazy.h).

The implementation has been carefully designed to utilize modern C++ features, ensuring both performance and code clarity.
In addition, the implementation has been tested with the tests found in [test.cc](https://github.com/yonisimian/mergeable-heap/blob/main/test.cc).

## Documentation

The code itself is thoroughly documented. In addition to the in-code comments, Doxygen-generated documentation is available via [docs.pdf](https://github.com/yonisimian/mergeable-heap/blob/main/docs.pdf).

Below is a complexity table that summarizes the performance characteristics of my implementation:

|  Operation  |  Time Complexity   |
|-------------|--------------------|
|  MAKE-HEAP  |        O(1)        |
|   INSERT    |        O(1)        |
|   MINIMUM   |        O(1)        |
| EXTRACT-MIN | O(log n) amortized |
|    UNION    |        O(1)        |

## Example

The file [example.cpp](https://github.com/yonisimian/mergeable-heap/blob/main/example.cpp) provides a concise example demonstrating the usage of the mergeable heap, as well as a proof of the implementation's efficiency.

By utilizing the mergeable heap in a `constexpr` context, all heap allocations and deallocations are performed at compile-time, resulting in optimized performance and reduced runtime overhead.

---

Yehonatan Simian, 2024 Ⓒ <yonisimian@gmail.com>
