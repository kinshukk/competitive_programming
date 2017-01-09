#include <bits/stdc++.h>
using namespace std;

long long sz = 1000005;
long long fact[1000005];
long long MOD = (long long)1E9 + 7,
          ans = 0;

long long exponent(long long a, long long p){
    long long ret = 1, tmp = a;
    while(p > 0){
        if(p%2){
            ret = (ret * tmp) % MOD;
        }

        tmp = (tmp * tmp) % MOD;
        p /= 2;
    }

    return ret;
}

long long combination(long long n, long long r){
    long long res = fact[n];
    res = ( res * exponent( (fact[n-r] * fact[r])%MOD, MOD-2) ) % MOD;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    fact[0] = fact[1] = 1;
    for(long long i=2; i<sz; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }

    int a, b, n;
    cin >> a >> b >> n;

    for(long long i=0; i<=n; i++){
        int num = i*a + (n-i)*b;
        bool flag = true;
        while(num > 0){
            if( num%10 != a && num%10 != b ){
                flag = false;
                break;
            }
            num /= 10;
        }

        if(!flag)   continue;

        ans = (ans + combination((long long)n, (long long)i) ) % MOD;
    }

    cout << ans << endl;

    return 0;
}
