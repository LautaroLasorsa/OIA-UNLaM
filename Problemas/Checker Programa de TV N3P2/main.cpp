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
#define get(mask,i) (mask&(1<<i))
#define set(mask,i) (mask|=(1<<i))
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
const intl mod = 10000007;
void solucion(istream & cin, ostream & cout){
    int N,S,M;
    cin>>N>>S>>M;
    vector<vector<intl> > in(N,vector<intl>(3,0));
    forn(i,N) {
        forn(j,3)cin>>in[i][j];
        forn(j,2)in[i][j]--;
        assert(in[i][2]>0);
    }
    vector<intl> fin(S);
    forn(i,S){cin>>fin[i];fin[i]--;}
    vector<vector<intl> > maxv(N,vector<intl>(M+1,-1));
    vector<vector<intl> > maxdp(N,vector<intl>(M+1,0));
    vector<vector<intl> > dp(N,vector<intl>(M+1,0));
    dp[0][0] = 1;
    maxdp[0][0] = 1;
    maxv[0][0] = 0;
    forn(j,M)forn(i,N){
        if(maxv[i][j]<0) continue;
        vector<intl> vs(2);
        vs[0] = maxv[i][j] + in[i][2];
        vs[1] = maxv[i][j];
        int lim = 1 + (in[i][0]!=in[i][1]);
        forn(k,lim){
            if(vs[k]>maxv[in[i][k]][j+1]) maxv[in[i][k]][j+1] = vs[k], maxdp[in[i][k]][j+1] = 0;
            if(vs[k]==maxv[in[i][k]][j+1]) maxdp[in[i][k]][j+1] = (maxdp[in[i][k]][j+1] + maxdp[i][j])%mod;
            dp[in[i][k]][j+1] = (dp[in[i][k]][j+1]+dp[i][j])%mod;
        }
    }
    intl formas = 0;
    intl mejor = 0;
    intl fmejor = 0;
    for(auto k : fin){
        formas = (formas + dp[k][M])%mod;
        if(mejor<maxv[k][M]) mejor = maxv[k][M], fmejor = 0;
        if(mejor==maxv[k][M]) fmejor = (fmejor + maxdp[k][M])%mod;
    }
    //DBG(dp);
    //DBG(maxv);
    //DBG(maxdp);
    cout<<formas<<" "<<mejor<<" "<<fmejor<<"\n";
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    solucion(cin,cout);
    return 0;
}
