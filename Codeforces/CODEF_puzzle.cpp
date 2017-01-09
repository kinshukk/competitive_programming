#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int arr[m];
    for(int i=0; i<m; i++){
        cin >> arr[i];
    }
    sort(arr, arr+m);
    // for(int i=0; i<m; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    int min_diff = arr[m-1] - arr[0];
    for(int i=0; i<=m-n; i++){
        min_diff = min(min_diff, arr[i+n-1] - arr[i]);
    }
    cout << min_diff << endl;
    return 0;
}
