#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

typedef struct Node *Tlist;

void insertStart(Tlist &list, int dat){
    
    Tlist q;
    q = new Node();
    q->data = dat;
    q->next = list;
    list = q;
}

void insertEnd(Tlist &list, int value)
{
    Tlist t, q = new Node();
 
    q->data = value;
    q->next = NULL;
 
    if(list == NULL){
    
        list = q;
    
    }else{
    
        t = list;
        while(t->next != NULL){
            
            t = t->next;
        }
        t->next = q;
    
    }
}

void delRepeatElements(Tlist &list, int val){

    Tlist q, ant;
    q = list;
    ant = list;
    int aux = 0;
    while(q != NULL){
        aux = q->data;
        if(q->data == val){

            if(q == list){

                list = list->next;
                delete(q);
                q = list;

            }else{

                ant->next = q->next;
                delete(q);
                q = ant->next;

            }

        }else{  
            
            ant = q;
            q = q->next;

        }
    }
    cout<<"\n\n Deleted values ... \n\n";

}

void delDuplicate(Tlist &list){

    Tlist q = list;
    while(q != NULL){
        /*Remove all future nodes that have the same value*/
        Tlist runner = q;
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

void printList(Tlist list){
    int i = 0;

    while(list != NULL){
        if(list->next != NULL){
            cout << list->data << " -> ";
        }else{
            cout << list->data;
        }
        list = list->next;
        i++;
    }
}


 Node* nthToLast(Node* head, int k, int &i) { 
    if (head== NULL) { 
        return NULL; 
    } 
    Node* nd = nthToLast(head->next, k, i); 
    i = i + 1; 
    if (i == k) { 
        return head; 
    } 
    return nd; 
    } 
 
 Node* nthToLast(Node* head, int k) { 
    int i = 0; 
    return nthToLast(head, k, i); 
 }

void delMiddleNode(Tlist &list){

    Tlist q = list, aux = list;
    int totalNodes = 0;
        
    while(aux != NULL){
        totalNodes ++;
        aux = aux->next;
    }

    int mid = totalNodes / 2;
    int count = 1;
    while(q != NULL){
        if (count == mid){
            q->next = q->next->next;
        }
        q = q->next;
        count++;
    }

   // q->next = q->next->next;


}
/*
bool palindromeList(Tlist list){

    Tlist q;
    q = list;
    stack <int> s;

    if (q == NULL)
       return false;
    if (q->next == NULL){
        return false;
    }
    
    while (q != NULL){
        s.push(q->data);

        q = q->next;
    }

    while(list != NULL){

        int i = s.top();

        s.pop();

        if(list->data != i){
            return false;
        }
        list = list->next;
    }
    return true;
}*/

bool palindromeList(Tlist lst){

    Tlist q = NULL;
    Tlist aux = NULL;
    q = lst;
    aux = lst;
    stack<int> stk;
    while (q != NULL){

        stk.push(q->data);
        q = q->next;

    }

    while(!stk.empty()){
        if(stk.top() == aux->data ){
            stk.pop();
            aux = aux->next;
        }else{
            return false;
        }

    }
    return true;

}

void sumList(Tlist &list1, Tlist &list2){

   stack <int> a;
   stack <int> b;

   while(list1 != NULL){
       a.push(list1->data);
       list1 = list1->next;
   }

   while(list2 != NULL){
       b.push(list2->data);
       list2 = list2->next;
   }

   int carry = 0;
   Tlist result = new Node();
   while(a.empty() == false || b.empty() == false){

       int d1 = 0, d2 = 0;
       if(a.empty() == false){
           d1 = a.top();
           a.pop();
       } 

       if(b.empty() == false){
           d2 = b.top();
           b.pop();        
       }

       int total = d1 + d2 + carry;
       Tlist tmp = new Node();
       tmp->data = total%10;
       carry = total / 10;
       if (result == NULL){
           result = tmp;
       }else{
           tmp->next = result;
           result = tmp;
       }
   }

   if(carry != 0){
       Tlist temp = new Node();
       temp->data = carry;
       temp->next = result;
       result = temp;
   }
  //printList(result);
  cout<<result->next->next->data;
  cout<<result->next->data;
  cout<<result->data;
 
}

void partition(Tlist &list, int part){

    Tlist beforeStart = NULL;
    Tlist beforeEnd = NULL;
    Tlist afterStart = NULL;
    Tlist afterEnd = NULL;

    while (list != NULL){

        Tlist next = list->next;
        list->next = NULL;

        if(list->data < part ){
            
            if(beforeStart == NULL){
                beforeStart = list;
                beforeEnd = beforeStart;
            }else{
                beforeEnd->next = list;
                beforeEnd = list;
            }

        }else{

            if (afterStart == NULL ){
                afterStart = list;
                afterEnd = afterStart;
            }else{

                afterEnd->next = list;
                afterEnd = list;
            }
        }
        list = next;
    }

    if (beforeStart == NULL){

        list = afterStart;

    }

    beforeEnd->next = afterStart;
    list = afterStart;

}


Tlist intersection(Tlist &lst1, Tlist &lst2){
    Tlist q = NULL; Tlist t = NULL;
    Tlist aux = lst2;
    
    while(lst1 != NULL){
        Tlist runner = lst2;
        while(runner != NULL){
            if(runner->data == lst1->data){
                q = runner;
                t = q;
                t->next = NULL;
            }
                
            runner = runner->next;
        }
        lst1 = lst1->next;
        
    }
    if (t != NULL){
        return t;
    }else{
        return NULL;
    }
}


Tlist SumLists(Tlist list1, Tlist list2){

    stack <int> stk1;
    stack <int> stk2;

    while(list1 != NULL){
        stk1.push(list1->data);
        list1 = list1->next;
    }

    while(list2 != NULL){
        stk2.push(list2->data);
        list2 = list2->next;
    }

    int carry = 0;
    Tlist result = NULL;
    while(stk1.empty() == false || stk2.empty() == false){

        int d1 = 0, d2 = 0;
        if(!stk1.empty()){
            d1 = stk1.top();
            stk1.pop();
        }

        if(!stk2.empty()){
            d2 = stk2.top();
            stk2.pop();
        }

        Tlist tmp = new Node();
        int total = d1 + d2 + carry;
        tmp->data = total % 10;
        carry = total / 10;

        if(result == NULL){
            result = tmp;
        }else{
            tmp->next = result;
            result = tmp;
        }
    

    }

    if (carry != 0){
        Tlist tmp = new Node();
        tmp->data = carry;
        tmp->next = result;
        result = tmp;
    }

    /*if(result == NULL)
        return NULL;
    else{
        return result;
    }*/
    return result;
}

int main(){
    
    Tlist lista = NULL;
    Tlist lista1 = NULL;
    Tlist res = NULL;
    insertEnd(lista, 5);
    insertEnd(lista, 6);
    insertEnd(lista, 7);
    insertEnd(lista1, 7);
    insertEnd(lista1, 6);
    insertEnd(lista1, 5);

    res = SumLists(lista, lista1);
    while(res != NULL){
        cout<< res->data;
        res = res->next;
    }
    /*insertEnd(lista1, 8);
    insertEnd(lista1, 6);
    insertEnd(lista1, 3);
    insertEnd(lista1, 7);
    insertEnd(lista1, 5);
    delMiddleNode(lista);
    printList(lista);*/
    /*cout<<endl;
    printList(lista1);
    //partition(lista, 5);
    Tlist q =  intersection(lista, lista1);
    cout<<"\n*********************************"<<endl;
    printList(q);
    bool flag = palindromeList(lista);
    if(flag == true)
        cout<<"It's palindrome"<<endl;
    else
        cout<<"it's not palindrome"<<endl;*/
    //printList(lista);


    return 0;
}