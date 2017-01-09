#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, j, k;
    cin >> n >> m;
    k = (n > m)? m : n;
    cout << k + 1 << "\n";
    j = 0;
    while(j <= k){
        cout << j << " " << k - j << "\n";
        ++j;
    }
    return 0;
}
