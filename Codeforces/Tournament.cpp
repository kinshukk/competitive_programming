//WRONG SOLUTION
#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long n, cnt;
    cin >> n;
    cnt = 0;
    while(n > 1){
        n = (n%2) + n/2;
        cnt++;
    }
    cout << cnt << endl;
}
