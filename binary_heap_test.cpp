#include <bits/stdc++.h>
#include "binary_heap.h"
using namespace std;

int main()
{
    MinHeap h;
    long long n;
    cin >> n;
    while (n--)
    {
        /*
            0 : insert
            1 : get minimum
            2 : extract minimum
            3 : decrease key
         */
        int c;
        cin >> c;
        int inp=0;
        int d_x,d_y;
        switch (c)
        {
            case 0:
                cin >> inp;
                h.insert(inp);
                break;
            case 1:
                cout << h.get_min()<<endl;
                break;
            case 2:
                h.extract_min();
                break;
            case 3: 
                cin >> d_x >> d_y;
                h.decrease_key(d_x, d_y);
                break;
            default:
                break;
        }
    }
    return 0;
}