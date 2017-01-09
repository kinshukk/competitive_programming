#include <bits/stdc++.h>
using namespace std;

bool palindrome[4001][4001];
int dp[4001], prev[4001];
string inp;

void print_words(int k){
    if(prev[k] == -1) return;
    print_words(prev[k]);
    cout << inp.substr(max(prev[k], 0), k-prev[k]) << " ";
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> inp;

    int l = inp.size();
    for(int i=0; i<=l; i++){
        fill(palindrome[i], palindrome[i]+4001, false);
        palindrome[i][i] = true;
    }

    for(int i=1; i<l; i++){
        if(inp[i-1] == inp[i]){
            palindrome[i][i+1] = true;
        }
    }

    for(int i=2; i<l; i++){
        for(int j=1; j<=l; j++){
            if(j+i <= l){
                if(inp[j-1] == inp[j+i-1] && palindrome[j+1][j+i-1]){
                    palindrome[j][j+i] = true;
                }
            }
        }
    }

    dp[0] = 0;
    prev[0] = -1;

    for(int i=1; i<=l; i++){
        dp[i] = dp[i-1] + 1;
        prev[i] = i-1;
        for(int j=i; j>0; j--){
            if(palindrome[j][i] && dp[i] > dp[j-1] + 1){
                dp[i] = dp[j-1] + 1;
                prev[i] = j-1;
            }
        }
    }

    cout << dp[l] << "\n";

    print_words(l);

    return 0;
}
