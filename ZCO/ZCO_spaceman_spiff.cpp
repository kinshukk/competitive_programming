#include <stdio.h>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

struct Blaster{
    int x, y, start, freq;
};

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    bool dp[n][m];//true means safe false means unsafe
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            dp[j][i] = true;//marking everything safe initially
        }
    }

    for(int i=0; i<k; i++){
        Blaster b;
        scanf("%d %d %d %d", &b.y, &b.x, &b.start, &b.freq);
        for(int j=b.x; j>=0; j--){
            int time_taken = j+b.y-2 - b.start - b.x + j;
            if(time_taken < 0){
                continue;
            }else if(time_taken % b.freq == 0){
                dp[b.y][j] = false;//unsafe
            }
        }
        for(int j=b.x; j<m; j++){
            int time_taken = j+b.y-2 - b.start - j + b.x;
            if(time_taken < 0){
                continue;
            }else if(time_taken % b.freq == 0){
                dp[b.y][j] = false;//unsafe
            }
        }
        for(int i=b.y; i>=0; i--){
            int time_taken = i+b.x-2 - b.start - b.y + i;
            if(time_taken < 0){
                continue;
            }else if(time_taken % b.freq == 0){
                dp[i][b.x] = false;//unsafe
            }
        }
        for(int i=b.y; i<n; i++){
            int time_taken = i+b.x-2 - b.start + b.y - i;
            if(time_taken < 0){
                continue;
            }else if(time_taken % b.freq == 0){
                dp[i][b.x] = false;//unsafe
            }
        }
    }

    for(int i=1; i<m; i++){
        if(!dp[0][i-1]){
            dp[0][i] = false;
        }
    }


    for(int j=1; j<n; j++){
        if(!dp[j-1][0]){
            dp[j][0] = false;
        }
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(!dp[j-1][i] && !dp[j][i-1]){
                dp[j][i] = false;
            }
        }
    }

    if(!dp[n-1][m-1]){
        printf("NO\n");
    }else{
        printf("YES\n%d\n", n+m-2);
    }
    return 0;
}
