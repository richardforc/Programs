// FindMinMaxSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
//#include <bits/stdc++.h>

using namespace std;

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !isspace(ch);
            })
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), s.end());
    return s;
}

vector<string> split(const string& str, string delimiter = " ") {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = str.find(delimiter, start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
    }
    tokens.push_back(str.substr(start));

    return tokens;
}

void MinMaxSum(vector<int> arr) {

    unsigned long nMin = 0, nMax = 0;
    unsigned long nTotal = 0;

    vector<int>::iterator iter1 = arr.begin();

    while (iter1 != arr.end())
    {
        nTotal += *iter1;
        iter1++;
    }

    vector<int>::iterator iter2 = arr.begin();
    nMin = nMax = nTotal - *iter2;
    iter2++;

    while (iter2 != arr.end())
    {
        int nRes = nTotal - *iter2;
        if (nRes < nMin)
        {
            nMin = nRes;
        }
        else {
            nMax = nRes;
        }
        iter2++;
    }

    cout << nMin << " " << nMax << endl;
}

int main()
{
    // Example of trimming space and tokenizing    
    string input;
    getline(cin, input);
    string str(input);
    string result = ltrim(str);
    result = rtrim(result);
    cout << result << endl;

    vector<string> tokens = split(result);
    vector<int> arr(5);
    for (vector<string>::iterator tokenIter = tokens.begin(); tokenIter != tokens.end(); tokenIter++ ) {
        cout << *tokenIter << endl;
        int value = stoi(*tokenIter);
        arr.push_back(value);
    }



    MinMaxSum(arr);
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
