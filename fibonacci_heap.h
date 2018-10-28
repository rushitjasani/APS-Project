/* Node structure of fibonacci heap */
struct node
{
  public:
    node *prev;
    node *next;
    node *child;
    node *parent;
    int value;
    int degree;
    bool marked;
};

class FibonacciHeap
{
  public:
    node *heap; /*root node of heap*/

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

    void deleteAll(node *n)
    {
        if (n)
        {
            node *c = n;
            do
            {
                node *d = c;
                c = c->next;
                deleteAll(d->child);
                delete d;
            } while (c != n);
        }
    }

    node *create_node(int value)
    {
        node *n = new node;
        n->value = value;
        n->prev = n->next = n;
        n->degree = 0;
        n->marked = false;
        n->child = NULL;
        n->parent = NULL;
        return n;
    }
    node *merge_heaps(node *a, node *b)
    {
        if (!a)
            return b;
        if (!b)
            return a;
        if (a->value > b->value)
        {
            node *temp = a;
            a = b;
            b = temp;
        }
        node *an = a->next;
        node *bp = b->prev;
        a->next = b;
        b->prev = a;
        an->prev = bp;
        bp->next = an;
        return a;
    }
    node *insert(int value)
    {
        node *ret = create_node(value);
        heap = merge_heaps(heap, ret);
        return ret;
    }

    int get_min()
    {
        return heap->value;
    }

    void addChild(node *parent, node *child)
    {
        child->prev = child->next = child;
        child->parent = parent;
        parent->degree++;
        parent->child = merge_heaps(parent->child, child);
    }

    node *remove_min_helper(node *n)
    {
        /* mark all childs as false and set their parent to null */
        if (n->child != NULL)
        {
            node *c = n->child;
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

        node *trees[64] = {NULL};

        while (true)
        {
            if (trees[n->degree] != NULL)
            {
                node *t = trees[n->degree];
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
        node *min = n;
        node *start = n;
        do
        {
            if (n->value < min->value)
                min = n;
            n = n->next;
        } while (n != start);
        return min;
    }

    int remove_min()
    {
        node *old = heap;
        heap = remove_min_helper(heap);
        int ret = old->value;
        delete old;
        return ret;
    }
};