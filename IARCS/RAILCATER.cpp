#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    long n, k;
    cin >> n >> k;
    long arr[n];
    cin >> arr[0];

    for(int i=1; i<n; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    // for(int i=0; i<n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    long max_total_after[n];
    max_total_after[n-1] = arr[n-1];

    for(int i=n-2; i>=0; i--){
        max_total_after[i] = max(arr[i], max_total_after[i+1]);
        //cout << max_total_after[i] << " ";
    }
    //cout << endl;

    long mx = INT_MIN;

    for(int i=0; i<(n-k+1); i++){
        mx = max(mx, max_total_after[i+k-1] - (i>0?arr[i-1]:0));
    }

    cout << mx << endl;

    return 0;
}
