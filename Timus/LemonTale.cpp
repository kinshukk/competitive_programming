//NOTE: need to implement BigInt for this
#include <bits/stdc++.h>
using namespace std;

const int sz = 10001;

long long lemon[sz],
          banana[sz],
          sum_banana[sz];

int main(){
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    lemon[0] = banana[0] = sum_banana[0] = 0;
    lemon[1] = banana[1] = sum_banana[1] = 1;
    lemon[2] = banana[2] = 2;
    sum_banana[2] = sum_banana[1] + banana[2];

    for(int i=3; i<=n; i++){
        banana[i] = banana[i-1] + lemon[i-1];
        sum_banana[i] = banana[i] + sum_banana[i-1];
        lemon[i] = sum_banana[i-1] - sum_banana[max(0, i-k-1)];
        //cout << lemon[i] << " " << banana[i] << " " << sum_banana[i] << endl;
    }

    cout << banana[n] + lemon[n] << endl;

    return 0;
}
