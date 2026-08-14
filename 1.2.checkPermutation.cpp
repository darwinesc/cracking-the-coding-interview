#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkPermutation(string input1, string input2){

    // fill the array int with zeros
    int chars[128] = {0};

    // Base case
    if(input1.length() != input2.length())
        return false;

    // Iterate string 2 to count how many time there is a char and compare it with string 1.
    for(int i = 0; i < input1.length(); i++){

        int idx = char(input1[i]);
        chars[idx]++;

    } 

    // Iterate string 2 to count how many time there is a char and compare it with string 1.
    for(int j = 0; j < input2.length(); j++){

        int idxx = char(input2[j]);
        chars[idxx]--;

    }
    
    // Finally, check the letter array if the every counter is equals 0.
    for (int k = 0; k < sizeof(chars)/sizeof(chars[128]);  k++){
        if(chars[k] > 0)
            return false;
    }
    return true;

}

int main(){

    string input1 = "darwin";
    string input2 = "darwinnn";

    if(checkPermutation(input1, input2))
        cout << "It's a permutation";
    else
        cout << "It's not a permutation";


}