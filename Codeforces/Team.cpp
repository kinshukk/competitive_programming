#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <climits>

using namespace std;
using std::pair;
using std::make_pair;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    ll n, m, diff;
    bool turn = true;
    cin >> n >> m;
    if(m > (2*n)+2 || m < n-1){
        cout << -1 << endl;
        return 0;
    }
    // diff = ((m-n)/2 > 0)?(m-n)/2 : 0;
    //m = m - diff;
    // cout << m << " " << n << " " << diff << endl;
    if(n <= m){
        while(n > 0 && m > 0){

            if(turn){
                // cout << 1;
                // --m;
                // if(diff > 0){
                //     cout << 1;
                //     --diff;
                // }
                if(m-1 > n){
                    cout << 11;
                    m -= 2;
                }else{
                    cout << 1;
                    m -= 1;
                }
            }else{
                cout << 0;
                --n;
            }
            turn = !turn;
        }
    }else{
        while(n > 0 && m > 0){
            if(turn){
                cout << 0;
                --n;
            }else{
                cout << 1;
                --m;
            }
            turn = !turn;
        }
    }
    if(m > 0){
        if(m-1 > n){
            cout << 11;
            m -= 2;
        }else{
            cout << 1;
            m -= 1;
        }
    }
    if(n > 0){
        cout << 0;
        --n;
    }
    cout << endl;

    return 0;
}
