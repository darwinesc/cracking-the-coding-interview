#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct MyStack{

    stack<int> stk;
    stack<int> stkmin;
    int minElement;

    void getMin(){

        if(stkmin.empty())
            cout << "The stack is empty";
        else
            cout << "THe minimun element is: " << stkmin.top() <<endl;      

    }

    void push(int val){

        if(stk.empty()){
            stk.push(val);
            stkmin.push(val);
        }else{
            stk.push(val);
            int t = stk.top();
            if(t < stkmin.top())
                stkmin.push(t);
        }

    }

    void pop(){

        if(stk.empty())
            cout << "The stack is empty";
        else
            
            if (stk.top() == stkmin.top()){
                stk.pop();
                stkmin.pop();
            }else{
                stk.pop();
            }
    }

};


int main(){

    MyStack s;
    s.push(3);
    s.push(5);
    s.push(2);
    s.push(7);
    s.getMin();

    s.pop();
    s.pop();

    s.getMin();

    return 0;
}