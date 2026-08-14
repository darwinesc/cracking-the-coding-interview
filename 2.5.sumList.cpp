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

        cout << q->data<< " ";
        q = q->next;
    }
}

Node* sumList(Node* lst1, Node* lst2){

    stack<int> stk1;
    stack<int> stk2;

    while(lst1 != NULL){
        stk1.push(lst1->data);
        lst1 = lst1->next;
    }

    while(lst2 != NULL){
        stk2.push(lst2->data);
        lst2 = lst2->next;
    }

    int digit1 = 0;
    int digit2 = 0;
    int carry = 0;
    Node* result = NULL;
    while(!stk1.empty() || !stk2.empty()){
        
        if(!stk1.empty()){
            digit1 = stk1.top();
            stk1.pop();
        }

        if(!stk2.empty()){
            digit2 = stk2.top();
            stk2.pop();
        }
        
        int sum = digit1 + digit2 + carry;
        int total = sum % 10;
        carry = sum / 10;
        Node* tmp = new Node();
        tmp->data = total;
        if(result == NULL){
            result = tmp;
        }else{
            tmp->next = result;
            result = tmp;
        }
    }


    if(carry != 0){
        Node* tmp = new Node();
        tmp->data = carry;
        tmp->next = tmp;
        result = tmp;
    }

    

    return result;
}


int main(){

    Node* lst1 = NULL;
    Node* lst2 = NULL;
    Node* sum = NULL;
    insert(lst1, 7);
    insert(lst1, 1);
    insert(lst1, 6);
    insert(lst2, 5);
    insert(lst2, 9);
    insert(lst2, 2);
    sum = sumList(lst1, lst2);
    cout<< "The sum: ";
    print(lst1);
    cout<< " between ";
    print(lst2);
    cout << " is: ";
    while(sum != NULL){
       cout << sum->data << " ";
       sum = sum->next;
    }
    
}