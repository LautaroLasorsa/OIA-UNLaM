#include <bits/stdc++.h>

using namespace std;
const int largo = 1<<19; /// Está operación hace que largo = 2^19
/// En este caso, como largo = 2*N, N = largo/2
int L[largo], R[largo], st[largo], V[largo/2+1], N; /// N será el tamaño real del vector que se ingresa
/// Notar que V en realidad tiene tamaño largo/2, pero no usamos la posición 0
void Update(int p, int x) /// actualiza el valor en la posición p, haciendo que valga x
{
    p+=largo/2; /// Convertimos p a la hoja que representa esa posición del vector
    st[p] = x;
    while(p/=2) st[p] = st[p*2] + st[p*2+1];
    /// el while(p/=2) ejecutara mientras p sea distinto de 0, y en cada paso lo divide por 2
}
int Query(int nodo, int lq, int rq)/// indice del nodo en el que estoy parado, y los extremos lq y rq de la query
{
    if(lq<=L[nodo] && R[nodo] <= rq) return st[nodo]; /// Caso completamente contenido
    if(lq>R[nodo] || rq<L[nodo]) return 0; /// Caso nada contenido.
    return Query(nodo*2,lq,rq) + Query(nodo*2+1,lq,rq);
}
int main()
{
    cin>>N;
    for(int i = 1;i<=N;i++){
        cin>>V[i];
        st[i+largo/2] = V[i];
        /// Leemos el vector e inicializamos las hojas
    }
    for(int i = largo/2+1;i<largo;i++){
        L[i] = R[i] = i-largo/2;
    }
    for(int i = largo/2;i>0;i--){
        /**
        Para recorrer los nodos respetando el nivel basta con recorrer los indices en reversa
        **/
        st[i] = st[i*2] + st[i*2+1];
        L[i] = L[i*2];
        R[i] = R[i*2+1];
    }
    /**
    Q será la cantidad de queries / updates que se harán

    Primero leera un entero t, si t = 0 es un update, si t = 1 es una query

    Si t = 0, luego leerá los enteros p y x en ese orden

    Si t = 1, luego leerá los enteros lq y rq en ese orden (inclusive - inclusive)
    **/
    int Q; cin>>Q;
    while(Q--){
        int t; cin>>t;
        if(t==0){
            int p,x;
            cin>>p>>x;
            Update(p,x);
        }else{
            int lq,rq;
            cin>>lq>>rq;
            cout<<Query(1,lq,rq)<<endl;
        }
    }
    return 0;
}
