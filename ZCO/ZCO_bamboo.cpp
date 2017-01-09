#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n; scanf("%d", &n);
    vector<int> arr;
    arr.reserve(n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    int mx;
    if(n == 1){
        mx = 1;
    }else{
        mx = 2;
    }
    int diff = 0, next = 0, count = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            count = 2;
            diff = arr[j] - arr[i];
            next = arr[j] + diff;
            for(int k=j+1; arr[k] <= next && k < n; k++){
                if(arr[k] == next){
                    count++;
                    next = next + diff;
                }
            }
            if(count > mx){
                mx = count;
            }
        }
    }
    printf("%d\n", mx);
    return 0;

}
