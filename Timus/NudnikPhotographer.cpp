#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(n == 1 || n == 2){
        cout << 1 << endl;
    }else{
        unsigned long long dp[n+1];
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;

        for(int i=4; i<=n; i++){
            /*
            Three cases to consider:
            12*****:
                here we have to find acceptable permutations
                for 3456..n which is the same as that for
                2345...n-1
            132****:
                here we can have only 4 at the fourth position,
                hence we have to find acceptable permutations
                for 567..n which is the same as for 234..n-3
            1***..2:
                only one possible case for all n > 1
            */
            dp[i] = dp[i-1] + dp[i-3] + 1;
        }

        cout << dp[n] << endl;
    }
}
