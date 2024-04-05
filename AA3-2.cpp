#include<iostream>
#include<vector>
using namespace std;

int linear_search(vector<int>& items, int target, size_t pos_l)
{
    if (pos_l ==0) //if the item is not found
        return -1;
      

    if (target == items[pos_l]) //check if the item is found then return the index of the last occurence of the item 
        return pos_l;
      
    return linear_search(items, target, pos_l - 1); //call the recusive function to search for the item in the previous positions
}


int main()
{
    vector<int> v ; // vector of integars
    //push integar values to the vector
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(4);
    v.push_back(5);
    v.push_back(20);
    cout<<linear_search(v, 30, v.size()-1)<<endl; //call the recursive function
    cout<<linear_search(v, 20, v.size()-1)<<endl; //call the recursive function
    cout<<linear_search(v, 9, v.size()-1)<<endl; //call the recursive function
}
