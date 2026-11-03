#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
public:
    vector<int> heap;

    void heapifyUp(int index)
    {
        if (index == 0)
            return;

        int parent = (index - 1) / 2;

        if (heap[index] > heap[parent])
        {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void insert(int priority)
    {
        heap.push_back(priority);

        heapifyUp(heap.size() - 1);
    }

    void heapifyDown(int index)
    {
        int largest = index;

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    int extractMax()
    {
        if (heap.empty())
            return -1;

        int maximum = heap[0];

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);

        return maximum;
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
    MaxHeap h;

    h.insert(40);
    h.insert(15);
    h.insert(30);
    h.insert(50);
    h.insert(10);
    h.insert(60);

    cout << "Max Heap: ";
    h.display();

    cout << "Removed Maximum: " << h.extractMax() << endl;

    cout << "Updated Heap: ";
    h.display();

    return 0;
}