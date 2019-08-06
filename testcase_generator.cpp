#include <bits/stdc++.h>
#define ll long long
using namespace std;

set<ll> num;

ll generate_random(ll r)
{
    ll x = rand() % r;
    if (num.find(x) != num.end())
        generate_random(r);
    else
        num.insert(x);
    return x;
}

int main(int argc, char *argv[])
{
    ll n = stoll(argv[1]);
    cout << n << endl;
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int opt = rand() % 7;
        if (opt == 0 || opt == 4 || opt == 5 || opt == 6)
        {
            ll k = generate_random(65535);
            cout << 0 << " " << k << endl;
        }
        else if (opt == 1)
        {
            cout << opt << endl;
        }
        else if (opt == 2)
        {
            cout << opt << endl;
            if( num.size() > 0 )
                num.erase(num.begin());
        }
        else if (opt == 3)
        {
            int index=0;
            if( num.size() == 0 ){
                cout << 1 << endl;
                continue;
            }
            else if ( num.size() > 1 ){
                index = rand() % (num.size() -1 );
            }
            auto it = num.begin();
            advance(it , index);
            ll to_change = *it;
            cout << opt << " " << to_change << " " << generate_random(to_change) << endl;
            num.erase(it);   
        }
    }
    return 0;
}