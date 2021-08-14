#include <bits/stdc++.h>
using namespace std;
/// Ejempl 0. Suma de los primeros N números
int suma(int n)
{
    if(n == 1)
    {
        cout << "Caso base 1, res = 1" << endl;
        return 1;
    }
    cout << "Recursion suma(" << n << ") = " << n << " + suma(" << n-1 << ")" << endl;
    int f = n+suma(n-1);
    cout << "Calcule suma(" << n << ") = " << f << endl;
    return f;
}
/// Ejemplo 1. Factorial
/**
Factorial de N.
Decimos que N! = 1*2*3*4*...*N
Lo que es lo mismo:
1! = 1
N! = N * (N-1)!
*/
const int mod = 1e9 + 7;
int FactorialIterativo(int N){
    int f = 1;
    for(int i = 1;i<=N;i++){
        f = (1ll*f*i)%mod;
    }
    return f;
}
int FactorialRecursivo(int N){
    if(N==1){
        cout<<" LLegue al caso base, 1! = 1"<<endl;
        return 1;
    }
    cout<<"Calculo "<<N<<"! como "<<N<<" * "<<(N-1)<<"!"<<endl;
    int f = 1LL * N * FactorialRecursivo(N-1)%mod;
    cout<<"Calcule "<<N<<"! = "<<f<<endl;
    return f;
}

/// Ejemplo 2. Algoritmo de Euclides
/// Da el gcd de 2 números A y B en O(min(log(A),log(B))
/**
Usa la idea de que
gcd(a,b) = gcd(b,a) = gcd(b,a-b)
Como tomar modulo es restar muchas veces b
gcd(b,a) = gcd(b,a%b)
*/
int gcd(int a, int b){
    cout<<"Calculo gcd( "<<a<<" , "<<b<<" ) "<<endl;
    if(b==0) return a;
    return gcd(b,a%b);
}
/// Ejemplo 3. Potencia Binaria.
/// Permite calculra b^e (b = base, e = exponente) en O(log(e))
/**
Usa que si e es par, podemos pensarlo como (b^(e/2))^2, y si es impar es (b^(e-1))*b
y como e-1 será par, podemos usar la optimización que vimos en el caso par
*/
int PotenciaLinealIterativa(int b, int e){ /// O(e)
    int r = 1;
    for(int i = 1;i<=e;i++){
        r = 1ll*r*b%mod;
    }
    return r;
}
int PotenciaLinealRecursiva(int b, int e){ /// O(e)
    if(e == 0) return 1;
    return 1ll * b * PotenciaLinealRecursiva(b,e-1) % mod;
    /// Hago b^e = b * b^(e-1)
}
int PotenciaBinariaRecursiva(int b, int e){ /// O(log(e))
    /// Yo usualmente llamo a esta función BinPow(b,e)
    if(e==0) return 1; /// Siempre es el caso base
    if(e%2==1) return 1ll * b * PotenciaBinariaRecursiva(b,e-1) % mod;
    int b2 = PotenciaBinariaRecursiva(b,e/2);
    return 1ll*b2*b2%mod;
}
/**
Ejemplo:
e = 12 = 1100 en binario
Entonces, b^12 = b^8 * b^4
*/
int PotenciaBinariaIterativa(int b, int e){
    int acum = b, r = 1;
    while(e){
        if(e%2==1) r = 1ll*r*acum%mod;
        acum = 1ll*acum*acum%mod;
        e/=2; /// e>>=1;
    }
    return r;
}

int main()
{
    ///Ejemplo 0. Suma
    //suma(12);
    ///Ejemplo 1. Factorial
    /*FactorialRecursivo(12);
    /*for(int i = 1;i<=10;i++){
        cout<<i<<" > "<<FactorialIterativo(i)<<" = "<<FactorialRecursivo(i)<<endl;
    }*/
    ///Ejemplo 2. gcd
    //cout<<gcd(1e9,2e9-12345678)<<endl;
    ///Ejemplo 3. Potencia Binaria
    /*for(int i = 1;i<=10;i++){
        cout<<"2 a la "<<i<<" = "<< PotenciaLinealIterativa(2,i)<<" = "<<PotenciaLinealRecursiva(2,i)<<" = "<<PotenciaBinariaIterativa(2,i)<<" = "<<PotenciaBinariaRecursiva(2,i)<<endl;
    }
    //Rendimiento
    cout<<PotenciaBinariaIterativa(2,1e9)<<endl;
    cout<<PotenciaLinealIterativa(2,1e9)<<endl;
    */
    return 0;
}
