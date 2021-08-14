#include <bits/stdc++.h>

using namespace std;
template<class U> ostream &operator <<(ostream & u, vector<U> v){
    u<<"[ ";
    for(auto x : v)u<<x<<" , ";
    u<<" ]\n";
    return u;
}
vector<int> adj[100000];
vector<int> BFS(int ini, int n){
    vector<int> dist(n,1e9); /// 1e9 ocupa el rol de infinito
    dist[ini] = 0;
    queue<int> Q;
    Q.push(ini);
    while(!Q.empty()){
        int nod = Q.front();
        Q.pop();
        for(auto nex : adj[nod]){
            if(dist[nex]>dist[nod]+1)
            {
                dist[nex] = dist[nod]+1;
                Q.push(nex);
            }
        }
    }
    return dist;
}
void DFS(int nod, vector<bool> & vis, vector<int> & pre, vector<int> & pos){
    if(vis[nod]) return;
    vis[nod] = true;
    pre.push_back(nod);
    for(auto nex : adj[nod]) DFS(nex,vis,pre,pos);
    pos.push_back(nod);
}

vector<pair<int,int> > adj01[100000];

vector<int> BFS01(int ini, int n){
    vector<int> dist(n,1e9); /// 1e9 ocupa el rol de infinito
    dist[ini] = 0;
    deque<int> DQ;
    DQ.push_front(ini);
    while(!DQ.empty()){
        int nod = DQ.front();
        DQ.pop_front();
        for(auto ar : adj01[nod]){
            int nex = ar.first;
            int dis = dist[nod] + ar.second;
            if(dist[nex]>dis)
            {
                dist[nex] = dis;
                if(ar.second==0) DQ.push_front(nex);
                else DQ.push_back(nex);
            }
        }
    }
    return dist;
}
int main()
{
    /***
    5 5
	1 4
	2 4
	4 5
	5 2
	5 3
	**/
    vector<pair<int,int> > lista ={
        {1,4},{2,4},{4,5},{5,2},{5,3}
    };
    int n = 5;
    for(auto p : lista){
        p.first--, p.second--;
        adj[p.first].push_back(p.second);
        //adj[p.second].push_back(p.first);
    }
    vector<vector<int> > distancias;
    for(int i = 0;i<n;i++){
        cout<<i<<" tiene distancias "<<BFS(i,n)<<endl;
        distancias.push_back(BFS(i,n));
    }
    cout<<distancias<<endl;
    for(int i = 0;i<n;i++){
        vector<bool> vis(n,false);
        cout<<"Inicio DFS en "<< i <<endl;
        vector<int> pre,pos;
        DFS(i,vis,pre,pos);
        cout<<" pre : "<<pre<<endl;
        cout<<" pos : "<<pos<<endl;

    }
    return 0;
}
