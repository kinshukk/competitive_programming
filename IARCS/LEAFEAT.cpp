#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long arr[21];
long long total = 0;

long long gcd(long long a, long long b){
    for(;;){
        if(a == 0)  return b;
        b %= a;

        if(b == 0)  return a;
        a %= b;
    }
}

long long lcm(long long a, long long b){
    cout << "lcm of " << a << " " << b << " is " << (a*b)/gcd(a, b) << endl;
    return (a*b)/gcd(a, b);
}

long long recurse(int start, int len){
    if(len <= 1){
        cout << " end " << endl;
        return arr[start-1];
    }else{
        long long s = 0;
        for(int j=start; j<=k && k-len >= 0; j++){
            s += lcm(arr[j-1], recurse(j+1, len-1));
        }

        return s;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i=0; i<k; i++){
        cin >> arr[i];
    }
    sort(arr, arr+k);
    long long sum = 0, tmp = 0;

    for(int l=1; l<=k; l++){
        sum = 0;
        for(int i=1; i<=k; i++){
            if(k-i+1 < l){
                break;
            }
            tmp = recurse(i, l);
            cout << "tmp " << tmp << endl;
            if(tmp > 0){
                sum += n/tmp;
            }
        }
        total += (l%2 == 1)? sum : -sum;
        cout << "total " <<  total << endl;
    }

    cout << "total: " << total << endl;

    return 0;
}
