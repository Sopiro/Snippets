#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

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