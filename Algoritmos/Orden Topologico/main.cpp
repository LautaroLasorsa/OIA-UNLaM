#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > adj;
vector<int> grado; /// grado de entrada
vector<int> orden;
queue<int> cola;
int N,M;
int main()
{
    cin>>N>>M;
    adj.resize(N+1);
    grado.resize(N+1,0);
    for(int i = 0;i<M;i++){
        int ini, fin;
        cin>>ini>>fin;
        adj[ini].push_back(fin);
        grado[fin]++;
    }
    for(int i = 1;i<=N;i++){
        if(grado[i] == 0)
            cola.push(i);
    }
    while(!cola.empty()){
        int nodo = cola.front();
        cola.pop();
        for(auto x : adj[nodo]){
            grado[x]--;
            if(grado[x]==0)
                cola.push(x);
        }
        orden.push_back(nodo);
    }
    if(orden.size() != N){
        cout<<"Hay ciclos"<<endl;
        return 0;
    }
    cout<<"Un posible orden topologico es : "<<endl;
    for(auto x : orden) cout<<x<<" ";
    cout<<endl;
}
/*
9 12
1 8
1 9
9 4
9 5
8 5
8 6
5 7
4 3
7 3
6 3
3 2
2 3
*/
