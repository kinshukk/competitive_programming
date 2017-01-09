#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    long long count;
    int n;
    long k;
    cin >> n >> k;
    long arr[n];
    count = 0;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);
    reverse(arr, arr+n);

    int R = n-1, L = 0;
    while(R > L){
        if(arr[R] + arr[L] < k){
            count += R - L;
            R--;
        }else{
            L++;
        }
    }

    cout << count << endl;
    return 0;
}
