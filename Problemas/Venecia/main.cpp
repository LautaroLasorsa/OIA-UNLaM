#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int,int> > > adj;
vector<int> costo;
vector<int> camino;
vector<bool> visto;
int N,M,S, tot = 0;
void DFS(int nodo){

    for(auto x : adj[nodo]){
        int sig = x.first;
        int ar = x.second;
        if(visto[ar] == false){
            visto[ar] = true;
            camino.push_back(ar);
            DFS(sig);
            camino.push_back(ar);
            //tot += costo[ar]*2;
        }
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N>>M>>S;
    adj.resize(N+1);
    visto.resize(M+1,false);
    costo.resize(M+1,0);
    for(int i = 1;i<=M;i++){
        int a,b;
        cin>>a>>b>>costo[i];
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }
    DFS(S);
    cout<<camino.size()<<"\n";
    for(auto x : camino)cout<<x<<" ";
    cout<<"\n";
}
