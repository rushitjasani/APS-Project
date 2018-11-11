#include <bits/stdc++.h>
#include "../fibonacci_heap/fibonacci_heap.h"

using namespace std;

typedef pair<int, int> iPair;
#define INF 999999
vector<string> split_string(string);

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s)
{
    vector<set<iPair>> g(n + 1);
    int test1 = edges.size();
    int u, v, w;
    for (int i = 0; i < test1; i++)
    {
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];
        g[u].insert({v, w});
        g[v].insert({u, w});
    }

    FibonacciHeap<iPair> pq;

    for (int i = 1; i <= n; i++)
    {
        pq.insert({INF, i});
    }

    vector<int> darr(n + 1, INF);
    darr[s] = 0; // source vertex dist is zero
    pq.decrease_key({INF, s}, {0, s});

    while (pq.heap)
    {

        int u = pq.get_min().second;
        pq.extract_min();

        for (auto x : g[u])
        {

            int v = x.first;
            int weight = x.second;

            if (darr[v] > darr[u] + weight)
            {
                // Updating distance of v
                int tmp = darr[v];
                darr[v] = darr[u] + weight;
                pq.decrease_key({tmp, v}, {darr[v], v});
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i)
    {
        if (i != s && darr[i] != 999999)
            ans.push_back(darr[i]);
        else if (i != s)
            ans.push_back(-1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++)
        {
            edges[i].resize(3);

            for (int j = 0; j < 3; j++)
            {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        clock_t begin = clock();
        vector<int> result = shortestReach(n, edges, s);
        clock_t end = clock();
        ofstream fout;
        fout.open("fibo_time", ios::out | ios::app);
        fout << 1.0 * (end - begin) / CLOCKS_PER_SEC << endl;
        fout.close();

        for (int i = 0; i < result.size(); i++)
        {
            fout << result[i];

            if (i != result.size() - 1)
            {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}