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
    sort(arr, arr+n);
    int count = 0;
    for(int i=0; i<=n-3; i += 3){
        if(arr[i] + k <= 5 && arr[i+1] + k <= 5 && arr[i+2] + k <= 5){
            count++;
        }
    }
    cout << count << endl;
}
