#include "StringSnippets.h"
#include "NumericSnippets.h"
#include "SortingSnippets.h"

int main(void)
{
    // auto r = ssplit_n("aa,  a   ,   s, d,a, ,,,dbb cc");

    // for (auto &a : r)
    //     cout << a << endl;

    vector<int> v = {10, 7, 1, 3, 8, 9, 2, 2, 4};

    bubble(v);

    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}