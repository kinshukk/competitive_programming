#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;
    string inp;
    cin >> inp;

    if(a > b){
        swap(a, b);
    }
    if(a == b){
        cout << 0 << endl;
    }else{
        --a, --b;
        char t1 = inp[a],
             t2 = inp[b];
        if(t1 == t2){
            cout << 0 << endl;
        }else{
            cout << 1 << endl;
        }
    }

    return 0;
}
