#ifndef SEGMENT_TREE
#define SEGMENT_TREE
using namespace std;
#include <exception>
#include <iostream>
/**
* Segment Tree structure
*
* You have to give it a class T and an associative function f:TxT->T,
* and this structure allows you to make points update and range query in
* log(lar*O(f)), where lar is the number of elements in the structure.
* 
* */
template<class T> T __segment_tree_default_f(T a, T b){ return a+b;}
template<class T, T f(T,T) = __segment_tree_default_f> class segment_tree{
    private:
    
    T * pos;
    size_t lar = 0;
    size_t tlar = 0; 

    T _query(int p, int lq, int rq, int ln, int rn){
    // Recursive implementation of the query.
        if(lq<=ln and rn<=rq) return pos[p];
        int m = (ln+rn)/2;
        if(m>=rq) return _query(p*2,lq,rq,ln,m);
        else if(m<=lq) return _query(p*2+1,lq,rq,m,rn);
        return f(_query(p*2,lq,rq,ln,m),_query(p*2+1,lq,rq,m,rn));
    }

    void actualize_range(int l, int r){
    // Actualizate all the values in the range [l,r). O((log(lar)+r-l)*O(f))
        l+=tlar/2; r+=tlar/2 - 1;
        while(l/=2,r/=2){
            for(int i = l;i<=r;i++)
                pos[i] = f(pos[i*2],pos[i*2+1]);
        }
    }

    public:

    segment_tree(size_t _lar = 0, T val = T()){
    // Inizalitation with size _lar and val at each position. O(_lar*copy(val))
        lar = _lar;
        tlar = 1;
        while(tlar<lar*2) tlar*=2;
        pos = new T[tlar];
        fill(pos+tlar/2,pos+tlar/2+lar,val);
        for(int i = tlar/2-1;i>=1;i--){
            pos[i] = f(pos[i*2],pos[i*2+1]);   
        }
    };

    void update(int p, const T & v){
    // Update the value at position p. O(log(tlar)*O(f))
        if(p>=lar or p<0) throw out_of_range("segment tree out of range");
        p += tlar/2;
        pos[p] = v;
        while(p/=2) pos[p] = f(pos[p*2],pos[p*2+1]);
    }

    T query(int l, int r){
    // Query about the range [l,r). O(log(tlar)*O(f))
        if(l>=lar or l<0) throw out_of_range("segment tree out of range");
        if(r>lar or r<0) throw out_of_range("segment tree out of range");
        return _query(1,l,r,0,tlar/2);
    }

    void push_back(const T & val){
    // Add a value at the end of the Segment Tree. O(log(tlar)*O(f))
        lar++;
        if(tlar<lar*2){
            T * temp = (T*)malloc(sizeof(T)*tlar*2);
            memcpy(temp+tlar,pos+tlar/2,(lar-1)*sizeof(T));
            fill(temp+tlar+lar,temp+2*tlar,T());

            tlar*=2;
            delete pos;
            pos = temp;
            
            for(int i = tlar/2-1;i>=1;i--) pos[i] = f(pos[i*2],pos[i*2+1]);
        }
        update(lar-1,val);
    }
    void pop_back(){
    // Erase the last position of the Segment Tree. O(log(tlar)*O(f))
        if(lar>0){
            lar--;
            update(pos,T());
        }
    }

    size_t size(){
        return lar;
    }

    const int & operator[](int i){
    // Read only access
        return pos[i];
    }

    void aplicate(void f2(T *, T *), int l = 0, int r = -1){
    /* Gets a fuction that receives 2 pointers and pass to it the pointers 
    from l to r. After that, it's update the internal nodes */    
        if(r==-1) r = lar;
        if(l>=lar or l<0) throw out_of_range("segment tree out of range");
        if(r>lar or r<0) throw out_of_range("segment tree out of range");
        f2(pos+tlar/2+l,pos+tlar/2+r);
        actualize_range(l,r);
    }

    friend ostream & operator<<(ostream & out, const segment_tree<T,f> & st){
        out<<"Segment Tree | Largo : "<<st.lar<<" | Largo Real : "<<st.tlar<<endl;
        for(int i = 1;i<st.tlar;i++){
            if(i>1){
                
                if(__builtin_popcount(i)==1) cout<<endl;
                else out<<" ";
            }
            out<<st.pos[i];

        }
        out<<endl;
        return out;
    }

};

#endif
