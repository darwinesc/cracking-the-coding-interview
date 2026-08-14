#include <bits/stdc++.h>
using namespace std;

struct MyStack {

    stack <int> s;
    int minElem;

    void getMin(){
        if (s.empty())
            cout<< "Stack is empty";
        else
            cout<< "Minimun element in the stack is: "
                << minElem;
    }

    void peek(){
        if (s.empty())
            cout<< "Stack is empty";
        int t = s.top();
        cout<<" Top most element is: ";

        (t < minElem)? cout<<minElem : cout << t;
        
    }

    void pop() {

        if (s.empty()){
            cout <<  "Stack empty";
            return;
        }

        cout << "Top most Element removed";
        int t = s.top();
        s.pop();

        if (t < minElem){
        
            cout << minElem << "\n";
            minElem = 2*minElem - t;
        }else{

            cout << t << "\n";
        }

    }

    void push (int x){

        if (s.empty()){

            minElem = x;
            s.push(x);
            cout << "Number inserted: " <<  x;
            return;

        }

        if (x < minElem){

            s.push(2*x - minElem);
            minElem = x;

        }else{

            s.push(x);

        }
        cout << "Number inserted: "<< x;

    }

};

int main(){

    MyStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();
 
    return 0;

}