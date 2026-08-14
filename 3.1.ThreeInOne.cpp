#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct MultiStack{

    int num_stacks = 3;
    int stack_capacity;
    int *values;
    int *sizes;

    MultiStack(int stack_size){
        stack_capacity = stack_size;
        values = new int[stack_size * num_stacks];
        sizes = new int[num_stacks]{0};
    }

    void push(int num_stack, int val){
        if(isFull(num_stack))
            cout << "The stack "<<num_stack<<" is full" << endl;
        sizes[num_stack]++;
        values[indexOfTop(num_stack)] = val;
    }

    void pop(int stack_num){

        if(isEmpty(stack_num)){
            cout << "The stack is empty "<< endl;
        }
        int top_index = indexOfTop(stack_num);
        int value = values[top_index];
        values[top_index] = 0;
        sizes[stack_num]--;
    }

    int top(int stack_num){
        if(isEmpty(stack_num)){
            return -1;
        }
        return values[indexOfTop(stack_num)];
    }

    bool isEmpty(int stack_num){
        return sizes[stack_num] == 0;
    }

    bool isFull(int stack_num){
        return sizes[stack_num] == stack_capacity;
    }

    int indexOfTop(int stack_num){

        int offset = stack_num * stack_capacity;
        int size = sizes[stack_num];
        return (offset + size - 1);

    }

};

int main(){
    
    MultiStack ms(3);
    ms.push(0,4);
    ms.push(0,6);
    ms.push(0,1);
    ms.push(1,2);
    ms.push(1,4);
    ms.push(1,6);
    ms.push(2,1);
    ms.push(2,3);
    ms.push(2,5);
    ms.push(0,10);
    for(int i = 0 ; i < ms.num_stacks; i ++){
        cout << "Stack " << i << ":" << endl;
        while(!ms.isEmpty(i)){
            cout << ms.top(i) << " ";
            ms.pop(i);
        }
        cout << endl;
    }

    return 0;
}