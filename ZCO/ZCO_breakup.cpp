#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    bool is_palindrome = true;
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int dp[n+1];
    dp[0] = 0;
    int i, j, k, max_first;
    for(i=1; i<=n; i++){
        dp[i] = dp[i-1] + 1;
        for(j=i; j>0; j--){
            is_palindrome = true;
            for(k=j; k<=i; k++){
                if(arr[k-1] != arr[j+i-k-1]){
                    is_palindrome = false;
                    break;
                }
            }
            if(is_palindrome){
                dp[i] = min(dp[i], dp[j-1] + 1);
            }
        }
    }

    printf("%d\n", dp[n]);
    return 0;
}
