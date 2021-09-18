#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <ctime>
#include <stack>

using namespace std;

void insertionSort(vector<int> &v, bool verbose)
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

void selectionSort(vector<int> &v, bool verbose = false)
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

void bubbleSort(vector<int> &v, bool verbose = false)
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

void _mergeSort(vector<int> &v, int left, int right, bool verbose = false)
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

    _mergeSort(v, left, mid, verbose);
    _mergeSort(v, mid + 1, right, verbose);

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

void mergeSort(vector<int> &v, bool verbose = false)
{
    _mergeSort(v, 0, v.size() - 1, verbose);
}

void _quickSort(vector<int> &v, int left, int right, bool verbose = false)
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
        while (v[lp] < pivot_val)
            lp++;
        while (v[rp] >= pivot_val)
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

    _quickSort(v, left, rp, verbose);
    _quickSort(v, lp + 1, right, verbose);
}

void quickSort(vector<int> &v, bool verbose = false)
{
    srand(time(NULL));
    _quickSort(v, 0, v.size() - 1, verbose);
}

void _quickSort_clean(vector<int> &v, int left, int right)
{
    if (right <= left)
        return;

    int pivot = v[(right + left) / 2];
    swap(v[(right + left) / 2], v[right]);

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
    _quickSort_clean(v, left, rp);
    _quickSort_clean(v, lp + 1, right);
}

void quickSort_clean(vector<int> &v)
{
    srand(time(NULL));
    _quickSort_clean(v, 0, v.size() - 1);
}

void _heapify(vector<int> &v, int start)
{
    int left_child = 2 * start + 1;
    int right_child = 2 * start + 2;

    // if this node has no children
    if (left_child >= v.size() && right_child >= v.size())
        return;

    int max_ptr = start;
    if (right_child < v.size() && v[right_child] > v[max_ptr])
        max_ptr = right_child;
    if (v[left_child] > v[max_ptr])
        max_ptr = left_child;

    if (max_ptr != start)
    {
        swap(v[start], v[max_ptr]);
        _heapify(v, max_ptr);
    }
}

void heapify(vector<int> &v)
{
    for (int ptr = v.size() / 2 - 1; ptr >= 0; ptr--)
        _heapify(v, ptr);
}

void insertHeap(vector<int> &v, int value)
{
    v.push_back(value);
    heapify(v);
}

int popHeap(vector<int> &v)
{
    int value = v.front();
    v[0] = v.back();
    v.pop_back();

    _heapify(v, 0);

    return value;
}

bool _isHeap(vector<int> &v, int start)
{
    int left_child = 2 * start + 1;
    int right_child = 2 * start + 2;

    // if this node has no children
    if (left_child >= v.size() && right_child >= v.size())
        return true;

    int max_ptr = start;
    if (right_child < v.size() && v[right_child] > v[max_ptr])
        max_ptr = right_child;
    if (v[left_child] > v[max_ptr])
        max_ptr = left_child;

    if (max_ptr != start)
        return false;
    else
        return true;
}

bool isHeap(vector<int> &v)
{
    for (int ptr = v.size() / 2 - 1; ptr >= 0; ptr--)
    {
        if (!_isHeap(v, ptr))
            return false;
    }

    return true;
}

void heapSort(vector<int> &v)
{
    if (!isHeap(v))
        heapify(v);

    stack<int> stk;

    while (v.size() > 0)
        stk.push(popHeap(v));

    while (!stk.empty())
    {
        v.push_back(stk.top());
        stk.pop();
    }
}
