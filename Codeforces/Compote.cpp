#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    b = b/2;
    c = c/4;
    int cnt = min(a, min(b, c));
    int ans = cnt*7;
    cout << ans << endl;

    return 0;
}
