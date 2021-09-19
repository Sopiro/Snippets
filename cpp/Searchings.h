#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int _binarySearch(vector<int> &v, int value, int left, int right)
{
    int mid = (left + right) / 2;

    if (left == right)
        return v[mid] == value ? mid : -1;

    return v[mid] == value ? mid : v[mid] < value ? _binarySearch(v, value, mid + 1, right)
                                                  : _binarySearch(v, value, left, mid - 1);
}

int binarySearch(vector<int> v, int value)
{
    return _binarySearch(v, value, 0, v.size() - 1);
}