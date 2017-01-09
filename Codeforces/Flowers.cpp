#include <bits/stdc++.h>
using namespace std;

const long MOD = 1E9 + 7,
           sz = 1E5 + 10;
long dp[sz];

int main(){
    ios_base::sync_with_stdio(false);
    int t, k;
    cin >> t >> k;
    dp[0] = 1;

    for(long i=1; i<sz; i++){
        dp[i] = ( dp[i-1] + ( (i-k >= 0)? dp[i-k] : 0 ) ) % MOD;
    }

    dp[0] = 0;

    for(long i=1; i<sz; i++){
        dp[i] = ( dp[i] + dp[i-1] ) % MOD;
    }

    int a, b;

    long outp = 0;

    for(long i=0; i<t; i++){
        cin >> a >> b;
        outp = (dp[b] - dp[a-1]) % MOD;
        
        //wrapping around negative values
        if(outp < 0) outp += MOD;
        cout << outp << "\n";
    }

    // for(int i=1; i<10; i++){
    //     cout << dp[i] << "\n";
    // }

    return 0;
}
