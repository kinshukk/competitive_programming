#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool prime(unsigned long long n){
    for(unsigned long long i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    unsigned long long n, lim, cnt;
    cin >> n;

    cnt = 0;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    if(n%2 != 0){
        if(prime(n)){
            cnt = 1;
        }else if(prime(n-2)){
            cnt = 2;
        }else{
            cnt = 3;
        }
    }else{
        if(n == 2){
            cnt = 1;
        }else{
            cnt = 2;
        }
    }

    cout << cnt << endl;
    return 0;
}
