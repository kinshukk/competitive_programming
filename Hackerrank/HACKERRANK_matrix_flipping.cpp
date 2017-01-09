#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int arr[256][256];
    int q;
    cin >> q;
    int n, n2;
    long long outp = 0ll;

    for(int i=0; i<q; i++){
        cin >> n;
        n2 = 2*n;
        outp = 0ll;
        for(int j=0; j<n2; j++){
            for(int k=0; k<n2; k++){
                cin >> arr[j][k];
            }
        }
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                outp += max(max(arr[j][k], arr[n2-j-1][k]), max(arr[j][n2-k-1], arr[n2-j-1][n2-k-1]));
            }
        }
        printf("%lld\n", outp);
    }

    return 0;
}
