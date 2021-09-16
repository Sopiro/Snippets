#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void bubble(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 1; j < v.size() - i; j++)
        {
            if (v[j - 1] > v[j])
            {
                swap(v[j - 1], v[j]);
            }
        }
    }
}
