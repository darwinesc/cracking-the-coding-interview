#include <bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &inputStk){

    stack<int> tmpStack;
    while(!inputStk.empty()){

        int tmp = inputStk.top();
        inputStk.pop();
        while(!tmpStack.empty() && tmpStack.top() > tmp){
            int x = tmpStack.top();
            tmpStack.pop();
            inputStk.push(x);
        }
        tmpStack.push(tmp);
    }
    inputStk = tmpStack;
}

int main(){

    stack<int> stk;
    stk.push(25);
    stk.push(10);
    stk.push(54);
    stk.push(32);
    stk.push(4);
    stk.push(95);
    stk.push(1);
    stk.push(42);

    sortStack(stk);

    while (!stk.empty())
    {
        cout << stk.top()<< " ";
        stk.pop();
    }

    return 0;

}