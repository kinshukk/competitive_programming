#include <bits/stdc++.h>
using namespace std;

const int sz = 501;
int dp[sz][sz],
    count_black[sz],
    count_white[sz];
bool arr[sz];

int unhappiness(int a, int b){
    return (count_black[b] - count_black[a]) * (count_white[b] - count_white[a]);
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, k, j;
    cin >> n >> k;
    count_black[0] = count_white[0] = 0;

    dp[0][0] = 0;
    fill(dp[0]+1, dp[0]+n+1, 100000);
    bool inp;

    for(int i=1; i<=n; i++){
        cin >> inp;
        if(inp){
            count_black[i] = count_black[i-1] + 1;
            count_white[i] = count_white[i-1];
        }else{
            count_black[i] = count_black[i-1];
            count_white[i] = count_white[i-1] + 1;
        }
        fill(dp[i], dp[i]+n+1, 100000);
    }

    for(int i=1; i<=k; i++){
        for(int j=i; j<=n-k+i; j++){
            //we have to find minimum possible unhappiness
            //for putting j horses into i stables
            //take min of allowable elements of i-1 stables

            //-1 because we have to put at least 1 horse in the ith stable
            for(int l=i-1; l<=n-k+i-1; l++){
                dp[i][j] = min(dp[i][j], dp[i-1][l] + unhappiness(l, j));
                //cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
    }

    cout << dp[k][n] << endl;

    return 0;
}
