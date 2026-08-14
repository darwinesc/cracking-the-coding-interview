#include <iostream>
#include <ctype.h>

using namespace std;

bool palindrome(string input){
    int letters[128]{0};
    int count_odd = 0;

    for(int i = 0; i < input.length(); i ++){
        if(input[i] != ' '){
            char c = tolower(input[i]);
            int idx = int(c);
            letters[idx] ++;
        }
    }


    for (int aNumber : letters)
	{		
        if (aNumber % 2 != 0 && aNumber > 0){
            count_odd++;
            if (count_odd > 1 ){
                cout<<"It's not";
                return false;
            }
        }
	}

    cout<< "Yeah! It is.";
    return true;
}

int main()
{
    palindrome("Tactq Coaaaom");
    return 0;
}