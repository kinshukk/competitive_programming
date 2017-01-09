#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    long inp;
    long mx = 0;
    long long s = 0;
    for(int i=0; i<n; i++){
        cin >> inp;
        s += inp;
        mx = max(inp, mx);
    }

    long ans = max( mx, (long)ceil(((double)s)/(double)(n-1)) );

    cout << ans << endl;

    return 0;
}
