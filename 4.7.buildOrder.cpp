#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Graph{

    int numVert;
    bool **adjMat;


    Graph(int num){

        this->numVert = num;
        adjMat = new bool*[numVert];
        for(int i = 0; i < numVert; i ++){
            adjMat[i] = new bool[numVert];
            for(int j = 0; j < numVert; j++){
                adjMat[i][j] = false;
            }
        }
    }

    void addEdge(char u, char v){
        
        int x = int(u) - int('a');
        int y = int(v) - int('a');
        adjMat[x][y] = true;
    }

    void printMat(){

        for(int i = 0; i < numVert; i ++){
            for(int j = 0; j < numVert; j ++){
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void buildOrderUtil(stack<int> &q, bool visited[], int curr){

        visited[curr] = true;
        for(int i = 0; i < numVert; i++){
            if(adjMat[curr][i] == true && (!visited[i]))
                buildOrderUtil(q, visited, i);
        }

        q.push(curr);
    }

    void buildOrder(){

        stack<int> q;
        bool visited[numVert] = {false};
        for(int i = 0; i < numVert; i++){
            if(!visited[i])
                buildOrderUtil(q, visited, i);
        }

        while(!q.empty()){
            cout << char(q.top() + int('a')) << " ";
            q.pop();
        }   
    }

    

};

int main (){

    int start = int('a');
    int end = int('g');
    int len = end - start;
    Graph g(len);
    g.addEdge('a', 'd');
    g.addEdge('f', 'b');
    g.addEdge('b', 'd');
    g.addEdge('f', 'a');
    g.addEdge('d', 'c');
    //g.printMat();
    g.buildOrder();

    return 0;

}