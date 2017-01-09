//AC for all test cases
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long n;
    cin >> n;
    int dp[n][2];
    //dp[i][1] : number of ways to tile so that
    //the ith column has one cell empty
    //dp[i][0] : number of ways to completely tile i columns
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 2;
    dp[1][1] = 2;

    for(long i=2; i<n; i++){
        dp[i][0] = ( dp[i-1][1] + dp[i-1][0] + dp[i-2][0] ) % 10000;
        dp[i][1] = ( dp[i-1][1] + 2*dp[i-2][0] ) % 10000;
    }

    cout << dp[n-1][0] << endl;
    return 0;
}
