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
#define get(mask,i) (bool(mask&(1<<(i))))
#define set(mask,i) (mask|=(1<<(i)))
#define invert(mask,i) (mask^=(1<<(i)))
#define popcount(mask) (__builtin_popcount(mask))
template<class T> ostream & operator<<(ostream & out, vector<T> v){
	for(auto k : v) out<<k<<" ";
	out<<"\n";
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
int cambio[255];
bool SePasa(int tot[4], int cant[4]){
    forn(i,4) if(tot[i]<cant[i]*2) return true;
    return false;
}

bool OK(int tot[4], int cant[4]){
    forn(i,4) if(tot[i]!=2*cant[i]) return false;
    return true;
}
vector<int> cromosoma(string s){
    cambio['A'] = 0;
    cambio['C'] = 1;
    cambio['G'] = 2;
    cambio['T'] = 3;
    int n = s.size();
    s = s + s;
    int cant[4] = {0,0,0,0}, tot[4] = {0,0,0,0};
    for(auto & c : s) c = cambio[c], tot[c]++;
    forn(i,4) tot[i]/=2;
    int i = 0, j = 0; /// [i;j)
    while(j < s.size()){
        cant[s[j]]++; j++;
        while(j-i>n || SePasa(tot,cant)){
            cant[s[i]]--;
            i++;
        }
        if(OK(tot,cant)){
            int a = i%n;
            int b = j%n;
            return {a,b};
        }
    }
    return {-1,-1};
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    string s; cin>>s;
    cout<<cromosoma(s)<<endl;
    return 0;
}
