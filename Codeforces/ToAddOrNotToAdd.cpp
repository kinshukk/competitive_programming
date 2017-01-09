#include <bits/stdc++.h>
using namespace std;

int arr[100001];
long long s[100001];
int n, k;

int main(){
    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    s[0] = arr[0];
    for(int i=1; i<n; i++){
        s[i] = arr[i] + s[i-1];
    }

    long long best = 1, best_num = arr[0];

    for(long long i=1; i<n; i++){
        long long currbest = 1;
        long long lo = 0, hi = i-1, mid = (lo+hi)/2;
        while(lo <= hi){
            mid = (lo+hi)/2;
            //number of additions needed for selecting mid..i
            long long c = (i-mid+1)*arr[i] - (s[i] - ((mid > 0)? s[mid-1] : 0) );

            if(c>k){
                lo = mid+1;
            }else{
                currbest = max(currbest, i+1-mid);
                hi = mid-1;
            }
        }
        if(currbest > best){
            best = currbest;
            best_num = arr[i];
        }
    }

    cout << best << " " << best_num << endl;

    return 0;
}
