#include <bits/stdc++.h>
using namespace std;

vector<int> segtree, array;
int n;

void build(int p, int L, int R){
    if(L == R){
        segtree[p] = L;
    }else{
        build(p << 1, L, (L+R)/2);
        build((p << 1)+1, 1 + (L+R)/2, R);

        int p1 = segtree[ (p << 1) ], p2 = segtree[ 1 + (p << 1) ];
        segtree[p] = (array[p1] <= array[p2])? p1 : p2;
    }
}

int RMQ(int p, int L, int R, int i, int j){
    if(i > R || j < L)  return -1;

    if(L >= i && R <= j){
        //query within segment
        return segtree[p];
    }else{
        int p1 = RMQ(p << 1, L, (L+R)/2, i, j),
            p2 = RMQ(1 + (p << 1), 1 + (L+R)/2, R, i, j);

        if(p1 == -1)    return p2;
        if(p2 == -1)    return p1;
        return (array[p1] <= array[p2])? p1 : p2;
    }
}

int rmq(int i, int j){
    return RMQ(1, 0, n-1, i, j);
}

void update(int i, int val, int p,  int L, int R){
    if(L != R){
        int left = p << 1, right = 1 + left;

        if(i <= (L+R)/2 && i >= L){
            update(i, val, left, L, (L+R)/2);
        }
        else if(i >= (L+R)/2 && i <= R){
            update(i, val, right, 1+(L+R)/2, R);
        }

        if(array[ segtree[left] ] <= array[ segtree[right] ]){
            segtree[p] = segtree[left];
        }else{
            segtree[p] = segtree[right];
        }
    }else{
        array[ segtree[p] ] = val;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    array.reserve(n+1);
    segtree.assign(4*n, 0);

    int inp;
    for(int i=0; i<n; i++){
        cin >> inp;
        array.push_back(inp);
    }

    build(1, 0, n-1);

    int q, a, b;
    cin >> q;
    for(int i=0; i<q; i++){
        cin >> a >> b;
        cout << array[rmq(a, b)] << endl;;
    }


    return 0;
}
