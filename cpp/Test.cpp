#include "StringSnippets.h"
#include "NumericSnippets.h"

int main(void)
{
    auto r = ssplit_n("aa,  a   ,   s, d,a, ,,,dbb cc");

    for (auto &a : r)
        cout << a << endl;

    return 0;
}