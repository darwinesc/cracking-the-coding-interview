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

int getHigh(Node* root){

    if(root == NULL)
        return 0;
    else{

        int left_h = getHigh(root->left);
        int right_h = getHigh(root->right);

        return max(left_h, right_h) + 1;
    }
    
}

void getListByDeph(Node* root, int level, vector<int> list[]){   

    if(root == NULL)
        return;

    list[level].push_back(root->data);
        
    getListByDeph(root->left, level + 1, list);
    getListByDeph(root->right, level + 1, list);
    
}

void printByDepth(Node* root){

    int h = getHigh(root);
    vector<int> list[h];
    
    getListByDeph(root, 0, list);
    
    for (int v = 0; v < h; ++v){

        cout << "Level " << v + 1 << "\n";
        for (int x = 0; x < list[v].size(); x++)
           cout << list[v][x] << " ";
        printf("\n");
    }

}

int main (){

    Node* root;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(10);
    root->right->right->left = newNode(8);
    root->right->right->right->right = newNode(9);
    root->right->right->left->left = newNode(11);
    root->right->right->left->right = newNode(12);
    root->right->right->left->right->left = newNode(13);
    printByDepth(root);

    return 0;
}