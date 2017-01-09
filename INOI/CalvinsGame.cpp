#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    if(n == 1){
        cout << 0 << endl;
        return 0;
    }

    int dp[n];
    dp[0] = 0;
    dp[1] = arr[0] + dp[0];

    for(int i=2; i<n; i++){
        dp[i] = max(arr[i-1] + dp[i-1], arr[i-2] + dp[i-2]);
    }

    if(k == n){
        cout << dp[n-1] << endl;
    }else if(k == n-1){
        cout << max(dp[n-2], arr[n-1] + dp[n-1]) << endl;
    }else{
        int kek[n-k];
        kek[n-1] = dp[n-1];
        kek[n-2] = max(dp[n-2], arr[n-1] + kek[n-1]);

        for(int i=n-3; i>=k-1; i--){
            kek[i] = max(max(dp[i],
                             arr[i+1] + kek[i+1]),
                         arr[i+2] + kek[i+2]);
        }
        cout << kek[k-1] << endl;
    }

    return 0;
}
