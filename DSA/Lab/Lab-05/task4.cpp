// An airport boarding gate has limited space for passengers waiting to board an aircraft. The passengers
// are managed according to their arrival order, where the passenger who arrives first is boarded first.
// The gate has a capacity of six passengers and uses a circular queue to efficiently reuse the positions
// that become available after passengers are boarded. Initially, passengers with IDs 101, 102, 103, 104,
// 105, and 106 enter the boarding queue. The first three passengers are then boarded, after which
// passengers 107, 108, and 109 arrive at the gate. The boarding process continues with two more
// passengers being boarded, followed by the arrival of passenger 110. One more passenger is then
// boarded, after which passengers 111 and 112 arrive. Implement this scenario using an array-based
// circular queue and display the final passengers in their actual boarding order along with the final front
// and rear positions.

#include <iostream>
using namespace std;

#define MAX 6

class Queue
{
public:
    int queue[MAX];
    int front;
    int rear;
    int number; // current no of elements in a queue

    Queue()
    {
        front = -1;
        rear = -1;
        number = 0;
    }

    bool isEmpty()
    {
        return number == 0;
    }

    bool isFull()
    {
        return number == MAX;
    }

    void arrived(int id)
    {
        if (isFull())
        {
            cout << "Queue Overflow!" << endl;
            return;
        }

        rear = (rear + 1) % MAX;
        queue[rear] = id;
        number++;
    }

    int boarded()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return -1;
        }

        front = (front + 1) % MAX;
        number--;

        return queue[front];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        int index = (front + 1) % MAX;

        cout << "Queue: ";
        for (int i = 0; i < number; i++)
        {
            cout << queue[index] << " ";
            index = (index + 1) % MAX;
        }
        cout << endl;
        cout << "Front: " << (front + 1) % MAX << endl;
        cout << "Rear: " << rear << endl;
    }
};

int main()
{

    Queue passengers;

    passengers.arrived(101);
    passengers.arrived(102);
    passengers.arrived(103);
    passengers.arrived(104);
    passengers.arrived(105);
    passengers.arrived(106);

    passengers.boarded();
    passengers.boarded();
    passengers.boarded();

    passengers.arrived(107);
    passengers.arrived(108);
    passengers.arrived(109);

    passengers.boarded();
    passengers.boarded();

    passengers.arrived(110);
    passengers.boarded();

    passengers.arrived(111);
    passengers.arrived(112);

    passengers.display();

    return 0;
}