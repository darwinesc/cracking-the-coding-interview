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

Node* intersection(Node* lst1, Node* lst2){
    Node* q = NULL;
    while(lst1 != NULL){
        Node* runner = lst2;
        while(runner != NULL){
            if (runner->data == lst1->data){
                q = runner;
                q->next = NULL;
            }
            runner = runner->next;
        }
        lst1 = lst1->next;
    }
    if(q != NULL)
        return q;
    else
        return NULL;

}


int main(){

    Node* lst1 = NULL;
    Node* lst2 = NULL;
    insert(lst1, 2);
    insert(lst1, 4);
    insert(lst1, 6);
    insert(lst1, 8);
    insert(lst1, 10);
    insert(lst1, 12);
    insert(lst2, 3);
    insert(lst2, 6);
    insert(lst2, 9);
    insert(lst2, 12);

    cout << "The number: ";
    Node *tmp = intersection(lst1, lst2);
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    
}