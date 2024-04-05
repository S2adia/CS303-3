#include<iostream>
using namespace std;
#include"AA3.cpp"

int main(){
    CQ:: queue<int> q;
    //pushing integar values to the queue
    q.Push(10);
    q.Push(20);
    q.Push(30);
    q.Push(40);
    q.Push(50);
    q.Push(60);
    q.Push(70);
    q.Push(80);
    q.Push(90);
    q.Push(100);
    //displaying the elements
    while(q.Size()!=0){
        cout<<q.Front()<<endl;
        q.Pop();
    }
    q.Push(11);
    q.Push(12);
    q.Push(13);
    q.move_to_rear(); 
    //displaying the elements
    while(q.Size()!=0){
        cout<<q.Front()<<endl;
        q.Pop();
    }
}