/*
Question 04: KFC Delivery Rider Management

Description:
Develop a program to manage KFC delivery riders using a circular linked list. The program should:

* Store Rider ID, Rider Name, and Number of Assigned Orders in each node.
* Support insertion at the beginning, end, and a specific position.
* Support deletion from the beginning, end, and a specific position.
* Search for a rider using Rider ID.
* Update the information of an existing rider.
* Display all riders and count the total number of riders.
* Traverse the riders starting from a selected rider.
* Maintain the circular connection after every insertion and deletion.
* Handle an empty list and invalid positions.
* Do not use STL containers such as list or vector.

*/

#include <iostream>
using namespace std;

struct Node
{
    Node *next;

    int riderID;
    string rider_name;
    int no_of_assigned_orders;
};

class Linked_list
{
public:
    int no_of_riders = 0;
    Node *head;

    // default constructor
    Linked_list()
    {
        head = NULL;
        no_of_riders = 0;
    }

    // insert at the beginning functions
    void insert_begin(Node *&head, int id, string name, int orders)
    {
        Node *new_node = new Node;

        new_node->riderID = id;
        new_node->rider_name = name;
        new_node->no_of_assigned_orders = orders;

        if (head == NULL)
        {
            head = new_node;
            new_node->next = head;
            no_of_riders++;
            return;
        }

        Node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        new_node->next = head;
        temp->next = new_node;
        head = new_node;

        no_of_riders++;
    }

    // insertion at any specific position
    void insert_position(Node *&head, int position, int id, string name, int orders)
    {
        Node *new_node = new Node;
        new_node->riderID = id;
        new_node->rider_name = name;
        new_node->no_of_assigned_orders = orders;

        if (position < 1 || position > no_of_riders + 1)
        {
            cout << "Invalid position." << endl;
            delete new_node;
            return;
        }

        if (head == NULL)
        {
            if (position == 1)
            {
                head = new_node;
                new_node->next = head;
                no_of_riders++;
            }
            else
            {
                cout << "Invalid position." << endl;
                delete new_node;
            }

            return;
        }

        Node *temp = head;

        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;

            if (temp == head)
            {
                cout << "Invalid position" << endl;
                return;
            }
        }

        new_node->next = temp->next;
        temp->next = new_node; // last element should also point to new head

        no_of_riders++;
    }

    // insert at the end functions
    void insert_end(Node *&head, int id, string name, int orders)
    {
        Node *new_node = new Node;
        new_node->riderID = id;
        new_node->rider_name = name;
        new_node->no_of_assigned_orders = orders;

        if (head == NULL)
        {
            head = new_node;
            new_node->next = head;
            no_of_riders++;
            return;
        }

        Node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->next = head;

        no_of_riders++;
    }

    // delete at the beginning functions
    void delete_begin(Node *&head)
    {
        if (head == NULL)
        {
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = NULL;
            no_of_riders--;
            return;
        }

        Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }

        Node *temp = head;

        head = head->next;
        last->next = head;

        delete temp;
        no_of_riders--;
    }

    // delete at any specific position
    void delete_position(Node *&head, int position)
    {

        if (position < 1 || position > no_of_riders)
        {
            cout << "Invalid position." << endl;
            return;
        }

        if (head == NULL)
        {
            return;
        }

        if (position == 1)
        {
            delete_begin(head);
            return;
        }

        Node *temp = head;

        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;

            if (temp->next == head)
            {
                cout << "Invalid position." << endl;
                return;
            }
        }

        Node *to_delete = temp->next;
        temp->next = to_delete->next;

        delete to_delete;
        no_of_riders--;
    }

    // delete at the end functions
    void delete_end(Node *&head)
    {
        // checking for empty list
        if (head == NULL)
        {
            return;
        }

        // only one node
        if (head->next == head)
        {
            delete head;
            head = NULL;
            no_of_riders--;
            return;
        }

        Node *temp = head;

        // temp->next->next == head means temp->next is the last node.
        while (temp->next->next != head)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = head;

        no_of_riders--;
    }

    // Searching for a rider
    void search(Node *&head, int id)
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;

        do
        {
            if (id == temp->riderID)
            {
                cout << "Rider found!" << endl;
                cout << "Rider Id: " << temp->riderID << endl;
                cout << "Rider Name: " << temp->rider_name << endl;
                cout << "Number of orders: " << temp->no_of_assigned_orders << endl;
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Rider not found." << endl;
        ;
    }

    // update rider info
    void update(Node *&head, int id)
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *temp_node = head;

        do
        {
            if (temp_node->riderID == id)
            {
                cout << "Enter new id: ";
                cin >> temp_node->riderID;

                cout << "Enter new name: ";
                cin >> temp_node->rider_name;

                cout << "Enter num of orders: ";
                cin >> temp_node->no_of_assigned_orders;

                cout << "Rider's info updated successfully!" << endl;
                return;
            }

            temp_node = temp_node->next;
        } while (temp_node != head);

        cout << "Rider not found." << endl;
    }
    // display all riders
    void display(Node *&head)
    {
        if (head == NULL)
        {
            return;
        }

        Node *temp = head;

        do
        {
            cout << "Rider ID: " << temp->riderID << endl;
            cout << "Rider Name: " << temp->rider_name << endl;
            cout << "Assigned Orders: " << temp->no_of_assigned_orders << endl;
            cout << "----------------------" << endl;

            temp = temp->next;
        } while (temp != head);
        cout << "Total riders = " << no_of_riders << endl;
    }
    // traversing the riders -- > starting from a selected rider.
    void traverse(Node *&head, int id)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *start = head;

        // Find the rider from which traversal should start
        do
        {
            if (start->riderID == id)
            {
                break;
            }

            start = start->next;

        } while (start != head);

        // Rider not found
        if (start->riderID != id)
        {
            cout << "Rider not found." << endl;
            return;
        }

        // Traverse from selected rider
        Node *temp = start;

        cout << "Traversal starting from Rider " << id << ":" << endl;

        do
        {
            cout << temp->riderID << " -> ";

            temp = temp->next;

        } while (temp != start);

        cout << "back to " << start->riderID << endl;
    }
};

int main()
{
    Linked_list riders;

    int choice;

    do
    {
        cout << "\n========== KFC RIDER MANAGEMENT SYSTEM ==========\n";
        cout << "1. Insert Rider at Beginning" << endl;
        cout << "2. Insert Rider at End" << endl;
        cout << "3. Insert Rider at Specific Position" << endl;
        cout << "4. Delete Rider from Beginning" << endl;
        cout << "5. Delete Rider from End" << endl;
        cout << "6. Delete Rider from Specific Position" << endl;
        cout << "7. Search Rider" << endl;
        cout << "8. Update Rider Information" << endl;
        cout << "9. Display All Riders" << endl;
        cout << "10. Count Total Riders" << endl;
        cout << "11. Traverse from Selected Rider" << endl;
        cout << "12. Exit" << endl;
        cout << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id, orders;
            string name;

            cout << "Enter Rider ID: ";
            cin >> id;

            cout << "Enter Rider Name: ";
            cin >> name;

            cout << "Enter Number of Assigned Orders: ";
            cin >> orders;

            riders.insert_begin(riders.head, id, name, orders);

            cout << "Rider inserted successfully.\n";
            break;
        }

        case 2:
        {
            int id, orders;
            string name;

            cout << "Enter Rider ID: ";
            cin >> id;

            cout << "Enter Rider Name: ";
            cin >> name;

            cout << "Enter Number of Assigned Orders: ";
            cin >> orders;

            riders.insert_end(riders.head, id, name, orders);

            cout << "Rider inserted successfully.\n";
            break;
        }

        case 3:
        {
            int position, id, orders;
            string name;

            cout << "Enter position: ";
            cin >> position;

            cout << "Enter Rider ID: ";
            cin >> id;

            cout << "Enter Rider Name: ";
            cin >> name;

            cout << "Enter Number of Assigned Orders: ";
            cin >> orders;

            riders.insert_position(riders.head, position, id, name, orders);

            break;
        }

        case 4:
        {
            riders.delete_begin(riders.head);
            cout << "Rider deleted from beginning.\n";
            break;
        }

        case 5:
        {
            riders.delete_end(riders.head);
            cout << "Rider deleted from end.\n";
            break;
        }

        case 6:
        {
            int position;

            cout << "Enter position to delete: ";
            cin >> position;

            riders.delete_position(riders.head, position);

            break;
        }

        case 7:
        {
            int id;

            cout << "Enter Rider ID to search: ";
            cin >> id;

            riders.search(riders.head, id);

            break;
        }

        case 8:
        {
            int id;

            cout << "Enter Rider ID to update: ";
            cin >> id;

            riders.update(riders.head, id);

            break;
        }

        case 9:
        {
            riders.display(riders.head);
            break;
        }

        case 10:
        {
            cout << "Total riders = " << riders.no_of_riders << endl;
            break;
        }

        case 11:
        {
            int id;

            cout << "Enter Rider ID to start traversal from: ";
            cin >> id;

            riders.traverse(riders.head, id);

            break;
        }

        case 12:
        {
            cout << "Exiting program...\n";
            break;
        }

        default:
        {
            cout << "Invalid choice. Please try again.\n";
        }
        }

    } while (choice != 0);

    return 0;
}