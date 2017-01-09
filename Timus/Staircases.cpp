#include <bits/stdc++.h>
using namespace std;

const int sz = 502;
//dp[i][j] is the number of staircases possible
//with i blocks arranged into j columns
long long dp[sz][sz];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i=0; i<=n; i++){
        fill(dp[i], dp[i] + sz, 0);
        dp[i][1] = 1;
    }

    for(int i=2; i<=n; i++){
        for(int j=2; j<i; j++){
            //dp[i-j][j-1]: for first step having only one block
            //dp[i-j][j]: for first step having more than one block
            dp[i][j] = dp[i-j][j-1] + dp[i-j][j];
        }
    }

    long long ans = 0;
    for(int j=2; j<=n; j++){
        ans += dp[n][j];
    }

    cout << ans << endl;

    return 0;
}
