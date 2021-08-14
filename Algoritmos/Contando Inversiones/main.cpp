#include <bits/stdc++.h>

using namespace std;
typedef long long intl;
const int largo = 1<<21; /// Está operación hace que largo = 2^19
/// En este caso, como largo = 2*N, N = largo/2
int L[largo], R[largo],  N; /// N será el tamaño real del vector que se ingresa
intl st[largo], cantInv = 0;
/// Notar que V en realidad tiene tamaño largo/2, pero no usamos la posición 0
int nulo = 0; /// acá debe ir el valor nulo de la operación Op
int Op(int a, int b){ /// Una operación cualquiera entre enteros, que sea asociativa
    return a+b;
}
void Update(int p) /// actualiza el valor en la posición p, haciendo que valga x
{
    p+=largo/2; /// Convertimos p a la hoja que representa esa posición del vector
    st[p]++;
    while(p/=2) st[p] = Op(st[p*2],st[p*2+1]);
    /// el while(p/=2) ejecutara mientras p sea distinto de 0, y en cada paso lo divide por 2
}
intl Query(int nodo, int lq, int rq)/// indice del nodo en el que estoy parado, y los extremos lq y rq de la query
{
    if(lq<=L[nodo] && R[nodo] <= rq) return st[nodo]; /// Caso completamente contenido
    if(lq>R[nodo] || rq<L[nodo]) return nulo; /// Caso nada contenido.
    return Op(Query(nodo*2,lq,rq), Query(nodo*2+1,lq,rq));
}
int main()
{

    cin>>N;
    memset(st,0,sizeof(st));
    for(int i = largo/2+1;i<largo;i++){
        L[i] = R[i] = i-largo/2;

    }
    for(int i = largo/2;i>0;i--){
        /**
        Para recorrer los nodos respetando el nivel basta con recorrer los indices en reversa
        **/
        L[i] = L[i*2];
        R[i] = R[i*2+1];
    }
    while(N--){
        int v;
        cin>>v;
        cantInv += Query(1,v+1,largo/2);
        cout<<"Hasta ahora la cantidad de inversiones es : "<<cantInv<<endl;
        Update(v);
    }
    return 0;
}
