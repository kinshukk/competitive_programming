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
    ull arr[100000], dp[100000];
    ull n, inp, i, tmp;

    for(ull i=0; i<100000; i++){
        arr[i] = 0;
    }

    cin >> n;
    tmp = 0;
    for(i=0; i<n; i++){
        cin >> inp;
        if(inp > tmp){
            tmp = inp;
        }
        arr[inp-1]++;
    }

    dp[0] = 1 * arr[0];
    dp[1] = max(dp[0], 2 * arr[1]);
    for(i=2; i<100000; i++){
        dp[i] = max(arr[i] * (i+1) + dp[i-2],
                    dp[i-1]);
    }

    cout << dp[i-1] << endl;
    return 0;
}
