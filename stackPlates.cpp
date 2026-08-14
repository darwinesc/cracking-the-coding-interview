#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

struct SetOfStacks{

    vector<stack<int>> myStacks;
    int maxSize;
    int current;
    
    SetOfStacks(int n){ maxSize = n; current = 0;}
    ~SetOfStacks(){};

    void push(int data){

        if(myStacks.size() == 0){

            stack<int> newStack;
            myStacks.push_back(newStack);
            myStacks[current].push(data);
        
        }else if (myStacks[current].size() == maxSize){

			stack<int> newStack;
			myStacks.push_back(newStack);
			myStacks[++current].push(data);
		
        }else if (myStacks[current].size() < maxSize){
			myStacks[current].push(data);
		}
        
    }

    void pop(){

        if(myStacks[current].size() > 0){
            myStacks[current].pop();
        }else{

            if(current == 0)
                cout<< "Stack has been empty!" << endl;
            else{

                current--;
                myStacks[current].pop();

            }

        }
    
    }

    int top(){
            return myStacks[current].top();
    }
};

int main (){

    SetOfStacks plates(3);
    plates.push(1);
	plates.push(2);
	plates.push(3);
	plates.push(4);
	plates.push(5);
	plates.push(6);
	plates.pop();

    // returns the highest plate number in the current heap
	int topNum = plates.top();
    // Run result : topNum = 5
	cout << topNum << endl;
	return 0;

}