#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    long long dp[n];

    dp[0] = k-1;
    dp[1] = k*dp[0];

    for(int i=2; i<n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) * (k-1);
    }

    cout << dp[n-1] << endl;

    return 0;
}
