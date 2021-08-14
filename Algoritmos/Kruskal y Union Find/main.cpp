#include <bits/stdc++.h>
using namespace std;
struct arista{
    int u,v, peso;
    /// Conecta los nodos u y v y tiene peso peso.
};
bool operator<(const arista & a, const arista & b){
    return a.peso<b.peso;
}
vector<arista> ars;
const int MAXN = 1e5 + 100;
/// Complejidad O(N) aprox.
int comp[MAXN], tam[MAXN}];
int findComp(int nodo){
    if(nodo == comp[nodo]) return nodo;
    return comp[nodo] = findComp(comp[nodo]);
}
bool Unir(arista a){
    /// Devuelve si usamos la arista a
    int cu = findComp(a.u), cv = findComp(a.v);
    if(cu==cv) return false;
    if(tam[cu]>tam[cv]) swap(cu,cv);
    /// Si la usa, une ambas componentes
    comp[cu] = cv;
    tam[cv]+=tam[cu];
    return true;
}
int main()
{
    int N,M;
    cin>>N>>M;
    for(int i = 1;i<=N;i++) comp[i] = i, tam[i] = i;
    ars.resize(M);
    for(int i = 0;i<M;i++){
        cin>>ars[i].u>>ars[i].v>>ars[i].peso;
    }
    sort(ars.begin(),ars.end()); /// O(NlogN)
    int pesoTotal = 0;
    vector<arista> mst;
    for(auto ar : ars){
        if(Unir(ar)){
            mst.push_back(ar);
            pesoTotal+=ar.peso;
        }
    }
    cout<<"Peso del MST: "<<pesoTotal<<endl;
    cout<<"Aristas usadas: "<<endl;
    for(auto ar : mst)
        cout<<ar.u<<" con "<<ar.v<<" con peso = "<<ar.peso<<endl;
    return 0;
}
