#include "StringSnippets.h"
#include "NumericSnippets.h"

int main(void)
{
    auto r = split("aa bb cc");

    for (auto &a : r)
        cout << a << endl;

    return 0;
}