#include <iostream>
using namespace std;

bool isSubstring(string s1, string s2){

    for (int i = 0; i < s1.length(); i++){
        char c = s1[i];
        for(int j = 0; j < s2.length(); j++){
            string sbString = "";
            if(c == s2[j]){
                sbString = sbString + c;
                
            }
        }
    }
}


int main (){

    isSubstring("waterbottle", "erbottlewat");
    return 0;

}