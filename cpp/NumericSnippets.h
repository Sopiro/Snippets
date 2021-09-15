#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int divisor_count(int n)
{
    int count = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i != n)
                count += 2;
            else
                count += 1;
        }
    }

    return count;
}

vector<int> digit_vector(int n)
{
    vector<int> res;

    while (n > 0)
    {
        res.push_back(n % 10);
        n /= 10;
    }

    return res;
}