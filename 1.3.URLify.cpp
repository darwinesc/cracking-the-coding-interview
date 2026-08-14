#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void URLify(string input, int trueLenght){

    int count_space = 0;
    for(int i = 0; i < trueLenght; i ++){
        if(input[i] == ' ')
           count_space++;
    }

    // Create a new adding to new string 2 extra spaces by each space.
    int new_length = trueLenght + count_space * 2;
    
    if(trueLenght < input.length())
        input[trueLenght] = '\0';
    for(int j = trueLenght - 1; j >= 0; j--){
        if(input[j] == ' '){
            input[new_length - 1] = '0';
            input[new_length - 2] = '2';
            input[new_length - 3] = '%';
            new_length = new_length - 3;
        }else{
            input[new_length - 1] = input[j];
            new_length--;
        }
    }

    cout << "New string: "<< input;
}

int main(){

    string input = "Mr John Smith    ";
    URLify(input, 13);

    return 0;
}