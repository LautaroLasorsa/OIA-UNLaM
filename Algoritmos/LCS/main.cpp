#include <bits/stdc++.h>

using namespace std;
string LCS(string a, string b){
    a = '$'+a;
    b = '$'+b;
    int la = a.size(), lb = b.size();
    vector<vector<int> > dp(la,vector<int>(lb,0));
    for(int i = 1;i<la;i++){
        for(int j = 1;j<lb;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    int i = la-1, j = lb-1;
    string lcs = "";
    while(i!=0 && j!=0){
        if(a[i] == b[j] && dp[i-1][j-1] >= max(dp[i-1][j],dp[i][j-1])){
            lcs+=a[i];
            i--,j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    reverse(lcs.begin(),lcs.end());
    return lcs;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<"LCS : "<<LCS(s1,s2)<<"\n";
    return 0;
}
