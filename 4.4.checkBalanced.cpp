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

int getHeight(Node* root){

    if(root == NULL)
        return 0;
    else{

        int left = getHeight(root->left);
        int right = getHeight(root->right);

        return max(right, left) + 1;
    }
}

bool checkBalanced(Node* node){

if(node == NULL)
    return true;

int h_left = getHeight(node->left);
int h_right = getHeight(node->right);

if(abs(h_left - h_right) <= 1)
    return true;

return false;
}


int main()
{
    
    Node* root;
    root = newNode(1);
    root->left = newNode(2);
    //root->right = newNode(3);
    root->left->left = newNode(4);
   // root->left->left->right = newNode(14);
    root->left->left->left = newNode(51);
     root->left->left->left->left = newNode(52);
    /*root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->right->left = newNode(7);
    root->right->left->right = newNode(8);
    root->right->left->right->left = newNode(18);*/

    if(checkBalanced(root))
        cout << "It's a balanced tree";
    else
        cout << "It's not a balanced tree";
    return 0;

}
