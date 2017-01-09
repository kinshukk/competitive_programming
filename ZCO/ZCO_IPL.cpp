#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    unsigned long int n;
    scanf("%ld", &n);
    unsigned int arr[n+1];
    unsigned int dp[n+1];
    dp[0] = 0;
    arr[0] = 0;
    unsigned int total = 0;

    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
        total += arr[i];
    }
    dp[1] = arr[1];
    dp[2] = arr[2] + dp[1];

    for(int i=2; i<=n; i++){
        dp[i] = max(dp[i-1],
                    arr[i] + max(arr[i-1] + ((i-3>=0)?dp[i-3]:0),
                                dp[i-2]));
    }
    printf("%d\n", dp[n]);

    return 0;
}
