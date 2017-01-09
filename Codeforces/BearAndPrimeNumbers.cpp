#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

unsigned int freq[10000001];
bool prime[10000001];
unsigned long num_multiples[10000001];

int main(){
    ios_base::sync_with_stdio(false);
    unsigned int inp, n;
    long l, r;
    cin >> n;

    //initialize
    fill(freq, freq+10000001, 0);
    fill(prime, prime+10000001, true);
    fill(num_multiples, num_multiples+10000001, 0);
    unsigned int mx = 0;

    //input values
    //count frequency of every number from 1 to 1E6
    //find max number
    for(unsigned int i=0; i<n; i++){
        cin >> inp;
        mx = max(mx, inp);
        freq[inp]++;
    }

    for(unsigned int i=2; i<=mx; i++){
        num_multiples[i] += num_multiples[i-1];
        if(prime[i]){
            for(int j=i; j<=mx; j += i){
                prime[j] = false;
                num_multiples[i] += freq[j];
            }
        }
    }

    unsigned int m;
    cin >> m;

    for(unsigned int i=0; i<m; i++){
        cin >> l >> r;
        if(l > mx){
            cout << 0 << endl;
        }else{
            r = min(r, (long)mx);
            cout << num_multiples[r] - num_multiples[l-1] << endl;
        }
    }

    return 0;
}
