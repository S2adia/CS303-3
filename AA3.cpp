#include"AA3.h"

template<typename Item_Type> 
CQ :: queue<Item_Type> :: queue(){
    size_t initial_capacity = DEFAULT_CAPACITY;
    capacity = initial_capacity;
    num_items = 0;
    front_index = 0;
    rear_index = capacity - 1;
    the_data = new Item_Type[capacity];
}

template<typename Item_Type> 
void CQ :: queue<Item_Type> :: Push(const Item_Type& item){
    if (num_items == capacity) { //check if the number of items is equal to the current capacity of the queue
        reallocate(); //call the reallocate function to increase the capacity of the queue
    }
    num_items++; 
    rear_index = (rear_index + 1) % capacity; //updating the last index where new item will be added
    the_data[rear_index] = item; //insert the new item at the end of the queue
}

template<typename Item_Type> 
void CQ :: queue<Item_Type> :: reallocate(){ 
    size_t new_capacity = 2 * capacity;
    Item_Type* new_data = new Item_Type[new_capacity]; //new array
    //copy elements to the new array
    size_t j = front_index;
    for (size_t i = 0; i < num_items; i++) {
        new_data[i] = the_data[j];
        j = (j + 1) % capacity;
    }
    //update front and rear index and capacity
    front_index = 0;
    rear_index = num_items - 1;
    capacity = new_capacity;
    //swap the array pointer
    std::swap(the_data, new_data);
    delete[] new_data;
}

template<typename Item_Type> 
void CQ :: queue<Item_Type> :: Pop(){
    front_index = (front_index + 1) % capacity; //update the front index
    num_items--; //decrement the number of items 
}
template<typename Item_Type>
Item_Type CQ :: queue<Item_Type>:: Front() {
    if (num_items == 0) { //check if the queue is empty
        throw runtime_error("Queue is empty");
    }
    return the_data[front_index]; //return the front item
}
template<typename Item_Type>
size_t CQ :: queue<Item_Type> :: Size(){
    return num_items; 
}
template<typename Item_Type>
bool CQ :: queue<Item_Type> :: Empty(){
    if(num_items == 0){ //check if the queue is empty
        return true;
    }
    else{
        return false;
    }
}

template<typename Item_Type>
void CQ :: queue<Item_Type> :: move_to_rear(){
    if(num_items == 0){ //check if the queue is empty
        throw out_of_range("There are no items in the queue");
    }
    Item_Type front_val = Front(); //store the front item 
    Pop(); //delete the front item
    Push(front_val); //push the front item at the end of the queue
}

