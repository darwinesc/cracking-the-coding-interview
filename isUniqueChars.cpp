#include <iostream>
using namespace std;

bool isUnique(string str_input){
    if(str_input.length() > 128) return false;

    bool char_set[128]{};
    for(int i = 0; i < str_input.length(); i++){
        int idx = int(str_input[i]);
        if (char_set[idx] == true){
            cout<<"It's not unique string"<<endl;
            return false;
        }
        char_set[idx] = true;
    }
    cout<<"It's unique string"<<endl;
    return true;
}

int main(){
    isUnique("DarwinA");
    return 0;       
}