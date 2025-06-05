// canCompleteCircuit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int canCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int total = 0;
    int current = 0;
    int start = 0;

    for (int i = 0; i < gasSize; ++i) {
        total += gas[i] - cost[i];
        current += gas[i] - cost[i];

        if (current < 0) {
            start = i + 1;
            current = 0;
        }
    }

    return total >= 0 ? start : -1;
}

int main()
{
    int gas[] = { 1,2,3,4,5 };
    int cost[] = { 3,4,5,1,2 };
    int gasSize = sizeof(gas) / sizeof(gas[0]);
    int costSize = sizeof(cost) / sizeof(cost[0]);

    int result = canCircuit(gas, gasSize, cost, costSize);
    std::cout << "Starting point: " << result << std::endl;

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
