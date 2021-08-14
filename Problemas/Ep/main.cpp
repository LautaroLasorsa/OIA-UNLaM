#include <bits/stdc++.h>
using namespace std;

#define pb push_back
//#define mp make_pair

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
typedef long double ld;
struct item{
    ld l,r,y;
};

item in[4000];
map<ld,int> pos,neg;
int tot = 0;
ld eps = 1e-18;
void MaxPos(int i, int j){
    if(in[j].y>=in[i].y) return;
    tot++;
    if(in[i].r<=in[j].l){
        pos[0]++;
        ld dy = in[i].y-in[j].y;
        ld ini = (in[j].l-in[i].r)/dy;
        ld fin = (in[j].r-in[i].l)/dy;
        //pos.push_back({ini,-1});
        //pos.push_back({fin,1});
        pos[ini+eps]--;
        pos[fin]++;
    }else if(in[i].l <= in[j].r){
        ld dy = in[i].y-in[j].y;
        ld fin = (in[j].r-in[i].l)/dy;
        pos[fin]++;
    }else{
        pos[0]++;
    }
}
void MaxNeg(int i, int j){
    if(in[j].y>=in[i].y) return;
    if(in[i].l>=in[j].r){
        neg[0]++;
        ld dy = in[i].y-in[j].y;
        ld ini = (-in[j].r+in[i].l)/dy;
        ld fin = (-in[j].l+in[i].r)/dy;
        //pos.push_back({ini,-1});
        //pos.push_back({fin,1});
        neg[ini+eps]--;
        neg[fin]++;
    }else if(in[i].r >= in[j].l){
        ld dy = in[i].y-in[j].y;
        ld fin = (-in[j].l+in[i].r)/dy;
        neg[fin]++;
    }else{
        neg[0]++;
    }
}
ld DisPos(ld mp, int N){
    ld minl = 1e32, maxr = -1e32;
    forn(i,N){
        ld pl = in[i].l + mp*in[i].y;
        ld pr = in[i].r + mp*in[i].y;
        minl = min(minl,pl);
        maxr = max(maxr,pr);
    }
    return maxr-minl;
}
ld DisNeg(ld mp, int N){
    ld minl = 1e32, maxr = -1e32;
    forn(i,N){
        ld pl = in[i].l - mp*in[i].y;
        ld pr = in[i].r - mp*in[i].y;
        minl = min(minl,pl);
        maxr = max(maxr,pr);
    }
    return maxr-minl;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
	int N;cin>>N;
    forn(i,N){
        cin>>in[i].l>>in[i].r>>in[i].y;
    }
    forn(i,N) forn(j,N) MaxPos(i,j), MaxNeg(i,j);
    //DBG(tot);
    ld mpos = 0, mneg = 0;
    int acp = 0, acn = 0;
    for(auto k : pos){
    //    cout<<"pos >> "<<k.first<<" >>> "<<k.second<<endl;
        acp+=k.second;
        if(acp>=tot){
            mpos = k.first;
            break;
        }
    }
    for(auto k : neg){
        acn+=k.second;
        if(acn>=tot){
            mneg = k.first;
            break;
        }
    }
    DBG(mpos);
    DBG(mneg);
    ld res = min(DisPos(mpos,N),DisNeg(mneg,N));
    cout.precision(30);
    cout<<fixed<<res<<"\n";

}
/*
1 => 7
4 => 10
2 => 6
3 => 7

*/
