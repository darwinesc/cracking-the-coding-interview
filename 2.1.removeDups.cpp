#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *next;

};

void insert(Node* &node, int val){

    Node* q = new Node();
    q->data = val;
    q->next = node;
    node = q;

}

void print(Node* list){

    while(list != NULL){
        
        cout<< list->data << " ";
        list = list->next;
    }

}

void removeDups(Node* &node){

    Node* q = node;
    while(q != NULL){
        Node* runner = q;
        while(runner->next != NULL){

            if(runner->next->data == q->data){
                runner->next = runner->next->next;
            }else{
                runner = runner->next;
            }

        }
        q = q->next;
    }

}

int factorial(int n){

    if(n < 0)
        return 0;
    else if(n > 1)
        return n*factorial(n - 1);
    return 1;
}

int fibonacci(int n_i){

    if (n_i == 0)
        return 0;
    else if (n_i == 1)
        return 1;
    return fibonacci(n_i - 1) + fibonacci(n_i - 2);

}

bool palindromo(string cad){

    string pal_final = "";
    for(int idx = cad.length() - 1; idx >= 0 ; idx--){
        pal_final = pal_final + cad[idx];
    }
    if(pal_final == cad)
       return true;
    return false;
}

bool pal_recursivo(string cad, int start, int end){

        if(start >= end)
            return true;
        
        if(cad[start] != cad[end])
            return false;

        return pal_recursivo(cad, start + 1, end - 1);

}

void permutation(char * cad, int l) {
    char c;    /* variable auxiliar para intercambio */
    int i, j;  /* variables para bucles */
    int n = strlen(cad);
 
    for(i = 0; i < n-l; i++) {
       if(n-l > 2) 
            permutation(cad, l+1);
       else 
            cout << cad << ", ";
       /* Intercambio de posiciones */
       c = cad[l];
       cad[l] = cad[l+i+1];
       cad[l+i+1] = c;
       if(l+i == n-1) {
          for(j = l; j < n; j++) cad[j] = cad[j+1];
          cad[n] = 0;
       }
    }
 }



int main(){

    char palabra[] = "ABC";
    permutation(palabra, 0);
    // 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144,
    //cout<< "Palindromo: " << pal_recursivo(cad, 0, cad.length() - 1); 
    /*
    Node* q = NULL;
    insert(q, 2);
    insert(q, 4);
    insert(q, 6);
    insert(q, 8);
    insert(q, 8);
    insert(q, 4);
    insert(q, 6);
    print(q);
    cout<<endl;
    removeDups(q);
    print(q);
    */
}