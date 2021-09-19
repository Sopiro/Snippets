#include "Strings.h"
#include "Numerics.h"
#include "Sortings.h"
#include "Searchings.h"

int main(void)
{
    vector<int> v = {1, 9};
    cout << "original: " << join(v, " ") << endl;
    // cout << "isHeap: " << isHeap(v) << endl;

    // heapify(v);
    // cout << "result:" << join(v, " ") << endl;
    // cout << "isHeap: " << isHeap(v) << endl;

    // cout << popHeap(v) << endl;
    // cout << "result:" << join(v, " ") << endl;
    // insertHeap(v, 1001);
    // cout << "result:" << join(v, " ") << endl;
    // heapSort(v);
    // cout << "result:" << join(v, " ") << endl;

    cout << quick_select(v, 1) << endl;

    return 0;
}