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


Node* createTree(int arr[], int start, int end){

    if(start > end)
        return NULL;

    int middle = (start + end) / 2;
    Node* node = newNode(arr[middle]);

    node->left = createTree(arr, start, middle - 1);

    node->right = createTree(arr, middle + 1, end);

    return node;

}

void printInorder(Node* root){

    if(root == NULL)
        return;

    printInorder(root->left);
    cout << root->data;
    printInorder(root->right);

}



int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

    int size = sizeof(arr) / sizeof(arr[0]);

    Node* root = createTree(arr, 0, size - 1);
    cout << "Inorder traversal of constructed BST \n";
    printInorder(root);

    return 0;

}
