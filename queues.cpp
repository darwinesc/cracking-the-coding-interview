#include <iostream>

using namespace std;

class FixedMultiStack {


    int numberOfStacks = 3;
    int stackCapacity;
    int *values;
    int *sizes;

public:

    FixedMultiStack(int stackSize){
        stackCapacity = stackSize;
        values = new int[stackSize * numberOfStacks];
        sizes = new int[numberOfStacks];
    }

    void push(int stackNum, int value){
        if (isFull(stackNum)){
            cout << "Stack Overflow"
                 << " By element :" << value << endl;
            return;
        }
        sizes[stackNum]++;
        values[indexOfTop(stackNum)] = value;
    } 

    int pop(int stackNum){
        if (isEmpty(stackNum)){
            cout<< "Stack underflow";
            exit(1);
        }
        int topIndex = indexOfTop(stackNum);
        int value = values[topIndex];
        values[topIndex] = 0;
        sizes[stackNum]--;
        return value;
    }


    int top(int stackNum){
        if(isEmpty(stackNum)) {
            cout<<"Stack empty";
        }
        return values[indexOfTop(stackNum)];
    }

    bool isEmpty(int stackNum){
        return sizes[stackNum] == 0;
    }

    bool isFull(int stackNum){
        return sizes[stackNum] == stackCapacity;
    }

    int indexOfTop(int stackNum){
        int offset = stackNum * stackCapacity;
        int size = sizes[stackNum];
        return offset + size - 1;
    }

};

int main(){

   FixedMultiStack ms(5);
   ms.push(3,1);
   ms.push(5,2);
   ms.push(7,1);
   int val = ms.pop(7);
   cout << "Popped element from stack1 is "
         << " : " << val
         << endl;
   /* ts.push2(40);
    cout << "\nPopped element from stack2 is "
         << ": " << ts.pop2()
         << endl;*/
    return 0;

}