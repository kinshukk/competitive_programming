#include <bits/stdc++.h>
using namespace std;

int dp[45];
string outp = "";
int i, n, k;

void idk(int ind){
    i = lower_bound(dp, dp+n, ind) - dp;
    //cout << i << endl;
    if(i == 0){
        outp[0] = '0';
    }else if(i == 1){
        outp[0] = '1';
    }else{
        outp[i-1] = '1';
        //cout << outp[i-1] << endl;
        idk(ind - dp[i-1]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = dp[1] + 1;

    for(int i=3; i<=45; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    for(int i=0; i<45; i++){
        outp += "0";
    }

    if(n > 44 || k > dp[n]){
        cout << -1 << endl;
    }else{
        idk(k);

        for(int i=0; i<n; i++){
            cout << outp[n-i-1];
        }
        cout << endl;
    }
    return 0;
}
