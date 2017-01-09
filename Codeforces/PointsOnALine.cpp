#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, d;
    long long count = 0;
    cin >> n >> d;

    int arr[n];

    for(long i=0; i<n; i++){
        cin >> arr[i];
    }

    for(long i=0; i<n; i++){
        //index of last element less than arr[i]+d
        int ind = upper_bound(arr+i, arr+n, arr[i]+d) - arr - i - 1;

        if(ind >= 2){
            //cout << i << " " << ind << endl;
            //nC2 ways to choose elements other than arr[i]
            count += ( (ind * (ind-1)) / 2);
        }
    }

    cout << count << endl;

    return 0;
}
