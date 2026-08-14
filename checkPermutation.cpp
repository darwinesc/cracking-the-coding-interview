#include <iostream>
#include <string.h>
using namespace std;

bool checkPermutation(string str1, string str2){

    if(str1.length() != str2.length()){
        return false;
    }
    // fill the array int with zeros
    int letters[128]{0};

    // Iterate string 1 to count how many times there is a char
    for (int i = 0; i < str1.length(); i++){
        int idx = int(str1[i]);
        letters[idx] ++;   
    }

    // Iterate string 2 to count how many time there is a char and compare with string 1.
    for (int j = 0; j < str2.length(); j++){
        int idx2 = int(str2[j]);
        letters[idx2] --;
    }
    
    // Finally, check the letter array if the every counter is equals 0.
    for(int z = 0; z < sizeof(letters[128]); z++){
       if (letters[z] > 0)
           return false;
    }

    return true;
}

int main(){

    bool f = checkPermutation("darwin", "niwrad");
    if (f == true)

        cout<<"It's permutation"<<endl;
    else
        cout<<"It's not permutation"<<endl;
    return 0;

}