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
const int largo = 1<<19;
struct nodo{
    intl suma = 0, lazy = 0;
};
int L[largo], R[largo];
nodo st[largo];
intl Eval(int nod){ /// Logica de evaluar un nodo
    return st[nod].suma + (R[nod]-L[nod]+1)*st[nod].lazy;
}
void Update(int nod, int lq, int rq, intl val){ /// Indexa en base 0
    if(lq<=L[nod] && R[nod]<=rq){
        st[nod].lazy += val;
        return ;
    }
    if(lq>R[nod] || rq<L[nod]){
        return;
    }
    /// Propago a mis hijos
    st[nod*2].lazy += st[nod].lazy;
    st[nod*2+1].lazy += st[nod].lazy;
    st[nod].lazy = 0;
    /// Paso la recursión
    Update(nod*2,lq,rq,val);
    Update(nod*2+1,lq,rq,val);
    /// Me actualizo yo
    st[nod].suma = Eval(nod*2) + Eval(nod*2+1);
}

intl Query(int nod, int lq, int rq){
    if(lq<=L[nod] && R[nod] <= rq) return Eval(nod); /// Responder la query en ese nodo
    if(lq>R[nod] || rq<L[nod]) return 0; /// Neutro
    st[nod*2].lazy += st[nod].lazy;
    st[nod*2+1].lazy += st[nod].lazy;
    st[nod].lazy = 0;
    st[nod].suma = Eval(nod*2) + Eval(nod*2+1);
    return Query(nod*2,lq,rq) + Query(nod*2+1,lq,rq);
}
int main()
{
    //cin.tie(0);
    //cin.sync_with_stdio(0);
    int N,Q;
    cin>>N>>Q;
    forn(i,N) cin>>st[i+largo/2].suma;
    forsn(i,largo/2,largo) L[i] = R[i] = i-largo/2; /// Acá se marca que indexa en base 0
    dforn(i,largo/2){
        L[i] = L[i*2];
        R[i] = R[i*2+1];
        st[i].suma = Eval(i*2) + Eval(i*2+1);
    }
    forn(i,Q){
        int t;cin>>t;
        if(t==1){
            /// Update
            intl lq,rq,x;
            cin>>lq>>rq>>x;
            Update(1,lq,rq,x);
        }else
        {
            /// Query
            int lq,rq;
            cin>>lq>>rq;
            cout<<Query(1,lq,rq)<<endl;
        }
    }
    return 0;
}
