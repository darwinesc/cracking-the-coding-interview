#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct Node{

    char data;
    bool flag; 
    Node* next;

};

void insert(char val, Node* &node){

    Node* q = new Node();
    q->data = val;
    q->flag = false;
    q->next = node;
    node = q;

}

void print(Node* node){

    while(node != NULL){

        cout << node->data << " ";
        node = node->next;

    }

}

bool loopDetection(Node* node){

    while(node != NULL ){
        if(node->flag == true)
            return true;
        node->flag = true;
        node = node->next;
    }   
    return false;
}


int main(){

    Node* node = NULL;
    insert('a', node);   
    insert('b', node);
    insert('c', node);
    insert('d', node);
    insert('e', node);
    node->next->next->next->next->next = node;
    //print(node);
    if(loopDetection(node))
        cout << "Loop detected ";
    else
        cout << "No loop";
    return 0;
}