#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+100;
vector<int> adj[MAXN];
int gin[MAXN];
bitset<MAXN> visto;
int N,M;
vector<int> ToposortConBFS(){
    queue<int> Q;
    for(int i = 1;i<=N;i++)
        if(gin[i]==0){
            visto[i] = true;
            Q.push(i);
        }
    vector<int> orden;
    while(!Q.empty()){
        int nodo = Q.front();
        Q.pop();
        orden.push_back(nodo);
        for(auto x : adj[nodo]){
            gin[x]--;
            if(gin[x]==0 && visto[x]==false){
                visto[x] = true;
                Q.push(x);
            }
        }
    }
    return orden;
}

void ToposortConDFS(int nodo, deque<int> & orden){
    if(visto[nodo]) return;
    visto[nodo] = true;
    for(auto x : adj[nodo])
        ToposortConDFS(x,orden);
    orden.push_front(nodo);
}
int main()
{
    cin>>N>>M;
    for(int i = 0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        gin[b]++;
    }

    vector<int> ordenA = ToposortConBFS();
    deque<int> ordenB;
    cout<<"ORDEN BFS:"<<endl;
    for(auto x : ordenA) cout<<x<<" ";
    cout<<endl;
    visto.reset();
    for(int i = 1;i<=N;i++) ToposortConDFS(i,ordenB);
    cout<<"ORDEN DFS:"<<endl;
    for(auto x : ordenB) cout<<x<<" ";
    cout<<endl;

    return 0;
}
/**
8 10
6 1
6 3
1 5
1 2
1 4
5 2
2 7
7 8
4 8
8 3
*/
