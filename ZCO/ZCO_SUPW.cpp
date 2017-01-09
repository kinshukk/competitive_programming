#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    long n;
    scanf("%ld", &n);
    int arr[n];
    int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i-1]);
        if(i<3){
            dp[i] = 0;
        }else{
            dp[i] = min( min( arr[i-1] + dp[i-1], arr[i-2] + dp[i-2] ),
                         arr[i-3] + dp[i-3]);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
