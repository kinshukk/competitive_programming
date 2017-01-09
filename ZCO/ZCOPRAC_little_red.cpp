#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

struct cell{
    int change;
    bool safe;
};

struct dpelement{
    int berries;
    bool safe;
};

int main(){
    ios::sync_with_stdio(false);

    int n, m, x, y, k;

    cin >> n >> m;
    dpelement dp[n+1][n+1];
    cell mat[n][n];
    for(int iii=0; iii<=n; iii++){
        dp[0][iii].berries = 0;
        dp[0][iii].safe = true;
    }
    for(int jjj=1; jjj<=n; jjj++){
        dp[jjj][0].berries = 0;
        dp[jjj][0].safe = true;
    }
    //input berry changes
    for(int iii=0; iii<n; iii++){
        for(int jjj=0; jjj<n; jjj++){
            cin >> mat[jjj][iii].change;
            mat[jjj][iii].safe = false;
        }
    }
    //assign unsafe cells
    for(int iii=0; iii<m; iii++){
        cin >> y >> x >> k;
        for(int i=x; i>=x-k && i >= 1; i--){
            for(int j=y; (x-i + y-j) <= k && j >= 1; j--){
                mat[i-1][j-1].safe = true;
            }
        }

        for(int i=x; i>x-k && i >= 1; i--){
            for(int j=y+1; (x-i + j-y) <= k && j <= n; j++){
                mat[i-1][j-1].safe = true;
            }
        }

        for(int i=x+1; i<=x+k && i <= n; i++){
            for(int j=y; (i-x + y-j) <= k && j >= 1; j--){
                mat[i-1][j-1].safe = true;
            }
        }

        for(int i=x+1; i<=x+k && i <= n; i++){
            for(int j=y+1; (i-x + j-y) <= k && j <= n; j++){
                mat[i-1][j-1].safe = true;
            }
        }
    }
    for(int iii=1; iii<=n; iii++){
        dp[1][iii].berries = mat[0][iii-1].change + dp[1][iii-1].berries;
        dp[1][iii].safe = mat[0][iii-1].safe && dp[1][iii-1].safe;
    }
    for(int jjj=1; jjj<=n; jjj++){
        dp[jjj][1].berries = mat[jjj-1][0].change + dp[jjj-1][1].berries;
        dp[jjj][1].safe = mat[jjj-1][0].safe && dp[jjj-1][1].safe;
    }

    for(int i=2; i<=n; i++){
        for(int j=2; j<=n; j++){
            // cout << mat[j-1][i-1].safe << endl;
            if(mat[j-1][i-1].safe == false){
                dp[j][i].safe = false;
                dp[j][i].berries = INT_MIN;
                // cout << "first :" << j << " " << i << endl;
            }else if((!dp[j-1][i].safe) && (!dp[j][i-1].safe)){
                dp[j][i].safe = false;
                dp[j][i].berries = INT_MIN;
                // cout << "second :" << j << " " << i << endl;
            }else{
                dp[j][i].safe = true;
                dp[j][i].berries = max((dp[j-1][i].safe)?(dp[j-1][i].berries + mat[j-1][i-1].change) : INT_MIN,
                                       (dp[j][i-1].safe)?(dp[j][i-1].berries + mat[j-1][i-1].change) : INT_MIN);
                // cout << "third :" << j << " " << i << endl;
            }
            // cout << dp[j][i].berries << endl;
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << mat[j][i].safe << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=n; j++){
    //         cout << ((dp[j][i].safe == true)?1:0) << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=n; j++){
    //         cout << dp[j][i].berries << " ";
    //     }
    //     cout << endl;
    // }

    if(dp[n][n].safe == true){
        cout << "YES\n" << dp[n][n].berries << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
