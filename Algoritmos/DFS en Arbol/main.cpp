#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > adj;
vector<int> dist;
void DFS(int nod, int pad, int prof){
    dist[nod] = prof;
    for(auto k : adj[nod])
        if(k!=pad)
            DFS(k,nod,prof+1);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n; cin>>n;
    adj.resize(n);
    dist.resize(n);
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int raiz; cin>>raiz;
    raiz--;
    DFS(raiz,-1,0);
    for(int i = 0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}
/*
A B C D E F G H I  J  K  L  M  N
1 2 3 4 5 6 7 8 9 10 11 12 13 14
14
4 10
4 7
4 2
7 12
10 5
10 1
10 11
5 13
5 9
11 3
2 8
2 14
14 6
4

*/
