#include <iostream>
using namespace std;

void matrixRotation(int dim){
    int matrix[dim][dim];
    int count = 1;
    // Create a matrix
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            matrix[i][j] = count;
            cout<< matrix[i][j]<<" ";
            count ++;
        }
        cout<<endl;
    }
    int aux;
    int rotMatrix[dim][dim];
    for (int i = 0; i < dim; i++){
        aux = dim - 1;
        for(int j = 0; j < dim; j++){
           rotMatrix[i][aux] = matrix[j][i]; 
           aux--;
        }
    }
    cout<<"*****************************************"<<endl;
    for (int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            cout<<rotMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    matrixRotation(3);
    return 0;

}
