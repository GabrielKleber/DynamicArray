# DynamicArray

A lightweight implementation of a generic dynamic array in **C++**, developed from scratch without using `std::vector` or any other container from the C++ Standard Library.

This project was created as a programming challenge to better understand how dynamic arrays work internally, including memory allocation, capacity management, and generic programming using templates.

## Features

- ✅ Generic implementation using C++ templates
- ✅ Dynamic memory allocation on the heap
- ✅ Automatic capacity growth (doubles when full)
- ✅ Automatic capacity shrinking when appropriate
- ✅ Manual `shrinkToFit()`
- ✅ Random access with `get()`
- ✅ Element replacement without reallocation
- ✅ Insert and remove at any position
- ✅ Error handling through `ArrayError`
- ✅ Iterator support with `begin()` and `end()`
- ✅ Compatible with primitive types and custom structures
- ✅ Automatic memory cleanup through the destructor

---

## API

| Method | Description |
|---------|-------------|
| `push(value)` | Adds an element to the end of the array |
| `pop()` | Removes and returns the last element |
| `insert(value, index)` | Inserts an element at a given position |
| `remove(index)` | Removes and returns the element at the given position |
| `get(index)` | Returns the element at the given position |
| `replace(index, value)` | Replaces an existing element |
| `clear()` | Removes all elements while preserving capacity |
| `shrinkToFit()` | Releases unused memory |
| `size()` | Returns the current number of elements |
| `capacity()` | Returns the allocated capacity |
| `isEmpty()` | Returns whether the array is empty |
| `begin()` / `end()` | Provides iterator support |

---

## Example

```cpp
#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> numbers;

    numbers.push(10);
    numbers.push(20);
    numbers.push(30);

    numbers.insert(99, 1);

    numbers.remove(2);

    numbers.replace(0, 100);

    numbers.print();

    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << '\n';
}
```

Output:

```text
100, 99, 30
Size: 3
Capacity: 4
```

---

## Error Handling

Operations return a `Result<T>` structure containing both the returned value (when applicable) and an error code.

```cpp
auto result = numbers.pop();

if (result.error == ArrayError::OK)
{
    std::cout << result.value;
}
```

Available error codes:

```cpp
enum class ArrayError
{
    OK,
    OUT_OF_BOUNDS,
    EMPTY_ARRAY,
    ALLOCATION_ERROR
};
```

---

## Benchmarks

A benchmark program is included to compare this implementation against `std::vector`.

The following operations are measured:

- Push
- Pop
- Insert
- Remove

Example output:

```text
========== DynamicArray Benchmark ==========

DynamicArray Push:          17.284 ms
std::vector Push:           15.923 ms

DynamicArray Pop:            9.842 ms
std::vector Pop:             0.931 ms

DynamicArray Insert:        52.317 ms
std::vector Insert:         48.129 ms

DynamicArray Remove:        46.705 ms
std::vector Remove:         42.688 ms
```

> **Note:** The benchmark results may vary depending on the compiler, optimization level, hardware, and operating system.

---

## Project Structure

```
.
├── Array.hpp
├── main.cpp
├── benchmark.cpp
└── README.md
```

---

## Learning Objectives

This project was developed to practice:

- Dynamic memory management (`new[]` / `delete[]`)
- Generic programming with templates
- Dynamic array implementation
- Time complexity analysis
- Memory growth strategies
- Manual resource management (RAII)
- Benchmarking and performance analysis

---

## Complexity

| Operation | Time Complexity |
|-----------|-----------------|
| Push | O(1) amortized |
| Pop | O(1)\* |
| Get | O(1) |
| Replace | O(1) |
| Insert | O(n) |
| Remove | O(n) |
| ShrinkToFit | O(n) |

\* In this implementation, `pop()` may reallocate memory when shrinking the internal capacity, making some calls O(n).

---

## License

This project is available under the MIT License.
