#include <bits/stdc++.h>
using namespace std;

const int sz = 1001;
int arr[sz];

bool comp(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, k, j;
    cin >> n >> k;
    for(int i=0; i<k; i++){
        for(j=0; j<n; j++){
            cin >> arr[j];
        }

        for(j=n-1; j>=1; j--){
            if(arr[j] > arr[j-1]){
                j--;
                break;
            }
        }

        int ind = j+1;
        for(int k=j+1; k<n; k++){
            if(arr[k] > arr[j] && arr[k] < arr[ind]){
                ind = k;
            }
        }


        swap(arr[j], arr[ind]);
        for(int k=j+1; k<j+(n-j+1)/2 && k<n; k++){
            swap(arr[k], arr[n-(k-j)]);
        }


        for(j=0; j<n; j++){
            cout << arr[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
