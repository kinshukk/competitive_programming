#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    unsigned long long n;
    cin >> n;
    unsigned long long ans = 0;
    if(n <= 2){
        cout << n << endl;
    }else if(n == 3){
        cout << 6 << endl;
    }else{
        if(n%2 == 0){
            if(n%3 == 0){
                ans = (n-1)*(n-2)*(n-3);
            }else{
                ans = n*(n-1)*(n-3);
            }
        }else{
            ans = n*(n-1)*(n-2);
        }
        cout << ans << endl;
    }
    return 0;
}
