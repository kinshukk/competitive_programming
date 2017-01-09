#include <iostream>
#include <algorithm>

using namespace std;

int c[200000];

int binary_search(int target, int end){
    int hi = end - 1, lo = 0, mid = (hi+lo)/2;
    while(lo <= hi){
        mid = (hi+lo))/2;
        if(target < c[mid]){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    return lo;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, inp, end, k;
    cin >> n;
    end = 0;

    for(int i=0; i<n; i++){
        cin >> inp;
        k = binary_search(inp, end);
        c[k] = inp;
        if(k == end){
            ++end;
        }
    }

    cout << n - end << endl;
    return 0;
}
