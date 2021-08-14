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
struct nodo{
    intl suma; /// suma del rango que representa
    int l, r; /// indices en la bolsa de nodos
};
///const int largo = 2e7; /// 20.000.000
const int largo = 1e4; /// Para mostrarlo en mi computadora
nodo st[largo]; /// La bolsa de nodos
int tam = 0; /// Cantidad de nodos ya usados = Indice del proximo nodo a usar
int NuevoNodo(int ind){
    if(ind!=-1) st[tam] = st[ind];
    else{
        st[tam].suma = 0;
        st[tam].l = -1;
        st[tam].r = -1;
    }
    ind = tam;
    tam++;
    return ind;
}

int Update(int ind, intl pos, intl val, intl l = 1, intl r = (1ll<<30)){ /// Indexa en base 1
    /// El nodo abarca el rango [l;r]
    /// Quiero cambiar el valor de pos para que valga val
    if(l>pos || r<pos){
        /// Fuera del rango del nodo
        return ind;
    }
    ind = NuevoNodo(ind);
    if(l==r){
        st[ind].suma = val;
        return ind;
    }
    intl m = (l+r)/2;
    st[ind].l = Update(st[ind].l,pos,val,l,m);
    st[ind].r = Update(st[ind].r,pos,val,m+1,r);
    st[ind].suma = 0;
    if(st[ind].l!=-1) st[ind].suma += st[st[ind].l].suma;
    if(st[ind].r!=-1) st[ind].suma += st[st[ind].r].suma;
    return ind;
}
intl Query(int nod, intl lq, intl rq, intl l = 1, intl r = (1<<30)){
    if(nod == -1) return 0; /// Esa rama de nodos directamente no existe
    if(lq<=l && r<=rq){
        return st[nod].suma;
    }
    if(lq>r || rq<l) return 0;
    intl m = (l+r)/2;
    return Query(st[nod].l,lq,rq,l,m) + Query(st[nod].r,lq,rq,m+1,r);
}
int main()
{
    //cin.tie(0);
    //cin.sync_with_stdio(0);
    vector<int> versiones = {-1};
    int Q;cin>>Q;
    forn(i,Q){
        int t;cin>>t;
        if(t==1){
            /// Update
            intl r, pos, x; /// r es la versión del seg tree
            cin>>r>>pos>>x;
            versiones.push_back(Update(versiones[r],pos,x));
        }else{
            /// Query
            intl r,lq,rq;
            cin>>r>>lq>>rq;
            cout<<Query(versiones[r],lq,rq)<<endl;
        }
    }
    return 0;
}
