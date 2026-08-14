#include <iostream>
using namespace std;

bool oneAway(string str1, string str2){
    int letters[128]{0};
    int count_ex = 0;

    for (int i = 0; i < str1.length(); i++){
        int idx = int(str1[i]);
        letters[idx]++;
    }

    for (int j = 0; j < str2.length(); j++){
        int idx2 = int(str2[j]);
        letters[idx2]--;
    }

    for (int ascii : letters){
        if(ascii > 0)
            count_ex++;
    }
    if(count_ex == 1){
        cout<<str1 << "," << str2 <<"->" << "true"<<endl;
        return true;
    }
    else{
        cout<<str1 << "," << str2 <<"->" << "false"<<endl;
        return false;
    }
}

int main(){

    oneAway("pale", "bake");
}