// MeanAndModeProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    float n, sum = 0, mode = 0, maxCount = 0;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Invalid number of elements." << std::endl;
        return 1;
    }

    float* arr = new float[n];
    std::cout << "Enter the elements: ";

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        sum += arr[i];
    }

    // Calculate mean
    double mean = static_cast<double>(sum) / n;

    // Calculate mode
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }

    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Mode: " << mode << std::endl;

    delete[] arr;
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
