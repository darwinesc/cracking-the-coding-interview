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

bool findLCAPath(Node* root, vector<int> &path, int val){

    if (root == NULL)
        return false;
    path.push_back(root->data);
    if(root->data == val)
        return true;

    if(root->left != NULL && findLCAPath(root->left, path, val))
        return true;

    if(root->right != NULL && findLCAPath(root->right, path, val))
        return true;
    
    path.pop_back();
    return false;
}

void findLCA(Node* root, int n1, int n2){

    vector<int> path1, path2;
    int i;
    if(!findLCAPath(root, path1, n1) || !findLCAPath(root, path2, n2))
        return;
    
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if(path1[i] != path2[i])
            break;

    cout << path1[i - 1];
}

void inOrder(Node* root){

    if (root == NULL)
        return;

    cout <<root->data << " ";
    inOrder(root->left);
    inOrder(root->right);

}

Node* getLCA(Node* root, int n1, int n2){

    if (root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    Node* left_lca = getLCA(root->left, n1, n2);
    Node* right_lca = getLCA(root->right, n1, n2);

    if(left_lca != NULL && right_lca != NULL)
        return root;

    if(left_lca != NULL)
        return left_lca;
    else
        return right_lca;


}

int main(){

    Node *root;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    cout << getLCA(root, 8, 5)->data;
    //inOrder(root);
    return 0;
}