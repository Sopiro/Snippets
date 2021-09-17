#include "StringSnippets.h"
#include "NumericSnippets.h"
#include "SortingSnippets.h"

int main(void)
{
    // auto r = ssplit_n("aa,  a   ,   s, d,a, ,,,dbb cc");

    // for (auto &a : r)
    //     cout << a << endl;

    vector<int> v = {1, 2, 3, 0, 4};

    // bubble(v, true);
    // merge(v, true);
    // selection(v, true);
    insertion(v, true);

    cout << join(v, " ") << endl;

    return 0;
}