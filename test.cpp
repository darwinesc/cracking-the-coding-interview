#include <iostream>
#include <bits/stdc++.h>
//#include <string.h>
using namespace std;


void rotateMatrix(int dim){

    int mat[dim][dim];
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            mat[i][j] = j;
        }
    }

    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    int tmp_mat[dim][dim];
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            mat[i][j] = tmp_mat[j][i];
        }
        cout<<endl;
    }

    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            cout<<tmp_mat[i][j]<<" ";
        }
        cout<<endl;
    }

}


int main(){

    int dim = 5;
    rotateMatrix(dim);
    return 0;
}