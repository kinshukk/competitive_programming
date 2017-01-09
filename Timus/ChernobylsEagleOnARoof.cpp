#include <bits/stdc++.h>
using namespace std;

const short sz = 1001;
//because reasons
const short ONE = (short)1;

//dp[i][j]: experiments required for i eggs and j floors
short dp[sz][sz];
//precalculated log2
short lg2[sz];

short mx(short a, short b){
    return (a>b)? a : b;
}

short mn(short a, short b){
    return (a<b)? a : b;
}

int main(){
    ios_base::sync_with_stdio(false);

    //time_t t = clock();

    lg2[0] = 0;
    for(short i=1; i<=sz; i++){
        dp[i][1] = 1;
        dp[i][0] = 0;
        dp[1][i] = i;
        lg2[i] = 1 + lg2[i/2];
    }
    short temp = 1000,
          p1 = 0,
          p2 = 0;

    //10 because log2(1000) < 10 so after 10 the answer is just log2(floors)
    for(short i=2; i<=10; i++){
        for(short j=2; j<sz; j++){
            temp = 1000;
            for(int k=1; k<=j; k++){
                //we might not have calculated some of the values of dp
                //therefore carefully picking the two cases
                //case 1: if egg breaks, n-1 eggs and k-1 floors(all those less than k) remain
                //case 2: if egg doesn't break, n-k floors and n eggs remain
                p1 = (lg2[k-1] <= i-1)? lg2[k-1] : dp[i-1][k-1];
                p2 = (lg2[j-k] <= i)? lg2[j-k] : dp[i][j-k];

                p1 = mx(p1, p2);
                temp = mn(temp, ONE+p1);
            }
            dp[i][j] = temp;
        }
    }

    // t = clock() - t;
    // cout << ((float)t/CLOCKS_PER_SEC) << endl;

    short a, b;
    cin >> a >> b;

    while(a != 0 || b != 0){
        if(a >= lg2[b]){
            cout << lg2[b] << "\n";
        }else{
            cout << dp[a][b] << "\n";
        }
        cin >> a >> b;
    }

    return 0;
}
