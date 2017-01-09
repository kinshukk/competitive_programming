#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    unsigned long long dp[n];
    dp[0] = 2;
    for(int i=1; i<n; i++){
        dp[i] = dp[i-1] + ((i>1)? dp[i-2] : 0);
    }
    cout << dp[n-1] << endl;
    return 0;
}
