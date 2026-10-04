/*
Question 05: Beauty Product List Management

Description:
Develop a program to manage and merge beauty product records from two branches using Singly Linked Lists. The program should:

* Maintain separate Singly Linked Lists for GlowCare and BeautyHub.
* Store Product ID, Product Name, Category, and Price in each node.
* Add products to each list while maintaining ascending order of Product ID.
* Display both branch lists before merging.
* Merge the two sorted lists into a single master product list by adjusting existing next pointers.
* Handle duplicate Product IDs by retaining the product with the lower price and discarding the other node.
* Display the complete sorted master product list after merging.
* Display the total number of remaining products and the total inventory value.
* Perform all operations using linked-list pointers only.
* Do not use arrays, STL lists, sort(), or any built-in merge function.

*/

#include <iostream>
using namespace std;

struct Node
{
    Node *next;

    int product_id;
    string product_name;
    string category;
    float price;
};

class GlowCare
{
};

class BeautyHub
{
};

int main()
{

    return 0;
}