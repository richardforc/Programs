// CPP_v14Features.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Auto Keyword
void autoKeywordExample()
{
    auto x = 42;
    auto y = 3.14;
    auto str = "Hello, Good Morning!!";
    std::cout << "X: " << x << "\n"
        << "Y: " << y << "\n"
        << "String: " << str << "\n";
}

// Range-based for loop

void RangeBasedForLoopExample()
{
    vector<int> numbers = { 1, 2, 3, 4, 5 };
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}
// Lambda expressions

void LambdaExpressionExample()
{
    auto add = [](int a, int b) {
        return a + b; 
    };
    auto sub = [](int a, int b) { 
        return a - b; 
    };
    auto mul = [](int a, int b) { 
        return a * b; 
    };
    auto div = [](int a, int b) { 
        return a / b; 
    };

    std::cout << "Sum: " << add(5, 3) << "\n";
    cout << "Subtraction: " << sub(5, 3) << "\n";
    cout << "Multiplication: " << mul(5, 4) << "\n";
    cout << "Division: " << div(6, 3) << "\n";
}

// Smart pointers
void SmartpointersExample()
{
    std::unique_ptr<int> ptr1(new int(10));
    std::shared_ptr<int> ptr2 = std::make_shared<int>(20);
    std::weak_ptr<int> weakPtr = ptr2;

    std::cout << "Unique Pointer Value: " << *ptr1 << "\n";
    std::cout << "Shared Pointer Value: " << *ptr2 << "\n";
    if (auto sharedFromWeak = weakPtr.lock()) {
        std::cout << "Weak Pointer Value: " << *sharedFromWeak << "\n";
    }
    else {
        std::cout << "Weak Pointer is expired.\n";
    }
}

// Move semantics
    void MoveSemanticsExample()
    {
        std::vector<int> vec1 = { 1, 2, 3, 4, 5 };
        std::vector<int> vec2 = std::move(vec1); // Move vec1 to vec2

        std::cout << "Moved Vector: ";
        for (const auto& num : vec2) {
            std::cout << num << " ";
        }   
        std::cout << "\n";
    }

// nullptr
    void nullptrExample()
    {
        int* ptr = nullptr; // Using nullptr instead of NULL
        if (ptr == nullptr) {
            std::cout << "Pointer is null.\n";
        }
        else {
            std::cout << "Pointer is not null.\n";
        }
    }

// constexpr
    constexpr int square(int x) { 
        return x * x; 
    }
    void constexprExample()
    {        
        constexpr int result = square(5);
        std::cout << "Square of 5 is: " << result << "\n";
    }

int main()
{
    std::cout << "C++14 Features Demonstration\n";

    // Auto Keyword Example
    autoKeywordExample();

    // Range-based for loop Example
    RangeBasedForLoopExample();
    

    // Lambda Expressions Example
    LambdaExpressionExample();

    // Smart Pointers Example
    SmartpointersExample();

    // Move Semantics Example
    MoveSemanticsExample();

    // nullptr Example
    nullptrExample();

    // constexpr Example
    constexprExample();

    //std::abort();
    //std::abs()
    //double res = std::acos(30); //cosine of the given value.
    std::acosh(30); //hyperbolic cosine of the given value.
    std::asinh(30); //hyperbolic sine of the given value.
    std::atanh(30); //hyperbolic tangent of the given value.
    int x = 10;
    std::addressof<int>(x); //returns the address of the given value.
    alignas(8) int arr[16] = { 1, 2, 3, 4, 5 };
    void* ptr = arr;
    size_t size = sizeof(arr);
    std::align(8, 16, ptr, size); //aligns the given value to the specified alignment.
    std::advance(ptr, 2); //advances the pointer by the specified number of elements.
    std::asctime(std::localtime(nullptr)); //returns the current time in the local time zone.
    std::atomic<int> atomicInt(0); //atomic integer
    atomicInt.fetch_add(1); //atomically adds 1 to the integer.
    std::atomic_thread_fence(std::memory_order_seq_cst); //creates a memory fence to ensure memory ordering.    
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
