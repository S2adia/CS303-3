#include<iostream>
using namespace std;


template<typename Item_Type>
struct Node
{
    Item_Type value;
    Node* nextptr;
    Node* prevptr;
    //constructor
    Node(Item_Type item)
    {
        value = item;
        nextptr = nullptr;
        prevptr = nullptr;
    }
    //constructor
    Node()
    {
        nextptr = nullptr;
        prevptr = nullptr;
    }
};

template <typename Item_type>
class DLinkedL
{
public :
    Node<Item_type> * headptr;
    Node<Item_type> * tailptr;
    //function to insert items
    void insert(Item_type value)
    {
        Node<Item_type> * curr = new Node<Item_type>(value);
        if(headptr== nullptr) //check if the list is empty
        {
            headptr = curr; //set headptr and tailptr to new node(curr)
            tailptr = curr;
        }
        else
        {
            //add the new node at the end of the list
            tailptr->nextptr = curr; 
            curr->prevptr = tailptr;
            tailptr = curr;
        }
    }
    //function to print the list
     void display()
    {
    
        Node<Item_type> * cur = headptr;
        while(cur!=nullptr)
        {
            cout<<cur->value<<" "; //print the elements of the list
            cur = cur->nextptr; //update cur value to the next cur value
        }
        cout<<endl;
    }
};
//function for insertion sort
void insertion_sort(DLinkedL<int> * double_list)
{
    int key;
    bool insertionNeeded = false;

    for (Node<int> * cur = double_list->headptr; cur!= nullptr; cur = cur->nextptr)
    {
        key = cur->value;
        insertionNeeded = false; //flag for tracking 
        Node<int> * var;

        for (var=cur->prevptr; var!=nullptr; var=var->prevptr)
        {
            if (key < var->value)
            {
                var->nextptr->value = var->value; // larger values move right
                insertionNeeded = true;
            }
            else
                break;
        }
        if (insertionNeeded) //Put key into its proper location
        {
            if(var== nullptr)
            {
                double_list->headptr->value = key;
            }
            else
            {
                var->nextptr->value = key;
            }
        }
    }
}


int main()
{
    DLinkedL<int> * list_d = new DLinkedL<int>(); //doubly linked list that holds integars
    //insert integar values to the list
    list_d->insert(85);
    list_d->insert(2);
    list_d->insert(5);
    list_d->insert(12);
    list_d->insert(55);
    list_d->insert(9);
    //print the list before insertion sort
    list_d->display();
    insertion_sort(list_d);
    //print the list after insertion sort
    list_d->display();

}
