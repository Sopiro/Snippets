#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int _quick_select(vector<int> v, int n, int left, int right)
{
    int mid = (right + left) / 2;
    int pivot = v[mid];

    std::swap(v[(right + left) / 2], v[right]);

    int lp = left;
    int rp = right - 1;

    while (rp >= lp)
    {
        while (v[lp] < pivot)
            lp++;
        while (v[rp] >= pivot)
            rp--;

        if (lp > rp)
            break;
        else
            std::swap(v[lp], v[rp]);
    }

    std::swap(v[lp], v[right]);

    // cout << mid << "[" << pivot << "] " << join(v, " ") << endl;

    if (lp == (n - 1))
        return v[lp];
    else if (lp < n - 1)
        return _quick_select(v, n, lp + 1, right);
    else
        return _quick_select(v, n, left, rp);
}

// Find the n-th smallist number in unsorted array
int quick_select(vector<int> &v, int n)
{
    srand(time(NULL));

    if (n < 1)
        n = 1;
    if (n > v.size())
        n = v.size();

    return _quick_select(v, n, 0, v.size() - 1);
}

int _binarySearch(vector<int> &v, int value, int left, int right)
{
    int mid = (left + right) / 2;

    if (left == right)
        return v[mid] == value ? mid : -1;

    return v[mid] == value ? mid : v[mid] < value ? _binarySearch(v, value, mid + 1, right)
                                                  : _binarySearch(v, value, left, mid - 1);
}

int binarySearch(vector<int> &v, int value)
{
    return _binarySearch(v, value, 0, v.size() - 1);
}