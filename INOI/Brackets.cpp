#include <bits/stdc++.h>
using namespace std;

int n, k;

bool match(int a, int b){
    if(a+k == b){
        return true;
    }else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    int v[n], b[n], dp[n][n];

    for(int i=0; i<n; i++){
        cin >> v[i];
        fill(dp[i], dp[i]+n, 0);
    }

    for(int i=0; i<n; i++){
        cin >> b[i];
    }

    //single bracket cannot be well bracketed
    for(int i=0; i<n; i++){
        dp[i][i] = 0;
    }

    int inner = 0, outer = 0;

    for(int width=2; width<=n; width++){
        for(int i=0; i+width-1<n; i++){
            int j = i+width-1;
            if(match(b[i], b[j])){
                inner = dp[i+1][j-1];
                outer = v[i] + v[j];
                dp[i][j] = max( dp[i][j], max( inner + outer, max( inner, outer ) ) );
            }

            dp[i][j] = max( dp[i][j], max( dp[i+1][j], dp[i][j-1] ) );

            for(int k=i; k<=j; k++){
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    cout << dp[0][n-1] << endl;


    return 0;
}
