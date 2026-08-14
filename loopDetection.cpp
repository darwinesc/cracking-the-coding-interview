#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node* next;
    bool flag;
};


void insertEnd(Node* &list, int value)
{
    Node* t = new Node(); 
    Node* q = new Node();
 
    q->data = value;
    q->flag = false;
    q->next = NULL;
 
    if(list == NULL){
    
        list = q;
    
    }else{

        t = list;
        while(t->next != NULL){
            
            t = t->next;
        }
        t->next = q;
    
    }

}

bool loopDetection(Node* root){

    while(root != NULL){

        if(root->flag == true)
            return true;

        root->flag = true;
        root = root->next;

    }
    return false;
}


int main (){

    Node* node = NULL;
    insertEnd(node, 20);
    insertEnd(node, 4);
    insertEnd(node, 15);
    insertEnd(node, 10);

    /* Create a loop for testing */
    node->next->next->next->next = node;
 
    if(loopDetection(node))
        cout << "Loop detection";
    else
        cout << "No Loop";

    return 0;

}