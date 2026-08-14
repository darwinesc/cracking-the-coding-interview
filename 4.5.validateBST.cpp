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

bool validateBST(Node* root, Node* l = NULL, Node* r = NULL){

    if(root == NULL)
        return true;
    
    if(l != NULL && l->data > root->data )
        return false;
    if(r != NULL && root->data > r->data)
        return false;
    if(!validateBST(root->left, l, root) || !validateBST(root->right, root, r))
        return false;
    
    return true;
}

int main(){

    Node *root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->right = newNode(25);

        

    if(validateBST(root,NULL,NULL))
        cout << "It's a BST";
    else
        cout << "It's not a BST";
    return 0;
}
