#include "StringSnippets.h"
#include "NumericSnippets.h"
#include "SortingSnippets.h"
#include "SearchSnippets.h"

#include <algorithm>

int main(void)
{
    vector<int> v = {1, 3, 5, 2, 4, 8, 6, 7, 9};
    cout << "original: " << join(v, " ") << endl;
    cout << "isHeap: " << isHeap(v) << endl;

    heapify(v);
    cout << "result:" << join(v, " ") << endl;
    cout << "isHeap: " << isHeap(v) << endl;

    cout << popHeap(v) << endl;
    cout << "result:" << join(v, " ") << endl;
    insertHeap(v, 1001);
    cout << "result:" << join(v, " ") << endl;
    heapSort(v);
    cout << "result:" << join(v, " ") << endl;

    return 0;
}