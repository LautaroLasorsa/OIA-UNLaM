#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > adj;
bool esBipartito = true;
vector<int> color;
/// -1 = no visitado ; 0 = grupo 1 ; 1 = grupo 2
void DFS(int nodo, int pad, int col){
    if(color[nodo]!=-1){
        if(color[nodo]!=col){
            esBipartito = false;
        }
        return;
    }
    color[nodo] = col;
    for(auto x : adj[nodo])
        DFS(x,nodo,1-col);
}
int main()
{
    int N,M;
    cin>>N>>M;
    color.resize(N+1,-1);
    adj.resize(N+1,vector<int>(0));
    for(int i = 0;i<M;i++){
        int ini,fin;
        cin>>ini>>fin;
        adj[ini].push_back(fin);
        adj[fin].push_back(ini);
    }
    for(int i = 1;i<=N;i++)
        if(color[i]==-1)
            DFS(i,-1,0);
    if(esBipartito){
        cout<<"Es bipartito y los colores son : "<<endl;
        for(int i = 1;i<=N;i++) cout<<color[i]<<" ";
        cout<<endl;
    } else cout <<"No es bipartito"<<endl;
}
/*
6 5
6 5
5 4
4 3
4 2
4 1
*/
