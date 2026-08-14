#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct Graph{

    int numVert;
    bool **adjMat;

    Graph(int val){

        this->numVert = val;
        adjMat = new bool*[numVert];
        for(int i = 0; i < numVert; i++){
            adjMat[i] = new bool[numVert];
            for(int j = 0; j < numVert; j++)
                adjMat[i][j] = false;
        }

    }

    void addEdge(int u, int v){

       adjMat[u][v] = true;   

    }

    void printMat(){

        for(int i = 0; i < numVert; i++){
            cout << i << ": ";
            for(int j = 0; j < numVert; j++)
                cout << adjMat[i][j] << " ";
            cout << endl;
        }
    }

    bool isReachable(int u, int v){

        if(u == v)
            return true;

        vector<bool> visited(numVert, false);
        queue<int> q;

        q.push(u);

        visited[u] = true;

        while(!q.empty()){

            u = q.front();

            q.pop();

            for(int i = 0; i < numVert; i++){
                if(adjMat[u][i] == 1 && !visited[i]){
                    
                    if(i == v)
                        return true;
                
                    if(!visited[i]){
                
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }

        }
        
        return false;

    }

};


int main()
{
     Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    int u = 0, v = 3;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    u = 3, v = 1;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    return 0;

}
