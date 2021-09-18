#include "StringSnippets.h"
#include "NumericSnippets.h"
#include "SortingSnippets.h"
#include "SearchSnippets.h"

int main(void)
{
    // auto r = ssplit_n("aa,  a   ,   s, d,a, ,,,dbb cc");

    // for (auto &a : r)
    //     cout << a << endl;

    // len = 6
    vector<int> v = {
        7,
        3,
        4,
        2,
        5,
        1,
        123,
        -132,
        120,
        2,
        1,
        5,
        6,
        8};

    // bubble(v, true);
    // merge(v, true);
    // selection(v, true);
    // insertion(v, true);
    cout << "original: " << join(v, " ") << endl;

    quick_clean(v);

    cout << "result:" << join(v, " ") << endl;

    cout << binarySearch(v, 1) << endl;

    return 0;
}