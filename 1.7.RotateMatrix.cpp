#include <iostream>
using namespace std;
const int N = 5;

void rotateMat(int mat[N][N]){
    int dim = N - 1;
    int rotMatrix[N][N];
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            rotMatrix[i][j] = mat[dim - j][i]; 
        }
    }

    for (int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
           cout <<  rotMatrix[x][y] << " ";
        }
        cout << endl;
    }
}


void printMat(int mat[N][N]){

    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "****************************" << endl;
}

int main(){

    
    int mat[N][N];
    int count = 10;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            mat[i][j] = count;
            count++;
        }
    }


    printMat(mat);
    rotateMat(mat);


    return 0;
}