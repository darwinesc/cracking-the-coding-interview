#include <iostream>
using namespace std;

void UrLify(string str_input, int trueLength){
    int count_space = 0;
    for(int i = 0; i < trueLength; i++){
        if(str_input[i] == ' '){
            count_space ++;
        }
    }
    
    int new_length = trueLength + count_space * 2;
     if(trueLength < str_input.length()) 
        str_input[trueLength] = '\0';
    for (int idx = trueLength - 1 ; idx >= 0; idx --){
        if(str_input[idx] == ' '){
            str_input[new_length - 1] = '0';
            str_input[new_length - 2] = '2';
            str_input[new_length - 3] = '%';
            new_length = new_length - 3;
        }else{
            str_input[new_length - 1] = str_input[idx];
            new_length --; 
        }
    }
    cout<<"Output: "<<str_input;
}

int main(){
    UrLify("Mr John Smith    ", 13);
    return 0;
}