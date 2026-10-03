// Create a circular link list and perform the mentioned tasks:
//     i. Insert a new node at the end of the list.
//     ii. Insert a new node at the beginning of list.
//     iii. Insert a new node at given position.
//     iv. Delete any node.
//     v. Print the complete circular link list.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class CircularList
{
public:
    Node *head;
    Node *tail;

    CircularList()
    {
        head = NULL;
        tail = NULL;
    }

    // INSERT AT END
    void insertEnd(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL && tail == NULL)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }

        tail->next = newNode;
        tail = tail->next;
        tail->next = head;
    }

    // INSERT AT FRONT
    void insertFront(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL && tail == NULL)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }

        tail->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    // INSERT AT ANY POSITION
    void insertPos(int value, int pos)
    {
        if (pos < 1)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        if (pos == 1)
        {
            insertFront(value);
            return;
        }

        Node *newNode = new Node(value);

        if (head == NULL && tail == NULL)
        {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != tail; i++)
        {
            temp = temp->next;
        }

        if (temp == tail && pos != 2)
        {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == tail)
        {
            tail = newNode;
        }
    }

    // DELETE ANY NODE
    void deleteNode(int pos)
    {
        if (pos < 1)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        if (head == NULL && tail == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (pos == 1)
        {
            Node *temp = head;

            if (head == tail)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                head = head->next;
                tail->next = head;
            }

            delete temp;
            return;
        }

        Node *temp = head;

        for (int i = 1; i < pos - 1 && temp != tail; i++)
        {
            temp = temp->next;
        }

        if (temp == tail)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        Node *target = temp->next;
        temp->next = target->next;

        if (target == tail)
        {
            tail = temp;
        }

        delete target;
    }

    // PRINT LIST
    void print()
    {
        if (head == NULL && tail == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *temp = head;
        while (temp != tail)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << temp->data << " -> HEAD" << endl;
    }
};

int main()
{
    CircularList list;
    int choice, value, pos;

    do
    {
        cout << "\n===== Circular Linked List =====" << endl;
        cout << "1. Insert at End" << endl;
        cout << "2. Insert at Beginning" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete Node" << endl;
        cout << "5. Print List" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertEnd(value);
            cout << endl;
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertFront(value);
            cout << endl;
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> pos;
            list.insertPos(value, pos);
            cout << endl;
            break;

        case 4:
            cout << "Enter position to delete: ";
            cin >> pos;
            list.deleteNode(pos);
            cout << endl;
            break;

        case 5:
            cout << "List: ";
            list.print();
            cout << endl;
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}