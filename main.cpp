#include <iostream>
#include <Array.hpp>

using namespace std;

int main()
{
    Array<int> numbers;

    std::cout << "=== DynamicArray Demo ===\n\n";

    // Push
    numbers.push(10);
    numbers.push(20);
    numbers.push(30);
    numbers.push(40);

    std::cout << "After push: ";
    numbers.print();

    // Insert
    numbers.insert(99, 1);

    std::cout << "After insert(99, 1): ";
    numbers.print();

    // Get
    auto value = numbers.get(2);

    if(value.error == ArrayError::OK)
    {
        std::cout << "\nElement at index 2: "
                  << value.value << '\n';
    }

    // Replace
    numbers.replace(2, 777);

    std::cout << "After replace(2, 777): ";
    numbers.print();

    // Remove
    auto removed = numbers.remove(3);

    if(removed.error == ArrayError::OK)
    {
        std::cout << "Removed value: "
                  << removed.value << '\n';
    }

    std::cout << "Current array: ";
    numbers.print();

    // Pop
    auto last = numbers.pop();

    if(last.error == ArrayError::OK)
    {
        std::cout << "Popped value: "
                  << last.value << '\n';
    }

    std::cout << "Current array: ";
    numbers.print();

    std::cout << "\nSize: "
              << numbers.size();

    std::cout << "\nCapacity: "
              << numbers.capacity();

    std::cout << "\nIs Empty: "
              << (numbers.isEmpty() ? "Yes" : "No")
              << "\n\n";

    // Range iteration
    std::cout << "Iterating with begin()/end(): ";

    for(auto p = numbers.begin(); p != numbers.end(); ++p)
    {
        std::cout << *p << ' ';
    }

    std::cout << '\n';

    // Clear
    numbers.clear();

    std::cout << "\nAfter clear():\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Is Empty: "
              << (numbers.isEmpty() ? "Yes" : "No")
              << '\n';

    return 0;
}
