//NOTE: Not Solved
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    double dp[n];
    cout << setprecision(7) << fixed;

    dp[0] = 0.0;
    dp[1] = 10.0;
    for(int i=2; i<=n-2; i++){
        dp[i] = 0.0;
        for(int j=1; j<=i; j++){
            dp[i] += 10.0 + max(dp[j-1], dp[i-j]);
        }
        dp[i] /= (i*1.0);
    }

    cout << dp[n-2] << endl;


    return 0;
}
