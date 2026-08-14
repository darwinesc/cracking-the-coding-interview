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


void generateRandom(Node* root, vector<int> &nodes){

    //vector<int> nodes;
    if(root == NULL){
        return;
    }

    generateRandom(root->left, nodes);
    nodes.push_back(root->data);
    generateRandom(root->right, nodes);

   // return nodes;
} 


int getRandomNode(Node* root){

    vector<int> array_nodes;
    generateRandom(root, array_nodes);

    for(int i = 0; i < array_nodes.size(); i++){
     //   cout << array_nodes[i];
    }
    srand(time(0));
    int random_index = (rand() % array_nodes.size()) + 1;

    return array_nodes[random_index];

}

int main() {

    Node* root1; 
    root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(6);
    root1->right->right = newNode(7);
    root1->left->left->left = newNode(8);
    root1->left->left->right = newNode(9);
    cout << "The random node is: " << getRandomNode(root1);
    return 0;
}