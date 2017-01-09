#include <bits/stdc++.h>
using namespace std;

const int sz = 3010;
int n = 0, ptr = 0;
int a[sz], b[sz];

void recurse(int start, int end){

    if(start > end) return;

    b[ptr] = a[end];
    ptr--;
    for(int i=end-1; i>=start; i--){
        if(a[i] < a[end]){
            //reverse order
            recurse(start, i);
            recurse(i+1, end-1);
            return;
        }
    }
    //if all elements are greater than a[end]
    recurse(start, end-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    ptr = n-1;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    recurse(0, n-1);

    for(int i=0; i<n; i++){
        cout << b[i] << "\n";
    }

    return 0;
}
