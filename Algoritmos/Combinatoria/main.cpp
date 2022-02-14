#include <bits/stdc++.h>

using namespace std;
/**

Permutaciones
Formas de tomar elementos (Combinaciones)

**/
/**
Permutaciones:

La cantidad de permutaciones de un vector de N elementos distintos es N!
La cantidad de permutaciones de un vector de N elementos donde hay repetidos es
N!/(x_1!*x_2!*x_3!...*x_m!) donde m es la cantidad de elementos distintos y
x_i son las apariciones de; i-esimo de estos elementos distintos.

Nota: N! = 1*2*3*4*5*...*(N-1)*N
**/
const int maxlargo = 20;
int factorial[maxlargo];
int CantPer(vector<int> & v){
    return factorial[v.size()];
}

/**
Combinatoria:
La cantidad de formas de tomar un subconjunto de K elementos de un conjunto de N
elementos distintos se dice N tomados de a K, (N K)

Se calcula como N!/(K!*(N-K)!)
**/
int Combinacion(int N, int K){
    return factorial[N]/factorial[K]/factorial[N-K];
}

int dpcomb[5000][5000];
const int mod = 1e9+7;
int CombinacionDP(int N, int K){
    if(K==0 or K==N) return 1;
    if(K<0 or K>N) return 0;
    if(dpcomb[N][K]==-1)
        dpcomb[N][K] = (CombinacionDP(N-1,K-1)+CombinacionDP(N-1,K))%mod;
    return dpcomb[N][K];
}
int triangulo[5000][5000];
int main()
{
    memset(dpcomb,-1,sizeof(dpcomb));
    for(int i = 0;i<5000;i++) triangulo[i][0] = triangulo[i][i] = 1;
    for(int i = 1;i<5000;i++)
        for(int j = 1;j<i;j++)
            triangulo[i][j] = (triangulo[i-1][j-1]+triangulo[i-1][j])%mod;
    for(int i = 0;i<10;i++){
        for(int j = 0;j<=i;j++)
            printf("%5d ",triangulo[i][j]);
        cout<<endl;
    }
    /**

    Comentarios:
    La suma de (N 0)  + (N 1) + ... (N (N-1) ) + (N N) = 2^N

    */
}
