#include <bits/stdc++.h>
using namespace std;

long long arr[(int)1E5 + 1];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    arr[0] = 0;
    cin >> arr[1];
    for(int i=2; i<=n; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    int count = 0;

    for(int i=1; i<n; i++){
        //cout << arr[i] << " " << arr[n] - arr[i] << endl;
        if(2*arr[i] == arr[n]){
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
