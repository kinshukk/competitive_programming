#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int dp[1000+1][1000+1];
    int k;
    cin >> k;
    string first, second;
    int careful_prev_len = 0;
    bool flag = true;

    while(k>0){
        cin >> first;
        cin >> second;
        int l1 = first.length(), l2 = second.length();

        for(int i=0; i<=l1; i++){
            for(int kek=0; kek<k; kek++){
                dp[i][kek] = 0;
            }
        }
        for(int j=0; j<=l2; j++){
            for(int kek=0; kek<k; kek++){
                dp[kek][j] = 0;
            }
        }

        for(int i=k; i<=l1; i++){
            for(int j=k; j<=l2; j++){
                flag = true;
                for(int iii=1; iii<k+1; iii++){
                    if(first[i-iii] != second[j-iii]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    if(i>k && j>k){
                        careful_prev_len = (first.substr(i-k-1, k) == second.substr(j-k-1, k))?(dp[i-1][j-1] + 1):0;
                    }else{
                        careful_prev_len = 0;
                    }
                    dp[i][j] = max(max(careful_prev_len,
                                    dp[i-k][j-k] + k), max(dp[i-1][j], dp[i][j-1]));
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        cout << dp[l1][l2] << endl;
        cin >> k;
    }
    return 0;
}
