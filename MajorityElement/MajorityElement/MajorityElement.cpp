// MajorityElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

int majorityElement(std::vector<int>& nums) {
    int count = 0, candidate = 0;
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

int majorityElement(std::vector<int>& nums, int start, int end) {
    if (start == end) return nums[start];
    std::map<int, int,()> uniqueElements;

    int count = 0, candidate = 0;
    for (int i = start; i <= end; ++i) {
        uniqueElements[nums[i]]++;
    }
    for
    return candidate;
}

int main()
{
    std::vector<int> nums = { 2,1,2,1,2,1,2,1,2,1,3,2 }; 
    int result = majorityElement(nums);
    std::cout << "The majority element is: " << result << std::endl;
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
