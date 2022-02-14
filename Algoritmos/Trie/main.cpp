#include <bits/stdc++.h>

using namespace std;
/**struct Nodo{
    int hijo[26], pref = 0;
    /// Ejemplo de dato que podemos guardar, cuantas palabras lo tienen como prefijo

};*/
struct Nodo{
    map<int,int> hijo;
    int pref = 0;
};
const int largo = 1e6;
Nodo trie[largo];
int raiz = 0, tam = 1;
int Agregar(string s){
    int nod = raiz;
    for(auto c : s){
    /// for(int i = 0;i<s.size();i++){char c = s[i]
        int  x = c-'a';
        if(trie[nod].hijo[x]==0){
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
    int n;cin>>n;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        cout<<Agregar(s)<<endl;
    }
    return 0;
}
