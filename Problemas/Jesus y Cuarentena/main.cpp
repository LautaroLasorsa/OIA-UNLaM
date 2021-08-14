#include <bits\stdc++.h>

using namespace std;
const int maxn = 6e4;
int d[maxn];
vector<pair<int,int> > g[maxn];
int BFS(int s, int t){
    memset(d,-1,sizeof(d));
    d[s] = 0;
    deque<int> dq;
    dq.push_back(s);
    while(dq.size()){
        int n = dq.front();
        if(n == t) return d[t];
        dq.pop_front();
        for(auto k : g[n]){
            int ne = k.first;
            int c = k.second + d[n];
            if(d[ne]==-1 || d[ne]>c){
                d[ne]=c;
                if(k.second == 0) dq.push_front(ne);
                else dq.push_back(ne);
            }
        }
    }
    return d[t];
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N,M,Q; cin>>N>>M;
    for(int i = 0;i<M;i++){
        int a,b,x;
        cin>>a>>b>>x;
        g[a].push_back({b,x});
        g[b].push_back({a,x});
    }
    cin>>Q;
    for(int i = 0;i<Q;i++){
        int s,t;
        cin>>s>>t;
        cout<<BFS(s,t)<<"\n";
    }
}
/*
5 5
1 2 1
1 3 0
2 5 1
3 4 0
4 5 0
2
2 3
5 1
*/
