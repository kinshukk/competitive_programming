#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){
    freopen("CulturalProgramme.in", "r", stdin);
    int n, p1, p2, count, max_count;
    cin >> n;
    int arr1[n], arr2[n];
    p1 = p2 = count = max_count = 0;

    for(int i=0; i<n; i++){
        cin >> arr1[i] >> arr2[i];
    }

    sort(arr1, n+arr1);
    sort(arr2, n+arr2);

    while(p1 < n){
        if(arr1[p1] < arr2[p2]){
            ++count;
            ++p1;
            if(count > max_count){
                max_count = count;
            }
        }else{
            --count;
            ++p2;
        }
    }
    cout << max_count << endl;
    return 0;
}
