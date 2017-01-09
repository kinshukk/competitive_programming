#include <bits/stdc++.h>
using namespace std;

long long find_len(int a){
    long long ans = 1;
    for(int i=1; i<a; i++){
        ans = 2*ans + 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n; long long k;
    cin >> n >> k;

    int num = n;
    long long left = 1, right = find_len(n), mid = 0;
    //cout << right << endl;
    while(left <= right){
        mid = (left + right)/2;
        //cout << left << " " << mid << " " << right << " " << num << endl;
        if(mid == k){
            cout << num << endl;
            break;
        }else if(mid < k){
            --num;
            left = mid + 1;
        }else{
            --num;
            right = mid - 1;
        }
    }

    return 0;
}
