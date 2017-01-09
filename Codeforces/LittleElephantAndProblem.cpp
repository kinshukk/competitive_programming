#include <bits/stdc++.h>
using namespace std;

long arr1[100001], arr2[100001];

int main(){
    int n, fptr, sptr, faults;
    cin >> n;
    faults = 0;

    for(int i=0; i<n; i++){
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }
    sort(arr1, arr1+n);

    for(int i=0; i<n; i++){
        if(arr1[i] != arr2[i]){
            faults++;
        }
    }
    if(faults>2){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}
