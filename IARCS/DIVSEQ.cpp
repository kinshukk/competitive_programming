#include <iostream>
#include <algorithm>
// #include <ctime>

using namespace std;

int arr[(int)1E4 + 10];
int l[(int)1E4 + 10];

int main(){
    ios_base::sync_with_stdio(false);
    // clock_t t;
    int n, mx;
    cin >> n;
    // t = clock();
    mx = 0;

    for(int i=0; i<n; i++){
        cin >> arr[i];
        l[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i] % arr[j] == 0){
                l[i] = max(l[i], l[j]+1);
            }
        }
        mx = max(mx, l[i]);
    }

    cout << mx << endl;
    // t = clock() - t;
    // cout << 4.0*((float)t / CLOCKS_PER_SEC) << endl;

    return 0;
}
