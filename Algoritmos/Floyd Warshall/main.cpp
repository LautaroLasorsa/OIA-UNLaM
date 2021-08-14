#include <iostream>

using namespace std;
const int maxn = 100;
int mat[maxn][maxn], inf = 1e9;
int main()
{
    int N, M;
    cin>>N>>M;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++)
            if(i!=j) mat[i][j] = inf;
            else mat[i][j] = 0;
    }
    for(int i = 0;i<M;i++){
        int a,b,c; /// a->b con costo c
        cin>>a>>b>>c;
        mat[a][b] = min(mat[a][b],c);
    }
    /// Algoritmo de Floyd Warshall
    for(int k = 1;k<=N;k++){
        cout<<endl<<"Procese los nodos antes del "<<k<<endl;
        for(int i = 1;i<=N;i++)
        {
            cout<<endl;
            for(int j = 1;j<=N;j++)
            {
                if(mat[i][j]!=inf)printf("%2d",mat[i][j]);
                else cout<<"NO";
                cout<<" | ";
            }
        }
        cout<<endl<<string(20,'-');
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=N;j++){
                ///int alternativo = mat[i][k] + mat[k][j];
                ///mat[i][j] = min(mat[i][j],alternativo);
                mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]);
                /// Para min-max: mat[i][j] = min(mat[i][j],max(mat[i][k] , mat[k][j]));
                /// Cantidad de Caminos: mat[i][j] = (mat[i][j]+ mat[i][k]*mat[k][j])%mod
            }
        }
    }
    /**
    for(int k = 1;k<=N;k++)
        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=N;j++)
                mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]);
    K I J
    O(N^3)
    **/
    cout<<endl<<"Procese todos los nodos"<<endl;
     for(int i = 1;i<=N;i++)
        {
            cout<<endl;
            for(int j = 1;j<=N;j++)
            {
                if(mat[i][j]!=inf)printf("%2d",mat[i][j]);
                else cout<<"NO";
                cout<<" | ";
            }
        }
        cout<<endl<<string(20,'-');
    return 0;
}
/**
5 12
2 1 3
2 3 3
2 4 3
2 5 3
3 1 5
3 4 4
3 5 1
4 5 5
5 1 1
5 2 2
5 3 3
5 4 4

3 3
1 3 -1
2 1 -1
3 2 -1

Ver también : http://wiki.oia.unsam.edu.ar/algoritmos-oia/grafos/floyd-warshall
**/
