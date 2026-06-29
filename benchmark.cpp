#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <Array.hpp>

constexpr int PUSH_POP_SIZE = 1'000'000;
constexpr int INSERT_REMOVE_SIZE = 10'000;
constexpr int TEST_RUNS = 100;

using Clock = std::chrono::high_resolution_clock;
using Ms = std::chrono::duration<double, std::milli>;

void benchmarkArrayPush()
{
    double total = 0;

    for (int t = 0; t < TEST_RUNS; ++t)
    {
        Array<int> arr;

        auto start = Clock::now();

        for (int i = 0; i < PUSH_POP_SIZE; ++i)
            arr.push(i);

        auto end = Clock::now();

        total += Ms(end - start).count();
    }

    std::cout << std::left << std::setw(30)
              << "DynamicArray Push:"
              << std::fixed << std::setprecision(3)
              << total / TEST_RUNS << " ms\n";
}

void benchmarkVectorPush()
{
    double total = 0;

    for (int t = 0; t < TEST_RUNS; ++t)
    {
        std::vector<int> vec;

        auto start = Clock::now();

        for (int i = 0; i < PUSH_POP_SIZE; ++i)
            vec.push_back(i);

        auto end = Clock::now();

        total += Ms(end - start).count();
    }

    std::cout << std::left << std::setw(30)
              << "std::vector Push:"
              << std::fixed << std::setprecision(3)
              << total / TEST_RUNS << " ms\n";
}

void benchmarkArrayPop()
{
    double total = 0;

    for (int t = 0; t < TEST_RUNS; ++t)
    {
        Array<int> arr;

        for (int i = 0; i < PUSH_POP_SIZE; ++i)
            arr.push(i);

        auto start = Clock::now();

        while (!arr.isEmpty())
            arr.pop();

        auto end = Clock::now();

        total += Ms(end - start).count();
    }

    std::cout << std::left << std::setw(30)
              << "DynamicArray Pop:"
              << total / TEST_RUNS << " ms\n";
}

void benchmarkVectorPop()
{
    double total = 0;

    for (int t = 0; t < TEST_RUNS; ++t)
    {
        std::vector<int> vec;

        for (int i = 0; i < PUSH_POP_SIZE; ++i)
            vec.push_back(i);

        auto start = Clock::now();

        while (!vec.empty())
            vec.pop_back();

        auto end = Clock::now();

        total += Ms(end - start).count();
    }

    std::cout << std::left << std::setw(30)
              << "std::vector Pop:"
              << total / TEST_RUNS << " ms\n";
}

void benchmarkArrayInsert()
{
    double total = 0;

    for (int t = 0; t < TEST_RUNS; ++t)
    {
        Array<int> arr;

        auto start = Clock::now();

        for (int i = 0; i < INSERT_REMOVE_SIZE; ++i)
            arr.insert(i, 0);

        auto end = Clock::now();

        total += Ms(end - start).count();
    }

    std::cout << std::left << std::setw(30)
              << "DynamicArray Insert:"
              << total / TEST_RUNS << " ms\n";
}

void benchmarkVectorInsert()
{
    double total = 0;

    for (int t = 0; t < TEST_RUNS; ++t)
    {
        std::vector<int> vec;

        auto start = Clock::now();

        for (int i = 0; i < INSERT_REMOVE_SIZE; ++i)
            vec.insert(vec.begin(), i);

        auto end = Clock::now();

        total += Ms(end - start).count();
    }

    std::cout << std::left << std::setw(30)
              << "std::vector Insert:"
              << total / TEST_RUNS << " ms\n";
}

void benchmarkArrayRemove()
{
    double total = 0;

    for (int t = 0; t < TEST_RUNS; ++t)
    {
        Array<int> arr;

        for (int i = 0; i < INSERT_REMOVE_SIZE; ++i)
            arr.push(i);

        auto start = Clock::now();

        while (!arr.isEmpty())
            arr.remove(0);

        auto end = Clock::now();

        total += Ms(end - start).count();
    }

    std::cout << std::left << std::setw(30)
              << "DynamicArray Remove:"
              << total / TEST_RUNS << " ms\n";
}

void benchmarkVectorRemove()
{
    double total = 0;

    for (int t = 0; t < TEST_RUNS; ++t)
    {
        std::vector<int> vec;

        for (int i = 0; i < INSERT_REMOVE_SIZE; ++i)
            vec.push_back(i);

        auto start = Clock::now();

        while (!vec.empty())
            vec.erase(vec.begin());

        auto end = Clock::now();

        total += Ms(end - start).count();
    }

    std::cout << std::left << std::setw(30)
              << "std::vector Remove:"
              << total / TEST_RUNS << " ms\n";
}

int main()
{
    std::cout << "========== DynamicArray Benchmark ==========\n\n";

    benchmarkArrayPush();
    benchmarkVectorPush();

    std::cout << '\n';

    benchmarkArrayPop();
    benchmarkVectorPop();

    std::cout << '\n';

    benchmarkArrayInsert();
    benchmarkVectorInsert();

    std::cout << '\n';

    benchmarkArrayRemove();
    benchmarkVectorRemove();

    return 0;
}
