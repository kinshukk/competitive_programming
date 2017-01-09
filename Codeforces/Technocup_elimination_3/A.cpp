#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    int d = 0, l = 1;
    for(int i=1; i<=k; i++){
        d = (d + i%2);
        if(d > m){
            d = 1;
            l++;
        }
    }
    cout << l << " " << d << " " << ((k%2 == 0)? "R" : "L") << endl;

    return 0;
}
