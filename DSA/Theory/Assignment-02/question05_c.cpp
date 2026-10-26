
// Print jobs (Q5): J1 (priority 3), J2 (priority 1), J3 (priority 2), J4 (priority 1), J5 (priority 3),
// J6 (priority 2). A smaller number means higher priority.
// Step         Event
// 1            PUSH J1
// 2            PUSH J2
// 3            PUSH J3
// 4            POP
// 5            PUSH J4
// 6            PUSH J5
// 7            POP
// 8            POP
// 9            PUSH J6
// 10 to 12     POP (three times)
// c) Implement a PriorityQueue with push(job, priority), pop() and peek() that handles ties correctly.
// Run the 12 events above and print the output of every POP.
#include <iostream>
#include <string>
using namespace std;

class Job
{
public:
    string name;
    int priority;
    int arrival;

    Job()
    {
        name = "unknown";
        priority = 0;
        arrival = 0;
    }
    Job(string n, int p, int a)
    {
        name = n;
        priority = p;
        arrival = a;
    }
};

class PriorityQueue
{
private:
    Job heap[100];
    int size;
    int arrivalCount;

    // Check which job should come first
    bool higherPriority(Job a, Job b)
    {
        if (a.priority != b.priority)
            return a.priority < b.priority;

        return a.arrival < b.arrival;
    }

    void swapJobs(int i, int j)
    {
        Job temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void siftUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;

            if (higherPriority(heap[index], heap[parent]))
            {
                swapJobs(index, parent);
                index = parent;
            }
            else
                break;
        }
    }

    void siftDown(int index)
    {
        while (true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size &&
                higherPriority(heap[left], heap[smallest]))
                smallest = left;

            if (right < size &&
                higherPriority(heap[right], heap[smallest]))
                smallest = right;

            if (smallest == index)
                break;

            swapJobs(index, smallest);
            index = smallest;
        }
    }

public:
    PriorityQueue()
    {
        size = 0;
        arrivalCount = 0;
    }

    void push(string name, int priority)
    {
        if (size == 100)
        {
            cout << "Queue is full\n";
            return;
        }

        heap[size] = Job(name, priority, arrivalCount);
        size++;
        arrivalCount++;

        siftUp(size - 1);
    }

    void pop()
    {
        if (size == 0)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << heap[0].name << endl;

        heap[0] = heap[size - 1];
        size--;

        if (size > 0)
            siftDown(0);
    }

    void peek()
    {
        if (size == 0)
            cout << "Queue is empty\n";
        else
            cout << heap[0].name << endl;
    }
};

int main()
{
    PriorityQueue pq;

    // Step 1
    pq.push("J1", 3);

    // Step 2
    pq.push("J2", 1);

    // Step 3
    pq.push("J3", 2);

    // Step 4
    cout << "Step 4 POP: ";
    pq.pop();

    // Step 5
    pq.push("J4", 1);

    // Step 6
    pq.push("J5", 3);

    // Step 7
    cout << "Step 7 POP: ";
    pq.pop();

    // Step 8
    cout << "Step 8 POP: ";
    pq.pop();

    // Step 9
    pq.push("J6", 2);

    // Steps 10 to 12
    cout << "Step 10 POP: ";
    pq.pop();

    cout << "Step 11 POP: ";
    pq.pop();

    cout << "Step 12 POP: ";
    pq.pop();

    return 0;
}
