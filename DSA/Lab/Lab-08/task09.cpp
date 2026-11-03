#include <iostream>
#include <vector>
using namespace std;

class Request
{
public:
    int id;
    int priority;
    int order;

    Request(int i, int p, int o)
    {
        id = i;
        priority = p;
        order = o;
    }
};

class PriorityQueue
{
public:
    vector<Request> heap;
    int counter = 0;

    bool isSmaller(int a, int b)
    {
        if (heap[a].priority == heap[b].priority)
            return heap[a].order < heap[b].order;

        return heap[a].priority < heap[b].priority;
    }

    void insert(int id, int priority)
    {
        Request r(id, priority, counter++);

        heap.push_back(r);

        int index = heap.size() - 1;

        while (index > 0)
        {
            int parent = (index - 1) / 2;

            if (isSmaller(index, parent))
            {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int index)
    {
        int smallest = index;

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && isSmaller(left, smallest))
            smallest = left;

        if (right < heap.size() && isSmaller(right, smallest))
            smallest = right;

        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void extractMin()
    {
        if (heap.empty())
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Processed Request: ID "
             << heap[0].id
             << " Priority "
             << heap[0].priority << endl;

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);
    }

    void peek()
    {
        if (heap.empty())
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Next Request: ID "
             << heap[0].id
             << " Priority "
             << heap[0].priority << endl;
    }

    void display()
    {
        for (int i = 0; i < heap.size(); i++)
        {
            cout << "ID: " << heap[i].id
                 << " Priority: " << heap[i].priority << endl;
        }
    }
};

int main()
{
    PriorityQueue q;

    q.insert(101, 4);
    q.insert(102, 2);
    q.insert(103, 5);
    q.insert(104, 1);
    q.insert(105, 2);
    q.insert(106, 3);

    cout << "Emergency Queue:\n";
    q.display();

    cout << "\n";
    q.peek();

    cout << "\n";
    q.extractMin();

    cout << "\nUpdated Queue:\n";
    q.display();

    cout << "\n";
    q.peek();

    cout << "\n";
    q.extractMin();

    return 0;
}