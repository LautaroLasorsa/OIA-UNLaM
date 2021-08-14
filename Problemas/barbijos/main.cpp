#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

#define forn(i,n) for(int i = 0;i<int(n);i++)
#define dforn(i,n) for(int i = int(n)-1;i>=0;i--)
#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define fore(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)

#define DBG(x) do{cout<<#x<<" = "<<x<<endl;}while(false)
//#define get(mask,i) (bool(mask&(1<<(i))))
//#define set(mask,i) (mask|=(1<<(i)))
//#define invert(mask,i) (mask^=(1<<(i)))
//#define popcount(mask) (__builtin_popcount(mask))
template<class T> ostream & operator<<(ostream & out, vector<T> & v){
	out<<"[";
	for(auto k : v) out<<k<<" ";
	out<<"]"<<"\n";
	return out;
}
template<class T> ostream & operator<<(ostream & out, set<T>  s){
	out<<"{";
	for(auto k : s) out<<k<<" ";
	out<<"}"<<"\n";
	return out;
}

template<class T, class U> ostream & operator<<(ostream & out, pair<T,U>  p){
	out<<"[ "<<p.first<<" , "<<p.second<<" ] ";
	return out;
}
template<class T, class U> istream & operator>>(istream & in, pair<T,U> & p){
	in>>p.first>>p.second;
	return in;
}


typedef long long intl;
vector<vector<bool> > ok;
vector<vector<int> > dp;
int DP(int W,int H){
    if(W==1 && H==1) return 1;
    if(ok[W][H]) return dp[W][H] = 0;
    if(dp[W][H]!=-1) return dp[W][H];
    dp[W][H] = 1e6;
    forsn(i,1,W) dp[W][H] = min(dp[W][H],DP(i,H)+DP(W-i,H));
    forsn(i,1,H) dp[W][H] = min(dp[W][H],DP(W,i)+DP(W,H-i));
    return dp[W][H];
}
int barbijos(int W, int H, vector<int> w, vector<int> h){
    ok = vector<vector<bool> >(W+2,vector<bool>(H+2,false));
    dp = vector<vector<int> > (W+2,vector<int>(H+2,-1));
    forn(i,w.size()) ok[w[i]][h[i]] = true;
    if(ok[1][1]) return 0;
    return DP(W,H);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int W,H,t;
    cin>>W>>H>>t;
    vector<int> w(t),h(t);
    forn(i,t)cin>>w[i]>>h[i];
    cout<<barbijos(W,H,w,h)<<endl;
    return 0;
}
