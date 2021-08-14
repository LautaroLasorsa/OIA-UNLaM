#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m, mod = 1e9+7;
    cin>>n>>m;
    vector<int> in(n,0), dp(n,0);
    dp[0] = 1;
    vector<vector<int> > adj(n);
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        in[b]++;
    }
    queue<int> Q;
    for(int i = 0;i<n;i++){
        if(in[i]==0)
            Q.push(i);
    }
    while(!Q.empty()){
        int nod = Q.front();
        Q.pop();
        for(auto k : adj[nod]){
            dp[k] = (dp[k]+dp[nod])%mod;
            in[k]--;
            if(in[k]==0)
                Q.push(k);
        }
    }
    cout<<dp[n-1]<<"\n";
}
