// PlayersProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nsize;
    cin >> nsize;

    vector<int> players(nsize);
    for (int i = 0; i < nsize; i++)
    {
        cin >> players[i];
    }

    int prizeMoney = 0;

    while (players.size() > 1)
    {
    
        vector<int>::iterator minIt = min_element(players.begin(), players.end());
        vector<int>::iterator maxIt = max_element(players.begin(), players.end());
        int minValue = *minIt;
        int maxValue = *maxIt;
        int diff = maxValue - minValue;

        prizeMoney += diff;

        vector<int>::iterator it = players.erase(maxIt);
        
        if (diff > 0)
        {
            players.push_back(diff);
        }
    }

    cout << prizeMoney << endl;
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
