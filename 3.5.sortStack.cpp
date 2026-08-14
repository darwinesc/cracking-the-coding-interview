#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &stk){

    stack<int> tmp;
    while(!stk.empty()){

        int t = stk.top();
        stk.pop();
        while(!tmp.empty() && tmp.top() > t){
            int x = tmp.top();
            tmp.pop();
            stk.push(x);
        }
        tmp.push(t);
    }
    stk = tmp;
}


int main(){

    stack<int> stk;
    stk.push(30);
    stk.push(14);
    stk.push(20);
    stk.push(15);
    stk.push(10);

    sortStack(stk);

    while(!stk.empty()){

        cout<< stk.top() << " ";
        stk.pop();

    }

    return 0;
}