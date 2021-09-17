#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void insertion(vector<int> &v, bool verbose)
{
    int ptr = 0;
    for (int i = 1; i < v.size(); i++, ptr++)
    {
        ptr = i - 1;
        int target = i;

        if (verbose)
            cout << "iteration " << i - 1 << ": ";

        while (ptr >= 0 && v[ptr] > v[target])
        {
            if (verbose)
                cout << "swap(" << ptr << "<->" << target << ") ";

            swap(v[ptr--], v[target--]);
        }
        if (verbose)
            cout << endl;
    }
}

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

void _quick(vector<int> &v, bool verbose = false)
{
}

void partition(vector<int> &v, int left, int right, bool verbose = false)
{
    int len = right - left + 1;

    if (len < 2)
        return;

    int pivot_ptr = left + (rand() % len);
    int pivot_val = v[pivot_ptr];

    if (verbose)
    {
        cout << "partitioning (" << left << " " << right << ") " << join(v) << endl;
        cout << "\tpivot value: " << pivot_val << endl;
    }

    swap(v[pivot_ptr], v[right]);

    if (verbose)
        cout << "\tpivot moved to back: " << join(v) << endl;

    int lp = left;
    int rp = right - 1;

    if (verbose)
        cout << "\tlp:" << lp << " rp:" << rp << endl;

    while (rp >= lp)
    {
        while (v[lp] < pivot_val && (rp >= lp))
            lp++;
        while (v[rp] >= pivot_val && (rp >= lp))
            rp--;

        if (verbose)
            cout << "\tlp:" << lp << " rp:" << rp << endl;
        if (lp > rp)
        {
            if (verbose)
                cout << "\tpartioning done" << endl;
            break;
        }
        else
        {
            if (verbose)
                cout << "\tswap (" << lp << " <-> " << rp << ") ";
            std::swap(v[lp], v[rp]);
            if (verbose)
                cout << join(v) << endl;
        }
    }

    std::swap(v[lp], v[right]);
    if (verbose)
    {
        cout << "\tpivot moved to correct: " << join(v) << endl;
        cout << "\t" << join(v) << endl;
    }

    partition(v, left, rp, verbose);
    partition(v, lp + 1, right, verbose);
}

void quick(vector<int> &v, bool verbose = false)
{
    srand(time(NULL));
    partition(v, 0, v.size() - 1, verbose);
}
