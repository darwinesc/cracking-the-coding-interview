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
    
    if(l != NULL && l->data <= root->data)
        return true;
    if(r != NULL && root->data > r->data)
        return true;
    
    return validateBST(root->left,root, r) and validateBST(root->right, l, root); 
}

int main(){

    Node* root;
    root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->right->right->right = newNode(9);
    root->right->right->right->right->right = newNode(10);

    if(validateBST(root, NULL, NULL))
        cout << "It's a BST";
    else
        cout << "It's not a BST";
    return 0;
}
