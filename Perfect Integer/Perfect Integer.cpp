// Perfect Integer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


    /*
    * min(|a-b|, |a+b|) <= min(|a|, |b|)
    * max(|a-b|, |a+b|) >= max(|a|, |b|)
    *
    */
#include <iostream>
#include <vector>

using namespace std;

long perfectInteger (vector<int>& nums)
{
    int nPerfectPairs = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int a = nums[i];
            int b = nums[j];

            // Check if the pair (a, b) is a perfect integer pair
            if (std::min(std::abs(a - b), std::abs(a + b)) <= std::min(std::abs(a), std::abs(b)) &&
                std::max(std::abs(a - b), std::abs(a + b)) >= std::max(std::abs(a), std::abs(b)))
            {
                nPerfectPairs++;
            }
        }
    }
    return nPerfectPairs;
}

int main()
{
    vector<int> nums = { -8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25,-8, -9, 2, 5, 1,1,5,6,10,15, 26,12, 25 };

    long result = perfectInteger(nums);
    cout << "Number of perfect integer pairs: " << result << endl;
    std::cout << "Hello World!\n";
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
