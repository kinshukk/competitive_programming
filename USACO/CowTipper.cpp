#include <bits/stdc++.h>
using namespace std;

bool arr[11][11];

void flip(int y, int x){
    // for(int i=0; i<=y; i++){
    //     for(int j=0; j<=x; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //
    // cout << "becomes" << endl;

    for(int i=0; i<=y; i++){
        for(int j=0; j<=x; j++){
            arr[i][j] = !arr[i][j];
            //cout << arr[i][j] << " ";
        }
        //cout << endl;
    }
}

int main(){
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int n;
    cin >> n;

    string inp;
    for(int i=0; i<n; i++){
        cin >> inp;
        for(int j=0; j<n; j++){
            arr[i][j] = (inp[j] - '0');
        }
    }

    int cnt = 0;
    for(int i=n-1; i>=0; i--){
        for(int j=i; j>=0; j--){
            if(arr[i][j]){
                flip(i, j);
                cnt++;
            }
            if(arr[j][i]){
                flip(j, i);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}
