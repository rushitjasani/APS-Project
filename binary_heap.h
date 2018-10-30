class MinHeap
{

  public:
    int *arr;
    int max_size;
    int heap_size;

    MinHeap()
    {
        arr = new int[1000000];
        max_size = 1000000;
        heap_size = 0;
    }
    ~MinHeap()
    {
        delete arr;
    }

    void min_heapify(int i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest;
        if (l <= heap_size && arr[l] < arr[i])
        {
            smallest = l;
        }
        else
            smallest = i;

        if (r <= heap_size && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i)
        {
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            min_heapify(smallest);
        }
    }

    int get_min()
    {
        if(heap_size==0)
            return -1;
            
        return arr[0];
    }

    int extract_min()
    {

        int min = arr[0];
        arr[0] = arr[heap_size - 1];
        heap_size--;
        min_heapify(0);
        return min;
    }

    void insert(int element)
    {

        heap_size++;
        arr[heap_size - 1] = element;

        int i = heap_size - 1;
        while (i != 0 && arr[(i - 1) / 2] > arr[i])
        {
            int temp = arr[i];
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = temp;

            i = (i - 1) / 2;
        }
    }

    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void decrease_key(int elem, int new_val)
    {
        int i=-1;
        for(int k=0;k<heap_size;k++)
        {
            if(arr[k]==elem)
            {
                i=k;
                break;
            }
        }
        
        if(i==-1 || arr[i]<=new_val)
            return;

        arr[i] = new_val;
        while (i != 0 && arr[(i - 1) / 2] > arr[i])
        {
            swap(&arr[i], &arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
};