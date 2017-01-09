#include <bits/stdc++.h>
using namespace std;

int arr[45001];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        int j=i-1,
            cur = arr[i];

        while(j>=0 && arr[j] < cur){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = cur;
        cout << j+2 << "\n";
    }

    return 0;
}
