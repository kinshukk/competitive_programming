#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    long long mx = 0;
    long long arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+(sizeof(arr)/sizeof(arr[0])));
    for(int i = 0; i < n; i++){
        mx = max(mx, arr[i] * (n - i) );
    }
    cout << mx;
    return 0;
}
