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

    if(n == 1){
        if(arr[0] == 0){
            cout << "UP" << endl;
        }else if(arr[0] == 15){
            cout << "DOWN" << endl;
        }else{
            cout << -1 << endl;
        }
        return 0;
    }

    if(arr[n-1] > arr[n-2]){
        if(arr[n-1] < 15){
            cout << "UP" << endl;
        }else{
            cout << "DOWN" << endl;
        }
    }else{
        if(arr[n-1] > 0){
            cout << "DOWN" << endl;
        }else{
            cout << "UP" << endl;
        }
    }

    return 0;
}
