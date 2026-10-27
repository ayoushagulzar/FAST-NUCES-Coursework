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

        cout << "Swap (index " << i << ", index " << j << "): ";
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
                 << " <= Left child " << heap[left] << " : ";

            if (heap[index] <= heap[left])
                cout << "PASS\n";
            else
            {
                cout << "FAIL\n";
                return false;
            }
        }

        if (right < size)
        {
            cout << "Parent " << heap[index]
                 << " <= Right child " << heap[right] << " : ";

            if (heap[index] <= heap[right])
                cout << "PASS\n";
            else
            {
                cout << "FAIL\n";
                return false;
            }
        }

        return verify(left) && verify(right);
    }

    void displayTree()
    {
        int level = 0;
        int index = 0;

        while (index < size)
        {
            int nodes = 1;

            for (int i = 0; i < level; i++)
                nodes *= 2;

            cout << "Level " << level << ": ";

            for (int i = 0; i < nodes && index < size; i++)
            {
                cout << heap[index] << "  ";
                index++;
            }

            cout << '\n';
            level++;
        }
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

    void drawTree()
    {
        cout << "\n========== PART (a): INITIAL MIN-HEAP ==========\n";

        cout << "\nBinary tree:\n";
        displayTree();

        cout << "\nMin-heap property verification:\n";

        if (verify(0))
            cout << "\nResult: Valid min-heap.\n";
        else
            cout << "\nResult: Invalid min-heap.\n";
    }

    void insert(int value)
    {
        heap[size] = value;
        size++;

        cout << "\nInsert " << value << '\n';
        cout << "After insertion: ";
        displayArray();

        siftUp(size - 1);

        cout << "Final heap: ";
        displayArray();
    }

    void insertNewJobs()
    {
        cout << "\n========== PART (b): INSERT 6 AND 4 ==========\n";

        int swapsBefore = totalSwaps;

        insert(6);
        insert(4);

        cout << "\nTotal swaps: "
             << totalSwaps - swapsBefore << '\n';

        cout << "Final heap: ";
        displayArray();
    }

    int extractMin()
    {
        if (size == 0)
        {
            cout << "Error: Heap is empty.\n";
            return -1;
        }

        int minimum = heap[0];

        cout << "\nExtract minimum: " << minimum << '\n';

        heap[0] = heap[size - 1];
        size--;

        cout << "After moving last element to root: ";
        displayArray();

        if (size > 0)
            siftDown(0);

        cout << "Heap after extraction: ";
        displayArray();

        return minimum;
    }

    void twoExtractMin()
    {
        cout << "\n========== PART (c): TWO EXTRACT-MIN OPERATIONS ==========\n";

        int first = extractMin();
        cout << "Removed: " << first << '\n';

        int second = extractMin();
        cout << "Removed: " << second << '\n';
    }

    void decreaseKey(int index, int newValue)
    {
        if (index < 0 || index >= size)
        {
            cout << "Error: Invalid index.\n";
            return;
        }

        if (newValue > heap[index])
        {
            cout << "Error: New value is greater than the current value.\n";
            return;
        }

        cout << "\nChange index " << index
             << " from " << heap[index]
             << " to " << newValue << '\n';

        heap[index] = newValue;

        cout << "After changing key: ";
        displayArray();

        siftUp(index);

        cout << "Final heap: ";
        displayArray();
    }

    void decreaseKeyAtIndex()
    {
        cout << "\n========== PART (d): DECREASE KEY ==========\n";

        if (heap[7] != 20)
        {
            cout << "Error: Deadline 20 is not at index 7.\n";
            return;
        }

        decreaseKey(7, 3);

        cout << "\nExplanation:\n";
        cout << "Only sift-up is required because decreasing a key\n";
        cout << "can violate the heap property with its parent,\n";
        cout << "but cannot violate it with its children.\n";
    }
};

int main()
{
    MinHeap h;

    h.drawTree();
    h.insertNewJobs();
    h.twoExtractMin();
    h.decreaseKeyAtIndex();

    return 0;
}
