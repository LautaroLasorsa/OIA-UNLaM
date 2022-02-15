#include <bits/stdc++.h>
#include "segment_tree.cpp"
using namespace std;

int main(){
    srand(time(0));
    segment_tree<int> st;
    for(int i = 0;i<16;i++)
        st.push_back(rand()%100);
    cout<<st<<endl;
    st.aplicate([](int * ini, int * fin){ while(ini!=fin){(*ini)++;ini++;}},0,5);
    cout<<st<<endl;
    st.aplicate(reverse,0,16);
    cout<<st<<endl;
    st.push_back(100);
    cout<<st<<endl;
    return 0;
}