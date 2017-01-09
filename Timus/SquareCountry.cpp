#include <bits/stdc++.h>
using namespace std;

vector<int> squares;
int dp[60000+1];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i=1; i<=sqrt(n); i++){
        squares.push_back(i*i);
    }

    int cnt = 0;

    dp[0] = 0;
    for(int i=1; i<=n; i++){
        dp[i] = INT_MAX;
        for(int j=0; j<squares.size() && squares[j]<=i; j++){
            dp[i] = min(dp[i], dp[ i-squares[j] ] + 1 );
        }
    }

    cout << dp[n] << endl;

    return 0;
}
