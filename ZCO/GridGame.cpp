#include <iostream>
#include <algorithm>

using namespace std;

struct cell{
    long with, without;
};

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int mat[n][n];
    cell dp[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
            dp[i][j].with = dp[i][j].without = 0;
        }
    }

    dp[0][0].without = mat[0][0];
    dp[0][0].with = mat[0][0] + max(mat[1][0], mat[0][1]) + mat[0][0];
    //initializing top row and leftmost column without values
    for(int i=1; i<n; i++){
        dp[i][0].without = dp[i-1][0].without + mat[i][0];
        dp[0][i].without = dp[0][i-1].without + mat[0][i];
    }

    //first pass calculating max values without the bonus
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            dp[i][j].without = mat[i][j] + max(dp[i-1][j].without, dp[i][j-1].without);
        }
    }

    //top row and leftmost column with values
    for(int i=1; i<n-1; i++){
        dp[i][0].with = mat[i][0] + max(max(dp[i+1][0].without,
                                            dp[i-1][0].with),
                                            dp[i][1].without);
        dp[0][i].with = mat[0][i] + max(max(dp[1][i].without,
                                            dp[0][i-1].with),
                                            dp[0][i+1].without);
    }

    //bottom left and top right corners
    dp[n-1][0].with = mat[n-1][0] + max(dp[n-2][0].with, dp[n-1][1].without);
    dp[0][n-1].with = mat[0][n-1] + max(dp[0][n-2].with, dp[1][n-1].without);

    //non extreme values
    for(int i=1; i<n-1; i++){
        for(int j=1; j<n-1; j++){
            dp[i][j].with = mat[i][j] + max(max(dp[i+1][j].without, dp[i-1][j].with),
                                            max(dp[i][j-1].with, dp[i][j+1].without));
        }
    }

    //bottom row and rightmost column
    for(int i=1; i<n-1; i++){
        dp[i][n-1].with = mat[i][n-1] + max(max(dp[i-1][n-1].with, dp[i][n-2].with),
                              dp[i+1][n-1].without);
        dp[n-1][i].with = mat[n-1][i] + max(max(dp[n-1][i-1].with, dp[n-2][i].with),
                              dp[n-1][i+1].without);
    }

    //rightmost bottom
    dp[n-1][n-1].with = mat[n-1][n-1] + max(dp[n-1][n-2].with, dp[n-2][n-1].with);

    //when all numbers are negative, it's better to not use the bonus,
    //hence the max
    cout << max(dp[n-1][n-1].with, dp[n-1][n-1].without) << endl;

    return 0;
}
