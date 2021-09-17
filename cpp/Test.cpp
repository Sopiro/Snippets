#include "StringSnippets.h"
#include "NumericSnippets.h"
#include "SortingSnippets.h"

int main(void)
{
    // auto r = ssplit_n("aa,  a   ,   s, d,a, ,,,dbb cc");

    // for (auto &a : r)
    //     cout << a << endl;

    vector<int> v = {5, 9, 1, 2, 4};
    // vector<int> t = {999, 999, 999};

    // bubble(v, true);
    merge(v, true);

    // copy(t.begin(), t.end(), v.begin()+3);

    cout << join(v, " ") << endl;

    return 0;
}