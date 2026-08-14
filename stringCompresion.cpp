#include <iostream>
#include <string>
using namespace std;
//aabcccccaaa
string stringCompress(string str_input){
    char c;
    int count = 0;
    string new_string = "";
    for(int i = 0; i <= str_input.length(); i++){
        if (i == 0)
            c = str_input[i];

        if (c == str_input[i]){
            count ++;
        }else{
            new_string = new_string + to_string(count) + c;
            c = str_input[i];
            count = 0;
            count++;
        }
    }
    
    if (new_string.length() < str_input.length())
        return new_string;
    else
        return str_input;

}

int main (){

    string output = stringCompress("aabcccccaaa");
    cout << output;
    return 0;

}