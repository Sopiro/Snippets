#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int _binarySearch(vector<int>& v, int value, int left, int right)
{
    int mid = (left + right) / 2;

    if (left == right)
    {
        if (v[mid] == value)
            return mid;
        else
            return -1;
    }

    if (v[mid] == value)
        return mid;
    else if (v[mid] < value)
        return _binarySearch(v, value, mid + 1, right);
    else if (v[mid] > value)
        return _binarySearch(v, value, left, mid - 1);
}

int binarySearch(vector<int> v, int value)
{
    return _binarySearch(v, value, 0, v.size() - 1);
}