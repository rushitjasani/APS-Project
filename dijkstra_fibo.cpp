#include <bits/stdc++.h>
#include "fibonacci_heap.h"

using namespace std;

typedef pair<int, int> iPair;
#define INF 999999
vector<string> split_string(string);

template <class V>
class FibonacciHeap
{
  public:
    node<V> *heap; /*root node of heap*/

    FibonacciHeap()
    {
        heap = NULL;
    }

    ~FibonacciHeap()
    {
        if (heap)
        {
            deleteAll(heap);
        }
    }

    void deleteAll(node<V> *n)
    {
        if (n)
        {
            node<V> *c = n;
            do
            {
                node<V> *d = c;
                c = c->next;
                deleteAll(d->child);
                delete d;
            } while (c != n);
        }
    }

    node<V> *create_node(V value)
    {
        node<V> *n = new node<V>;
        n->value = value;
        n->prev = n->next = n;
        n->degree = 0;
        n->marked = false;
        n->child = NULL;
        n->parent = NULL;
        return n;
    }

    node<V> *merge_heaps(node<V> *a, node<V> *b)
    {
        if (!a)
            return b;
        if (!b)
            return a;
        if (a->value > b->value)
        {
            node<V> *temp = a;
            a = b;
            b = temp;
        }
        node<V> *an = a->next;
        node<V> *bp = b->prev;
        a->next = b;
        b->prev = a;
        an->prev = bp;
        bp->next = an;
        return a;
    }

    node<V> *insert(V value)
    {
        node<V> *ret = create_node(value);
        heap = merge_heaps(heap, ret);
        return ret;
    }

    V get_min()
    {
        if (heap == NULL)
            return V();

        return heap->value;
    }

    void addChild(node<V> *parent, node<V> *child)
    {
        child->prev = child->next = child;
        child->parent = parent;
        parent->degree++;
        parent->child = merge_heaps(parent->child, child);
    }

    node<V> *extract_min_helper(node<V> *n)
    {
        /* mark all childs as false and set their parent to null */
        if (n->child != NULL)
        {
            node<V> *c = n->child;
            do
            {
                c->marked = false;
                c->parent = NULL;
                c = c->next;
            } while (c != n->child);
        }
        /* done */

        if (n->next == n)
        {
            n = n->child;
        }
        else
        {
            n->next->prev = n->prev; /* detach n from doubly LL */
            n->prev->next = n->next; /* detach n from doubly LL */
            n = merge_heaps(n->next, n->child);
        }

        if (n == NULL)
            return n;

        node<V> *trees[64] = {NULL};

        while (true)
        {
            if (trees[n->degree] != NULL)
            {
                node<V> *t = trees[n->degree];
                if (t == n)
                    break;
                trees[n->degree] = NULL;
                if ((n->value) < (t->value))
                {
                    t->prev->next = t->next;
                    t->next->prev = t->prev;
                    addChild(n, t);
                }
                else
                {
                    t->prev->next = t->next;
                    t->next->prev = t->prev;
                    if (n->next == n)
                    {
                        t->next = t;
                        t->prev = t;
                        addChild(t, n);
                        n = t;
                    }
                    else
                    {
                        n->prev->next = t;
                        n->next->prev = t;
                        t->next = n->next;
                        t->prev = n->prev;
                        addChild(t, n);
                        n = t;
                    }
                }
                continue;
            }
            else
            {
                trees[n->degree] = n;
            }
            n = n->next;
        }
        node<V> *min = n;
        node<V> *start = n;
        do
        {
            if (n->value < min->value)
                min = n;
            n = n->next;
        } while (n != start);
        return min;
    }

    V extract_min()
    {
        if (heap == NULL)
            return V();
        node<V> *old = heap;
        heap = extract_min_helper(heap);
        V ret = old->value;
        delete old;
        return ret;
    }

    node<V> *find_helper(node<V> *heap, V value)
    {
        node<V> *n = heap;
        if (n == NULL)
            return NULL;
        do
        {
            if (n->value == value)
                return n;
            node<V> *ret = find_helper(n->child, value);
            if (ret)
                return ret;
            n = n->next;
        } while (n != heap);
        return NULL;
    }

    node<V> *find(V value)
    {
        return find_helper(heap, value);
    }

    node<V> *cut(node<V> *heap, node<V> *n)
    {
        if (n->next == n)
        {
            n->parent->child = NULL;
        }
        else
        {
            n->next->prev = n->prev;
            n->prev->next = n->next;
            n->parent->child = n->next;
        }
        n->next = n->prev = n;
        n->marked = false;
        return merge_heaps(heap, n);
    }

    node<V> *decrease_key_helper(node<V> *heap, node<V> *n, V value)
    {
        if (n->value < value)
            return heap;
        n->value = value;
        if (n->parent)
        {
            if (n->value < n->parent->value)
            {
                heap = cut(heap, n);
                node<V> *parent = n->parent;
                n->parent = NULL;
                while (parent != NULL && parent->marked)
                {
                    heap = cut(heap, parent);
                    n = parent;
                    parent = n->parent;
                    n->parent = NULL;
                }
                if (parent != NULL && parent->parent != NULL)
                    parent->marked = true;
            }
        }
        else
        {
            if (n->value < heap->value)
            {
                heap = n;
            }
        }
        return heap;
    }

    void decrease_key(V i, V value)
    {
        node<V> *n = find(i);
        if (n == NULL)
        {
            return;
        }
        heap = decrease_key_helper(heap, n, value);
    }
};

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

    vector<int> darr(n + 1, INF);
    darr[s] = 0;       // source vertex dist is zero
    pq.insert({0, s}); // insert zero, Source

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
                darr[v] = darr[u] + weight;
                pq.insert({darr[v], v});
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

        vector<int> result = shortestReach(n, edges, s);

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