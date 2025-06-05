// TimeConvertion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>


using namespace std;

vector<int> parseTime(string s)
{
    string sTime(s);
    vector<int> vTime;

    string::size_type start = 0, end = 0; //= sTime.find(":");
    while ((end = sTime.find(":", start)) != sTime.npos)
    {
        vTime.push_back(stoi(sTime.substr(start, end)));
        start = end + 1;
    }
    vTime.push_back(stoi(sTime.substr(start)));

    return vTime;
}

string timeConversion(string s) {
    ostringstream ssHr, ssMin, ssSec, ssTime;
    string sAmPm;
    //Get Morning or Evening

    string::size_type posAmPm = s.find("PM");
    if (posAmPm == s.npos)
    {
        posAmPm = s.find("AM");
    }

    sAmPm = s.substr(posAmPm);


    cout << "Parsing..." << endl;
    vector<int> vTime = parseTime(s);
    cout << "Done parsing..." << endl;

    if (sAmPm == "PM")
    {
        if (vTime[0] != 12)
        {
            vTime[0] += 12;
        }
    }
    else if (sAmPm == "AM")
    {
        if (vTime[0] == 12)
        {
            vTime[0] = 0;
        }
    }

    ssHr.fill('0');
    ssHr << std::setw(2) << vTime[0];

    cout << ssHr.str() << endl;

    ssMin.fill('0');
    ssMin << std::setw(2) << vTime[1];

    cout << ssMin.str() << endl;

    ssSec.fill('0');
    ssSec << std::setw(2) << vTime[2];

    cout << ssSec.str() << endl;

    ssTime << ssHr.str() << ":" << ssMin.str() << ":" << ssSec.str();

    return ssTime.str();
}

int main()
{
    ofstream fout("OUTPUT_PATH");

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";
    cout << result << endl;

    fout.close();

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
