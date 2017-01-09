#include <bits/stdc++.h>
using namespace std;

const int sz = (int)1E5 + 10;
int cards[sz][2];
int dp[sz];

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("INPUT.in", "r", stdin);
    int n;
    cin >> n;
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            cin >> cards[j][i];
        }
    }
    if(n == 1){
        cout << abs(cards[0][0] - cards[0][1]) << endl;
    }else{
        dp[0] = abs(cards[0][0] - cards[0][1]);
        dp[1] = max(dp[0] + abs(cards[1][0] - cards[1][1]),
                    abs(cards[0][0] - cards[1][0]) + abs(cards[0][1] - cards[1][1]));
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1] + abs(cards[i][0] - cards[i][1]),
                        dp[i-2] + abs(cards[i][0] - cards[i-1][0]) + abs(cards[i][1] - cards[i-1][1]) );
        }

        cout << dp[n-1] << endl;
    }
}
