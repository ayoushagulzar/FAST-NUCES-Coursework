// Solve the following problem using a Singly Linked List:
// Given a Linked List of integers (input by user), write a function to modify the linked list such
// that all even numbers appear before all the odd numbers in the modified linked list. Also, keep
// the order of even and odd numbers same.

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

class SinglyList
{
public:
    Node *head;
    Node *tail;

    SinglyList()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL && tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            tail = newNode;
            newNode->next = NULL;
        }
    }

    void display()
    {
        if (head == NULL && tail == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void modify_list()
    {
        if (head == NULL && tail == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        bool hasEven = false;
        bool hasOdd = false;

        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->data % 2 == 0)
                hasEven = true;
            else
                hasOdd = true;

            temp = temp->next;
        }

        if (hasEven == false || hasOdd == false)
        {
            display();
            return;
        }

        // Print all even numbers first
        temp = head;

        while (temp != NULL)
        {
            if (temp->data % 2 == 0)
            {
                cout << temp->data << " -> ";
            }

            temp = temp->next;
        }

        // Print all odd numbers after evens
        temp = head;

        while (temp != NULL)
        {
            if (temp->data % 2 != 0)
            {
                cout << temp->data << " -> ";
            }

            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    int n, value;
    SinglyList list;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value of node " << i + 1 << " : ";
        cin >> value;
        list.insert(value);
    }

    cout << "\nOriginal List: ";
    list.display();

    cout << "\nModified List: ";
    list.modify_list();


    return 0;
}