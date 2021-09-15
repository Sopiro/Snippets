#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> split(string s)
{
    vector<string> tokens;
    int idx = 0;

    while ((idx = s.find(" ")) != string::npos)
    {
        tokens.push_back(s.substr(0, idx));
        s.erase(0, idx + 1);
    }
    tokens.push_back(s);

    return tokens;
}

string join(vector<string> sv, string delimiter)
{
    string res;

    for(auto& it = sv.begin(); it != sv.end()-1; it++)
        res += *it + " ";

    return res + sv.back();
}
