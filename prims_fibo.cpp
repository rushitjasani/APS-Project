#include <bits/stdc++.h>
#include "fibonacci_heap.h"
using namespace std;

#define ll long long
#define vpp vector<pair<ll, ll>>
vector<bool> marked;

ll prim(int x,vector<vpp>& adj)
{
    FibonacciHeap<pair <ll, ll > > Q;
    ll y;
    ll minimumCost = 0;
    pair<ll,ll> p;
    Q.insert(make_pair(0, x));
    while(Q.heap != NULL)
    {
        p = Q.get_min();
        Q.extract_min();
        x = p.second;
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.insert(adj[x][i]);
        }
    }
    return minimumCost;
}


int main()
{
    int v,e;
    cin >> v >> e;
    vector<vpp> adj(v+1);
    marked.resize(v+1);
    for( int i=0; i<e ;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    ll minimumCost = prim(1, adj);
    cout << minimumCost << endl;
    return 0;
}