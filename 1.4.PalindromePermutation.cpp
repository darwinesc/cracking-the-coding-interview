#include <iostream>
#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

// Get ascii num by hashmap,between 'a' and 'z', valid for uppercase and lowercase
int getCharNum(char c){

    int a = int('a');
    int z = int('z');
    int A = int('A');
    int Z = int('Z');
    int charc = int(c);
    if(a <= charc && charc <= z)
       return charc - a;
    if(A <= charc && charc <= charc)
        return charc - A;
    return -1;
}

// Check if a string is palindrome permutation 
bool palindrome(string input_string){

    //Create a lengh of array to count how many time there is a letter in a string.
    int len = int('z') - int('a');
    int letters[len] = {0};
    // Count how many time there is a letter in a string 
    for(int i = 0; i < input_string.length(); i++){
        int idx = getCharNum(input_string[i]);
        letters[idx]++;
    }

    // Check if there is a two or more odd number in a array. it means, it's not a palindrome permutation.
    int count = 0;
    for(int i = 0; i < sizeof(letters)/sizeof(letters[0]); i++){
        if(letters[i]%2 == 1)
            count++;
        if(count > 1)
            return false;
    }

    return true;
}

int main(){

    string input_string = "Tact Coa";
    if(palindrome(input_string))
        cout<< "It's palindrome permutation";
    else
        cout << "It's not palindrome permutation";

    return 0;

}