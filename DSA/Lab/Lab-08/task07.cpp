#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
public:
    vector<int> heap;

    void heapifyUp(int index)
    {
        if (index == 0)
            return;

        int parent = (index - 1) / 2;

        if (heap[index] < heap[parent])
        {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void insert(int urgency)
    {
        heap.push_back(urgency);

        heapifyUp(heap.size() - 1);
    }

    void heapifyDown(int index)
    {
        int smallest = index;

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;

        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    int extractMin()
    {
        if (heap.empty())
            return -1;

        int minimum = heap[0];

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);

        return minimum;
    }

    void display()
    {
        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << " ";

        cout << endl;
    }
};

int main()
{
    MinHeap h;

    h.insert(35);
    h.insert(12);
    h.insert(25);
    h.insert(8);
    h.insert(40);
    h.insert(5);

    cout << "Min Heap: ";
    h.display();

    cout << "Removed Minimum: " << h.extractMin() << endl;

    cout << "Updated Heap: ";
    h.display();

    return 0;
}