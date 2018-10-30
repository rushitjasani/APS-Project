class MaxHeap
{
  public:
    int *arr;
    int max_size;
    int heap_size;

    MaxHeap(int n)
    {
        arr = new int[n];
        max_size = n;
        heap_size = 0;
    }

    void max_heapify(int i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest;
        if (l <= heap_size && arr[l] > arr[i])
        {
            largest = l;
        }
        else
            largest = i;

        if (r <= heap_size && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            max_heapify(largest);
        }
    }

    int get_max()
    {
        return arr[0];
    }

    int extract_max()
    {

        int max = arr[0];
        arr[0] = arr[heap_size - 1];
        heap_size--;
        max_heapify(0);
        return max;
    }

    void insert(int element)
    {

        heap_size++;
        arr[heap_size - 1] = element;

        int i = heap_size - 1;
        while (i != 0 && arr[(i - 1) / 2] < arr[i])
        {
            int temp = arr[i];
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = temp;

            i = (i - 1) / 2;
        }
    }
};

class MinHeap
{

  public:
    int *arr;
    int max_size;
    int heap_size;

    MinHeap(int n)
    {
        arr = new int[n];
        max_size = n;
        heap_size = 0;
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
};