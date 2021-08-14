#include <bits/stdc++.h>

using namespace std;
map<vector<int>,int> mhash;
vector<vector<int> > adj;
int DFS(int nod, int p){
    vector<int> ids;
    for(auto k : adj[nod])
        if(k!=p)
            ids.push_back(DFS(k,nod));
    sort(ids.begin(),ids.end());
    if(mhash[ids] == 0)
        mhash[ids] = mhash.size();
    return mhash[ids];
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m, mod = 1e9+7;
    cin>>n>>m;

}
