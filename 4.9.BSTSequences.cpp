#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {

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


void weaveList(vector<int> first, vector<int> second, vector<vector<int>> &results, vector<int> prefix){

    if(first.size() == 0 || second.size() == 0){
        vector<int> result;
        result = prefix;
        result.insert(result.end(), first.begin(), first.end());
        result.insert(result.end(), second.begin(), second.end());
        results.push_back(result);
        return;
    }

    int headFirst = first.front();
    first.erase(first.begin());
    prefix.push_back(headFirst);
    weaveList(first, second, results, prefix);
    prefix.pop_back();
    first.insert(first.begin(), headFirst);

    int headSecond = second.front();
    second.erase(second.begin());
    prefix.push_back(headSecond);
    weaveList(first, second, results, prefix);
    prefix.pop_back();
    second.insert(second.begin(), headSecond);

}



vector<vector<int>> findAllSeq(Node* ptr)
{
    vector<vector<int>> results;

    if (ptr == NULL) {
        vector<int> seq;
        vector<vector<int>> v;
        v.push_back(seq);
        return v;
    }

    vector<int> prefix;
    prefix.push_back(ptr->data);
    
    vector<vector<int>> leftSeq  = findAllSeq(ptr->left);
    vector<vector<int>> rightSeq = findAllSeq(ptr->right);

    for(vector<int> left : leftSeq){
        for(vector<int> right : rightSeq){
            vector<vector<int>> weaved;
            weaveList(left, right, weaved, prefix);
            results.insert(results.end(), weaved.begin(), weaved.end());
        }
    }

    return results;

}

int main(){

    Node* root;
    root = newNode(5);
    root->left = newNode(4);
    root->left->left = newNode(1);
    root->right = newNode(7);
    root->right->left = newNode(6);
    root->right->right = newNode(10);
    vector<vector<int>> results = findAllSeq(root);
    for(int i = 0; i < results.size(); i++){
        for(int j = 0; j < results[i].size(); j++){
                    cout<<results[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}