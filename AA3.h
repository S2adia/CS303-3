#include<iostream>
using namespace std;

namespace CQ
{
template<typename Item_Type>
class queue {
    public:
    queue(); //constructor
    void Push(const Item_Type& item); //function to push items into the queue
    void reallocate(); //function to increase the capacity
    void Pop(); //function to remove items from the queue
    Item_Type Front(); //function to return the front/first value of the queue
    size_t Size(); //function to return the size of the queue
    bool Empty(); //function to check if the queue is empty
    void move_to_rear(); //function to move the front value to the rear of the queue
    private:
    //data fields
    static const size_t DEFAULT_CAPACITY = 5;
    size_t capacity;
    size_t num_items;
    size_t front_index;
    size_t rear_index;
    Item_Type* the_data;
};

}