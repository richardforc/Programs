// FindTheVirusApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
// There are N Applications and each application is represented by a number from 1 to N.
// The application is belongs to a group if its ID is neareset (floor) to the group ID.
// The group ID is calculated each time using the sum of all application IDs divided by 2.
// The neareset (floor) application ID will be removed from the list.


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int FindNearestAppID(vector<int> vAppID, int groupID)
{
    int nearestAppID = -1;
    int minDiff = INT_MAX;
    for (int i = 0; i < vAppID.size(); i++) {
        int diff = groupID - vAppID[i];
        if (diff >= 0 && diff < minDiff) {
            minDiff = diff;
            nearestAppID = vAppID[i];
        }
    }
    return nearestAppID;
}

int FindVirus(vector<int> vAppID)
{
    int groupID = 0, nTotal = 0;
    for (int i = 0; i < vAppID.size(); i++) {
        nTotal += vAppID[i];
    }
    int nearestAppID = 0;
    groupID = nTotal/2; // Calculate the group ID by dividing the sum by 2
    for (int i = 0; i < vAppID.size(); i++) {
        nearestAppID = FindNearestAppID(vAppID, groupID);
        vector<int>::iterator it = find(vAppID.begin(), vAppID.end(), nearestAppID);
        vAppID.erase(it);
        nTotal -= nearestAppID; // Update the total after removing the nearest app ID
        groupID = nTotal / 2; // Recalculate the group ID after removing the app ID

        cout << nearestAppID << " is part of the group with ID " << groupID << ". Removing this item" << endl;
    }
    int res = 0;
    if (vAppID.empty())
    {
        res = -1;
    }
    else
    {
        res = vAppID[0]; // Return the last remaining application ID
    }
    return res;
}
int main()
{
    int N;
    cout << "Enter the No. of Applications : ";
    cin >> N;

    vector<int> applications(N);
    for (int i = 0; i < N; i++) {
        cin >> applications[i];
    }

    int res = FindVirus(applications);
    cout << res << endl;

    _mm_pause();
    /*
    int start = 0, end = 0;
    while (input.substr(start).empty() == false) {
        end = input.find(" ", start);
        int number = stoi(input.substr(start, end));
        applications.push_back(number);
        start = end + 1;
        cout << "Application ID: " << number << endl;
    }*/
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
