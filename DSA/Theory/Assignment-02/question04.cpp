// Heap H (Q4), a min-heap of job deadlines in hours: [5, 11, 8, 14, 17, 9, 12, 20, 16, 19]
// A cloud scheduler keeps pending jobs in a min-heap ordered by deadline (in hours). The heap
// currently holds the given array H.
// a) Draw H as a binary tree and verify the min-heap property by checking every parent against its
// children.
// b) Two new jobs arrive: first a job with deadline 6, then a job with deadline 4. Insert them in this
// order. Show the array after every swap and state the total number of swaps.
// c) The scheduler now dispatches two jobs. Perform two extractMin operations on the heap from (b).
// Show the array after the last element is moved to the root and after every swap while it sifts down.
// d) On the heap from (c), an operator reports that the job at index 7 has become urgent and its
// deadline drops from 20 to 3. Perform decreaseKey and show every swap. Explain why decreaseKey only
// needs a sift up.

#include <iostream>
using namespace std;

class MinHeap
{
private:
    int heap[100];
    int size;
    int totalSwaps;

    void displayArray()
    {
        cout << "[ ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << "]\n";
    }

    void swapElements(int i, int j)
    {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;

        totalSwaps++;

        cout << "Swap index " << i << " and index " << j << ": ";
        displayArray();
    }

    void siftUp(int index)
    {
        if (index == 0)
            return;

        int parent = (index - 1) / 2;

        if (heap[index] < heap[parent])
        {
            swapElements(index, parent);
            siftUp(parent);
        }
    }

    void siftDown(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index)
        {
            swapElements(index, smallest);
            siftDown(smallest);
        }
    }

    bool verify(int index)
    {
        if (index >= size)
            return true;

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size)
        {
            cout << "Parent " << heap[index]
                 << ", left child " << heap[left];

            if (heap[index] <= heap[left])
                cout << " -> OK\n";
            else
            {
                cout << " -> VIOLATION\n";
                return false;
            }
        }

        if (right < size)
        {
            cout << "Parent " << heap[index]
                 << ", right child " << heap[right];

            if (heap[index] <= heap[right])
                cout << " -> OK\n";
            else
            {
                cout << " -> VIOLATION\n";
                return false;
            }
        }

        return verify(left) && verify(right);
    }

    void displayTree(int index, int depth)
    {
        if (index >= size)
            return;

        displayTree(2 * index + 2, depth + 1);

        for (int i = 0; i < depth; i++)
            cout << "    ";

        cout << heap[index] << '\n';

        displayTree(2 * index + 1, depth + 1);
    }

public:
    MinHeap()
    {
        int initial[] = {5, 11, 8, 14, 17, 9, 12, 20, 16, 19};

        size = 10;
        totalSwaps = 0;

        for (int i = 0; i < size; i++)
            heap[i] = initial[i];
    }

    void partA()
    {
        cout << "PART (a): Binary tree\n";
        displayTree(0, 0);

        cout << "\nChecking every parent against its children:\n";

        if (verify(0))
            cout << "The heap satisfies the min-heap property.\n";
        else
            cout << "The heap violates the min-heap property.\n";
    }

    void insert(int value)
    {
        heap[size] = value;
        size++;

        cout << "After inserting " << value << ": ";
        displayArray();

        siftUp(size - 1);

        cout << "Heap after insertion: ";
        displayArray();
    }

    void partB()
    {
        cout << "\nPART (b): Insert 6, then 4\n";

        int swapsBefore = totalSwaps;

        insert(6);
        insert(4);

        cout << "Total swaps during both insertions: "
             << totalSwaps - swapsBefore << '\n';
    }

    int extractMin()
    {
        if (size == 0)
        {
            cout << "Heap is empty.\n";
            return -1;
        }

        int minimum = heap[0];

        cout << "\nExtracting minimum: " << minimum << '\n';

        heap[0] = heap[size - 1];
        size--;

        cout << "After moving last element to root: ";
        displayArray();

        if (size > 0)
            siftDown(0);

        cout << "Heap after extractMin: ";
        displayArray();

        return minimum;
    }

    void partC()
    {
        cout << "\nPART (c): Two extractMin operations\n";

        cout << "First removed: " << extractMin() << '\n';
        cout << "Second removed: " << extractMin() << '\n';
    }

    void decreaseKey(int index, int newValue)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid index.\n";
            return;
        }

        if (newValue > heap[index])
        {
            cout << "New value must not be greater than old value.\n";
            return;
        }

        cout << "\nChanging index " << index
             << " from " << heap[index]
             << " to " << newValue << '\n';

        heap[index] = newValue;

        cout << "After changing the key: ";
        displayArray();

        siftUp(index);

        cout << "Heap after decreaseKey: ";
        displayArray();
    }

    void partD()
    {
        cout << "\nPART (d): Decrease key at index 7 to 3\n";

        if (heap[7] != 20)
        {
            cout << "The expected job with deadline 20 "
                 << "is not at index 7.\n";
            return;
        }

        decreaseKey(7, 3);

        cout << "Only sift-up is needed because decreasing "
             << "a key cannot violate the heap property "
             << "with its children; it can violate the "
             << "property with its parent.\n";
    }
};

int main()
{
    MinHeap h;

    h.partA();
    h.partB();
    h.partC();
    h.partD();

    return 0;
}
