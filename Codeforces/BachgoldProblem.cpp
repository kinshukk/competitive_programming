#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a, b;
    a = 0; b = 0;
    if(n%2){
        n-=3;
        a = 1;
    }else{
        a = 0;
    }

    b = (n/2);
    cout << (a+b) << endl;

    for(int i=0; i<a; i++){
        cout << 3 << " ";
    }

    for(int i=0; i<b; i++)
        cout << 2 << " ";

    cout << endl;
    return 0;
}
