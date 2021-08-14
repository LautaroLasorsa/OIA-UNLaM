#include <bits/stdc++.h>

using namespace std;
const int maxn = 100*1000 + 100;
bool pos[maxn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    pos[0] = true;
    int n;cin>>n;
    for(int i = 0;i<n;i++){
        int x; cin>>x;
        /// Si puedo usar una unica vez cada elemento.
        for(int j = maxn-x-1;j>=0;j--)
            if(pos[j]) pos[j+x] = true;
        /**
        Si puedo usar infinitas veces el elemento de valor
        x, entonces hago:
        for(int j = 0;j<maxn-x;j++)
            if(pos[j]) pos[j+x] = true;
        **/
    }
    int cant = 0;
    for(int i = 1;i<maxn;i++)
        if(pos[i]) cant++;
    cout<<cant<<"\n";
    for(int i = 1;i<maxn;i++)
        if(pos[i]) cout<<i<<" ";
    return 0;
}
