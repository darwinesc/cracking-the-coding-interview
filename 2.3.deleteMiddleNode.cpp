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

void delMiddle(Node* &q){

    int count = 0;
    int count1 = 1;
    Node* node = q;
    Node* aux = q;
    while(node != NULL){
        count++;
        node = node->next;
    }
    int mid = count / 2;
    
    while(aux->next != NULL){

        if(mid == count1){
            aux->next = aux->next->next;
        }
        count1++;
        aux = aux->next;
    }
}


int main(){

    Node* q = NULL;
    insert(q, 3);
    insert(q, 6);
    insert(q, 9);
    insert(q, 12);
    insert(q, 15);
    insert(q, 18);
    insert(q, 21);
    print(q);
    cout<<endl;
    delMiddle(q);
    print(q);
}