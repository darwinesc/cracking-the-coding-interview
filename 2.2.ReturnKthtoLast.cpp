#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* next;

};

void insert(Node* &node, int val){

    Node* q = new Node();
    q->data = val;
    q->next = node;
    node = q;
}

Node* nthToLast(Node* head, int k, int &i){

    if(head == NULL)
        return NULL;
    
    Node* nd = nthToLast(head->next, k, i);
    i = i + 1;
    if(i == k){
        return head;
    }
    return nd;
}

Node* nthToLast(Node* head, int k){
    int i = 0;
    return nthToLast(head, k, i);
}

int main(){

    Node* q = NULL;
    int n = 5;
    insert(q, 3);
    insert(q, 6);
    insert(q, 9);
    insert(q, 12);
    insert(q, 15);
    insert(q, 18);
    insert(q, 21);
    Node* r = nthToLast(q, n);
    cout << "The node "<<n<<" is "<<r->data;
    return 0;

}