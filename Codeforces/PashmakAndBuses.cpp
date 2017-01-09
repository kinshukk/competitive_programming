#include <iostream>

using namespace std;

const int MX = 1000+1;

int arr[MX][MX];

int main(){
    int n, d;
    long k;
    cin >> n >> k >> d;
    int pw = 1;
    bool not_rekt = false;

    for(int i=1; i<=d; i++){
        pw *= k;
        if(pw >= n){
            not_rekt = true;
            break;
        }
    }

    if(!not_rekt){
        cout << -1 << endl;
        return 0;
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<d; j++){
            arr[i][j] = arr[i-1][j];
        }
        for(int j=d-1; j>=0; j--){
            arr[i][j] = (arr[i][j] + 1) % k;
            if(arr[i][j] > 0){
                break;
            }
        }
    }

    for(int i=0; i<d; i++){
        for(int j=0; j<n; j++){
            cout << arr[j][i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
