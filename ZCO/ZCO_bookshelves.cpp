#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, k, i;
    cin >> n >> k;
    int arr1[n], arr2[n];
    for(i=0; i<n; i++){
        cin >> arr1[i];
    }
    for(i=0; i<n; i++){
        cin >> arr2[i];
    }
    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    int skew = arr1[n-1] + arr2[n-1],
        greatest = max(arr1[n-1], arr2[n-1]);
    int abig, bbig, min_skew;
    for(int pos=1; pos<=k; pos++){
        abig = greatest + max(arr2[pos-1], arr1[n-pos-1]);
        bbig = greatest + max(arr1[pos-1], arr2[n-pos-1]);
        min_skew = min(abig, bbig);
        if(skew > min_skew){
            skew = min_skew;
        }
    }

    // int A[n], B[n];
    //
    // for (int i=0; i<n; i++) {
    //     cin >> A[i];
    // }
    // for (int i=0; i<n; i++) {
    //     cin >> B[i];
    // }
    //
    // sort (A, A+n);
    // sort (B, B+n);
    //
    // int skew = A[n-1]+B[n-1];
    // for (int pos=1; pos<=k; pos++) {
    //     int abig = max(A[n-1], B[n-1])+max(A[pos-1], B[n-pos-1]);
    //     int bbig = max(A[n-1], B[n-1])+max(B[pos-1], A[n-pos-1]);
    //     skew = min(skew, min(abig, bbig));
    // }
    cout << skew << endl;
    return 0;
}
