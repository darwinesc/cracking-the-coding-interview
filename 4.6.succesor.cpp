#include <iostream>
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


void printInorder(Node* root){

    if(root == NULL)
        return;

    printInorder(root->left);
    cout << root->data;
    printInorder(root->right);

}

 Node* insert(Node* node, int val){

    if(node == NULL)
        return (newNode(val));
    else{
        
        if(val <= node->data)
            node->left = insert(node->left, val);

        else if(node->data < val)
            node->right = insert(node->right, val);
    }

    return node;       

}


Node* getMin(Node* node){

    Node* aux = node;
    while(aux->left != NULL){

        aux = aux->left;

    }

    return aux;

}

void inOrder(Node* node){

    if (node == NULL)
        return;

    inOrder(node->left);
    cout<< node->data << " ";
    inOrder(node->right);
}

Node* inOrderSuccesor(Node* root, Node* node){

    if(node->right != NULL)
        return getMin(node->right);

    Node* succ = NULL;
    while(root != NULL){

        if(node->data < root->data){
            succ = root;
            root = root->left;

        }
        else if (node->data > root->data){

            root = root->right;

        }
        else 
            break;
    }
    return succ;

}

int main()
{
   
   Node* root;
   Node* temp;
   Node* succ;
   root = insert(root, 20);
   root = insert(root, 8);
   root = insert(root, 22);
   root = insert(root, 4);
   root = insert(root, 12);
   root = insert(root, 10);
   root = insert(root, 14);
   temp = root->left->right->right;
   succ = inOrderSuccesor(root, temp);
   
   if(succ != NULL)
       cout << "\n Inorder Successor of "<< temp->data << " is "<< succ->data;
    else
        cout << "There is not successor";
   return 0;

}