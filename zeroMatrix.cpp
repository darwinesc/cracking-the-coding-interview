#include <iostream>
using namespace std;

void zeromMatrix(){
    int N = 3; 
    int M = 3;
    int matrix[N][M] = {
                            {1 , 5 , 6},
                            {0 , 8 , 9},
                            {2 , 3 , 4}

    };

    int count = 0;
    int ipos[N] = {};
    int jpos[M] ={};

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if(matrix[i][j] == 0){
                ipos[count] = i;
                jpos[count] = j;
                count ++;
            }
        }
        
    }

    for(int k = 0; k < count; k++){
        for(int x = 0; x < N; x++){
            matrix[x][jpos[k]] = 0;
    }
        for (int y = 0; y < N; y++){
            matrix[ipos[k]][y] = 0;
         }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
}

int main(){
    zeromMatrix();
    return 0;
}