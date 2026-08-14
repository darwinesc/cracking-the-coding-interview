#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct Node{

    int data;
    Node* left;
    Node* right;

};


Node* newNode(int val){

    Node* node = new Node();
    node->data = val;
    node->left = NULL;
    node->right = NULL;

    return node;

}

Node* insert(Node* root, int val){

    if(root == NULL)
        return newNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;

}

void traversalTreeLeft(Node* root){

    if(root == NULL)
        return;
    
    cout<< root->data << " ";
    traversalTreeLeft(root->left);
    traversalTreeLeft(root->right);

}


bool checkSubTree(Node* root1, Node* root2){

    if(root1 == NULL && root2 == NULL)
       return true;

    if(root1 == NULL || root2 == NULL)
        return false;

    if (root1->data == root2->data && checkSubTree(root1->left, root2->left) && checkSubTree(root1->right, root2->right))
        return true;

    return false;
}

bool isSubtree(Node* r1, Node* r2){

    if(r2 == NULL)
        return true;
    
    if(r1 == NULL)
        return false;

    if(checkSubTree(r1, r2))
        return true;

    if(isSubtree(r1->left, r2) || isSubtree(r1->right, r2))
        return true;
    
    return false;
}


int main() {

    Node* root1; 
    Node* root2;
    root1 = newNode(1);
    /*Tree 1*/
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(6);
    root1->right->right = newNode(7);
    root1->left->left->left = newNode(8);
    root1->left->left->right = newNode(9);
    /* Tree 2*/
    root2 = newNode(3);
    root2->left = newNode(6);
    root2->right = newNode(7);
  
    if(isSubtree(root1, root2))
        cout << "T2 it's a subtree of T1";
    else
        cout << "T2 isn't a subtree of T2";
    return 0;
}