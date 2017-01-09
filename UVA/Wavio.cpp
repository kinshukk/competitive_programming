#include <bits/stdc++.h>
using namespace std;

int seq[10005], l1[10005], l2[10005], c[10005];

int binary_search(int val, int end){
    int hi = end-1, lo = 0, mid = 0;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(val <= c[mid]){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return lo;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    while(cin >> n){
        for(int i=0; i<n; i++){
            cin >> seq[i];
        }

        int end1 = 0, end2 = 0;

        for(int i=0; i<n; i++){
            int k = binary_search(seq[i], end1);
            if(k == end1){
                end1++;
            }
            c[k] = seq[i];
            l1[i] = k+1;
        }

        for(int i=0; i<n/2; i++){
            swap(seq[i], seq[n-i-1]);
        }

        for(int i=0; i<n; i++){
            int k = binary_search(seq[i], end2);
            c[k] = seq[i];
            if(k == end2){
                end2++;
            }
            l2[n-i-1] = k+1;
        }

        int mx = 1;
        for(int i=0; i<n; i++){
            mx = max(mx, 2*min(l1[i], l2[i])-1);
        }

        cout << mx << endl;
    }
    //cout << endl;

    return 0;
}
