
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
// a) Give the job that is printed at every POP step, using the priorities in the Given Data and the FIFO
// rule for ties.
// b) A student stores only the priority number in the heap. Show with three jobs A, B, C, all of priority 1
// and pushed in that order, that the pops can come out as A, C, B. Then explain how to fix it by storing a
// pair (priority, arrival number).
// c) Implement a PriorityQueue with push(job, priority), pop() and peek() that handles ties correctly.
// Run the 12 events above and print the output of every POP.
// d) Starvation. A low-priority job may wait forever if urgent jobs keep arriving. Suggest an aging
// rule that fixes this. Explain why decreasing every waiting job's number on each pop would cost O(n)
// per pop, and describe a cheaper way to get aging (for example, by changing the key that is stored).

#include <iostream>
#include <string>
using namespace std;

class PriorityQueue
{
private:
    class Job
    {
    public:
        string name;
        int priority;
        int arrival;
    };

    Job heap[100];
    int size;
    int arrivalCounter;

    // Lower priority number wins.
    // If equal, first in wins.
    bool comesFirst(int i, int j)
    {
        if (heap[i].priority != heap[j].priority)
            return heap[i].priority < heap[j].priority;

        return heap[i].arrival < heap[j].arrival;
    }

    void swapJobs(int i, int j)
    {
        Job temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void siftUp(int index)
    {
        if (index == 0)
            return;

        int parent = (index - 1) / 2;

        if (comesFirst(index, parent))
        {
            swapJobs(index, parent);
            siftUp(parent);
        }
    }

    void siftDown(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int best = index;

        if (left < size && comesFirst(left, best))
            best = left;

        if (right < size && comesFirst(right, best))
            best = right;

        if (best != index)
        {
            swapJobs(index, best);
            siftDown(best);
        }
    }

public:
    PriorityQueue()
    {
        size = 0;
        arrivalCounter = 0;
    }

    void push(string name, int priority)
    {
        if (size == 100)
        {
            cout << "Priority queue is full.\n";
            return;
        }

        heap[size].name = name;
        heap[size].priority = priority;
        heap[size].arrival = arrivalCounter++;

        siftUp(size);
        size++;
    }

    string pop()
    {
        if (size == 0)
            return "Queue is empty";

        string result = heap[0].name;

        heap[0] = heap[size - 1];
        size--;

        if (size > 0)
            siftDown(0);

        return result;
    }

    string peek()
    {
        if (size == 0)
            return "Queue is empty";

        return heap[0].name;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

// this demonstrates why priority alone cannot guarantee first in first out(fifo)
class BadQueue
{
private:
    string names[10];
    int priorities[10];
    int size;

    void siftDown(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int best = index;

        if (left < size && priorities[left] < priorities[best])
            best = left;

        if (right < size && priorities[right] < priorities[best])
            best = right;

        if (best != index)
        {
            int tempPriority = priorities[index];
            priorities[index] = priorities[best];
            priorities[best] = tempPriority;

            string tempName = names[index];
            names[index] = names[best];
            names[best] = tempName;

            siftDown(best);
        }
    }

public:
    BadQueue()
    {
        size = 0;
    }

    void push(string name, int priority)
    {
        names[size] = name;
        priorities[size] = priority;
        size++;
    }

    string pop()
    {
        if (size == 0)
            return "Queue is empty";

        string result = names[0];

        names[0] = names[size - 1];
        priorities[0] = priorities[size - 1];
        size--;

        if (size > 0)
            siftDown(0);

        return result;
    }
};

int main()
{
    PriorityQueue pq;

    cout << "PART (a) and (c): Print server events\n\n";

    // Steps 1-3
    pq.push("J1", 3);
    pq.push("J2", 1);
    pq.push("J3", 2);

    cout << "Peek before Step 4: " << pq.peek() << '\n';

    // Step 4
    cout << "Step 4 POP: " << pq.pop() << '\n';

    // Steps 5-6
    pq.push("J4", 1);
    pq.push("J5", 3);

    // Steps 7-8
    cout << "Step 7 POP: " << pq.pop() << '\n';
    cout << "Step 8 POP: " << pq.pop() << '\n';

    // Step 9
    pq.push("J6", 2);

    // Steps 10-12
    cout << "Step 10 POP: " << pq.pop() << '\n';
    cout << "Step 11 POP: " << pq.pop() << '\n';
    cout << "Step 12 POP: " << pq.pop() << '\n';

    cout << "\nPART (b): Priority-only heap\n";

    BadQueue bad;

    bad.push("A", 1);
    bad.push("B", 1);
    bad.push("C", 1);

    cout << "First POP: " << bad.pop() << '\n';
    cout << "Second POP: " << bad.pop() << '\n';
    cout << "Third POP: " << bad.pop() << '\n';

    return 0;
}
