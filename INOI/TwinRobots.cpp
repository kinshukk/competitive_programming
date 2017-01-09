#include <bits/stdc++.h>
using namespace std;

const int sz = 2501;
int mat[sz][sz], dp[sz][sz];

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("INPUT.in", "r", stdin);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mat[j][i];
            dp[j][i] = 0;
        }
    }

    int tmp = INT_MIN;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = mat[i][j] + mat[n-j-1][i];
            tmp = INT_MIN;
            if(i > 0){
                tmp = max(tmp, dp[i-1][j]);
            }
            if(j > 0){
                tmp = max(tmp, dp[i][j-1]);
            }
            if(tmp != INT_MIN){
                dp[i][j] += tmp;
            }
        }
    }

    cout << dp[n-1][n-1] << endl;
}
