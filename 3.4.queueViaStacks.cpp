#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct MyQueue{

    stack<int> stk1;
    stack<int> stk2;

    void enqueue(int val){

        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }

        stk1.push(val);

        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        
    }

    void dequeue(){
        if(!stk1.empty()){
            cout << "Element " << stk1.top()<< " was removed" <<endl;
            stk1.pop();
        }else{
            cout << "The queue is empty"<<endl;
        }

    }

    void peek(){ 

        if(!stk1.empty()){
            int t = stk2.top();
            cout << "First in the queue is: "<< t <<endl;
        }

    }

    void printQueue(){

        while(!stk1.empty()){

            cout<< stk1.top() << " ";
            stk1.pop();
        }

    }



};


int main(){

    MyQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

  //  q.printQueue();

    q.dequeue();

    q.printQueue();

    q.peek();
    return 0;
}