#include <bits/stdc++.h>

using namespace std;
struct Nodo{
    int hijo[26], pref = 0;
    /// Ejemplo de dato que podemos guardar, cuantas palabras lo tienen como prefijo
    void iniciar(){
        for(int i = 0;i<26;i++){
            hijo[i] = -1;
        }
    }
};
const int largo = 1e7;
Nodo trie[largo];
int raiz = 0, tam = 1;
int Agregar(string s){
    int nod = raiz;
    for(auto c : s){
    /// for(int i = 0;i<s.size();i++){char c = s[i]
        int  x = c-'a';
        if(trie[nod].hijo[x]==-1){
            trie[tam].iniciar();
            trie[nod].hijo[x] = tam;
            tam++;
        }
        trie[nod].pref++;
        nod = trie[nod].hijo[x];
    }
    trie[nod].pref++;
    return trie[nod].pref;
}
int main()
{
    trie[0].iniciar();
    int n;cin>>n;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        cout<<Agregar(s)<<endl;
    }
    return 0;
}
