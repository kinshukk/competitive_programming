#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int count = 0, sum = 0, val = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == arr[i+1] || arr[i] == arr[i-1]){
            count++;
        }else{
            int l = i-1, h = i+1;
            val = 2*arr[i];

            while(l >= 0 && h <= n){
                sum = arr[l] + arr[h];
                if(sum == val){
                    count++;
                    break;
                }else if(sum < val){
                    h++;
                }else{
                    l--;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
