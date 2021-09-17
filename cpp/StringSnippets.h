#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<string> ssplit(string s, char delimiter)
{
    vector<string> res;
    stringstream ss(s);

    string line;
    while (getline(ss, line, delimiter))
        res.push_back(line);

    return res;
}

vector<string> ssplit_n(string s)
{
    vector<string> res;
    stringstream ss(s);

    string tmp;
    while (ss >> tmp)
        res.push_back(tmp);

    return res;
}

vector<string> split(string s, string delimiter)
{
    vector<string> tokens;
    int idx = 0;

    while ((idx = s.find(delimiter)) != string::npos)
    {
        string token = s.substr(0, idx);
        if (token.size() != 0)
            tokens.push_back(token);
        s.erase(0, idx + 1);
    }
    tokens.push_back(s);

    return tokens;
}

template <typename T>
string join(vector<T> sv, string delimiter)
{
    string res;

    for (auto it = sv.begin(); it != sv.end() - 1; it++)
        res += to_string(*it) + " ";

    return res + to_string(sv.back());
}

void replaceAll(string &s, string from, string to)
{
    size_t idx = 0;

    while ((idx = s.find(from, idx)) != string::npos)
    {
        s.replace(idx, from.size(), to);
    }
}

void _permutation(string s, vector<bool> done, string &data, int depth, unordered_set<string> &out)
{
    if (depth >= s.size())
        return;

    for (int i = 0; i < s.size(); i++)
    {
        if (!done[i])
        {
            data.push_back(s[i]);
            done[i] = true;

            // Print all possible permutation
            // cout << data << endl;
            out.insert(data);

            _permutation(s, done, data, depth + 1, out);
            done[i] = false;
            data.pop_back();
        }
    }
}

unordered_set<string> permutation(string s)
{
    vector<bool> done(s.size(), false);
    string data = "";
    unordered_set<string> uos;

    _permutation(s, done, data, 0, uos);

    return uos;
}

bool check_bracket(string s, char bracketType)
{
    char lb = 0;
    char rb = 0;

    switch (bracketType)
    {
    case '(':
    case ')':
        lb = '(';
        rb = ')';
        break;
    case '{':
    case '}':
        lb = '{';
        rb = '}';
        break;
    case '[':
    case ']':
        lb = '[';
        rb = ']';
        break;
    }

    int r = 0;

    for (auto &c : s)
    {
        if (r < 0)
            return false;

        if (c == rb)
            r--;
        else if (c == lb)
            r++;
    }

    return r == 0;
}