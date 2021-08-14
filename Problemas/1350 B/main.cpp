#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> s(n+1), dp(n+1,1);
        for(int i = 1;i<=n;i++) cin>>s[i];
        int res = 0;
        for(int i = 1;i<=n;i++){
            res = max(res,dp[i]);
            for(int j = 2*i;j<=n;j+=i){
                if(s[j]>s[i])
                    dp[j] = max(dp[j],dp[i]+1);
            }
        }
        cout<<res<<"\n";
    }
}
