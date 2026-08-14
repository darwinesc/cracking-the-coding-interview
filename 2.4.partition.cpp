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

Node* partition(int val, Node* lst){

    Node* head = lst;
    Node* tail = lst;
    while(lst != NULL){
        Node* next = lst->next;
        if(lst->data < val){

            lst->next = head;
            head = lst;

        }else{

            tail->next = lst;
            tail = lst;

        }
        lst = next;
    }
    
    tail->next = NULL;

    return head;


}


int main(){

    Node* q = NULL;
    insert(q, 3);
    insert(q, 5);
    insert(q, 8);
    insert(q, 5);
    insert(q, 10);
    insert(q, 2);
    insert(q, 1);
    Node* aux = NULL;
    cout<<endl;
    aux = partition(5, q);
    print(aux);
}