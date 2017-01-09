#include <iostream>
using namespace std;

long dp[11][82];

int main(){
    int sum;
    cin >> sum;

    if(sum == 1){
        //separate case for one because max value for s is 1E9
        //and only one can be in the leftmost place in 1E9
        //all other numbers will be in the range 0..(1E9 - 1)
        cout << 10 << endl;
    }else{
        //dp[d][s] is the number of ways to get sum s with d number of digits

        //0 ways to get any sum with 0 digits
        for(int s=0; s<=81; s++){
            dp[0][s] = 0;
        }

        for(int d=0; d<=9; d++){
            dp[1][d] = 1;
        }
        
        for(int d=10; d<= 81; d++){
            dp[1][d] = 0;
        }

        for(int i=2; i<=9; i++){
            for(int s=0; s<=9*i; s++){
                dp[i][s] = 0;
                for(int d=0; d<=min(9, s); d++){
                    dp[i][s] += dp[i-1][s-d];
                }
            }
        }
        cout << dp[9][sum] << endl;
    }

    return 0;
}
