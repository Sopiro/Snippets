#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void selection(vector<int> &v, bool verbose = false)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int ptr_min = i;

        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[ptr_min])
            {
                ptr_min = j;
            }
        }

        if (verbose)
        {
            cout << "iteration " << i + 1 << ": ";
            cout << "swap (" << i << " <-> " << ptr_min << ")" << endl;
        }

        swap(v[ptr_min], v[i]);
    }
}

void bubble(vector<int> &v, bool verbose = false)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << "bubbling ";
        for (int j = 1; j < v.size() - i; j++)
        {
            if (verbose)
                cout << "(" << j - 1 << ", " << j << ") ";

            if (v[j - 1] > v[j])
                swap(v[j - 1], v[j]);
        }
        cout << endl;
    }
}

void _merge(vector<int> &v, int left, int right, bool verbose = false)
{
    int mid = (left + right) / 2;

    if (verbose)
        cout << "Divided (" << left << " " << right << ")" << endl;

    if (left == right)
    {
        if (verbose)
            cout << "Return" << endl;
        return;
    }

    _merge(v, left, mid, verbose);
    _merge(v, mid + 1, right, verbose);

    if (verbose)
    {
        cout << "\t\tMerging  ";
        cout << "(" << left << " " << mid << ") + (" << mid + 1 << " " << right << ")" << endl;
    }

    int lp = left;
    int rp = mid + 1;

    vector<int> res;
    while (1)
    {
        if (lp > mid)
        {
            res.insert(res.end(), v.begin() + rp, v.end());
            break;
        }
        else if (rp > right)
        {
            res.insert(res.end(), v.begin() + lp, v.begin() + mid + 1);
            break;
        }

        if (v[lp] < v[rp])
        {
            res.push_back(v[lp]);
            lp++;
        }
        else if (v[lp] >= v[mid + 1])
        {
            res.push_back(v[rp]);
            rp++;
        }
    }

    std::copy(res.begin(), res.end(), v.begin() + left);
}

void merge(vector<int> &v, bool verbose = false)
{
    _merge(v, 0, v.size() - 1, verbose);
}
