#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    long n;
    cin >> n;
    int m = 0;
    bool flag = true;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n-1; i++){
        if(arr[i] % 2 == 0){
            continue;
        }else if(arr[i+1] > 0){
            arr[i+1]--;
        }else{
            cout << "NO\n";
            return 0;
        }
    }
    if(arr[n-1]%2 == 0){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}
