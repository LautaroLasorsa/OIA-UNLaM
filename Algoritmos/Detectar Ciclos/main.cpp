#include <bits/stdc++.h>
/// Detectar Ciclos en Grafos DIRIGIDOS
using namespace std;
vector<vector<int> > adj;
/// Contiene a los que apunta
bool hayCiclos = false;
vector<int> estado;
/// 0 = no visitado
/// 1 = en la recursión
/// 2 = visitado y cerrado
void DFS(int nodo){
    if(estado[nodo] == 2) return;
    if(estado[nodo] == 1){
        cout<<"Ciclo encontrado en "<<nodo<<endl;
        hayCiclos = true;
        return;
    }
    estado[nodo] = 1;
    for(auto x : adj[nodo])
        DFS(x);
    estado[nodo] = 2;
}
int main()
{
    int N,M;
    cin>>N>>M;
    estado.resize(N+1,0);
    adj.resize(N+1,vector<int>(0));
    for(int i = 0;i<M;i++){
        int ini,fin;
        cin>>ini>>fin;
        adj[ini].push_back(fin);
    }
    for(int i = 1;i<=N;i++) DFS(i);
    cout<<"Hay Ciclos = "<<hayCiclos<<endl;
}
/*
6 8
1 2
1 4
2 3
3 4
4 2
5 3
5 6
6 6

*/
