#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {

    int data;
    Node* next;

};

void insert(Node* &node, int val){

    Node* q = new Node();
    q->data = val;
    q->next = node;
    node = q;

}

void print(Node* q){

    while(q != NULL){

        cout << q->data;
        q = q->next;
    }
}

bool isPalindrome(Node* lst){

    Node* q = lst;
    stack<int> stk;
    while(q != NULL){

        stk.push(q->data);
        q = q->next;

    }

    while(lst != NULL){

        int n1 = stk.top();
        int n2 = lst->data;

        if(!stk.empty()){
            if(n1 == n2){
                stk.pop();
            }else{
                return false;
            }

        }
        lst = lst->next;
    }  
    return true;
}


int main(){

    Node* lst = NULL;
    insert(lst, 1);
    insert(lst, 7);
    insert(lst, 1);
    insert(lst, 1);
    cout << "The number: ";
    print(lst);
    if(!isPalindrome(lst))
        cout<< " It's not a palindrome number";
    else
        cout<< "It's a palindrome number"; 
    
}