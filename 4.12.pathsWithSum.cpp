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

int count_path = 0; 
void checkSum(Node* root, int val, vector<int> &path){
        
    if(root == NULL)
        return;

    path.push_back(root->data);
    //int sum = val - root->data;
    checkSum(root->left, val, path);
    checkSum(root->right, val, path);
    int total = 0;
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " ";
        total = total + path[i];
        if(total == val){
            count_path ++;
        }
    }cout  << endl;

    path.pop_back();

}


int main() {

    Node* root1;
    Node* root;
    vector<int> path;
    root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(6);
    root1->right->right = newNode(7);
    root1->left->left->left = newNode(8);
    root1->left->left->right = newNode(9);

    root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right = newNode(2);
    root->right->left = newNode(2);
    int sum = 21;
    checkSum(root, sum, path);
    cout << "Total of path that sum " << sum << ": " << count_path<< endl;

    return 0;
}