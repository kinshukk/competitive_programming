#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <climits>

using namespace std;
using std::pair;
using std::make_pair;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    ll n, k, d;
    ll mod = 1E9 + 7;

    cin >> n >> k >> d;
    ll dp[n+1][2];
    //one way to get sum 0
    dp[0][0] = 1;
    dp[0][1] = 0;

    for(int i=1; i<=n; i++){
        dp[i][0] = 0;dp[i][1] = 0;//default values
        for(int j=1; j<=k; j++){
            if(i-j < 0){
                break;
            }

            if(j < d){
                dp[i][0] = dp[i][0] + dp[i-j][0];
                if(dp[i][0] > mod){
                    dp[i][0] -= mod;
                }

                dp[i][1] = dp[i][1] + dp[i-j][1];
                if(dp[i][1] > mod){
                    dp[i][1] -= mod;
                }
            }else{
                dp[i][1] = dp[i][1] + dp[i-j][0];
                if(dp[i][1] > mod){
                    dp[i][1] -= mod;
                }
                dp[i][1] = dp[i][1] + dp[i-j][1];
                if(dp[i][1] > mod){
                    dp[i][1] -= mod;
                }
            }
        }
    }

    cout << dp[n][1] << endl;
    return 0;
}
