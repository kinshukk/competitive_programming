#include <iostream>
using namespace std;

const int MOD = 20011;

int mat[301][301];
int ways[301][301][301][2] = {};
//for last argument, 0:from right, 1: from down

int main(){
    int r, c, d;
    cin >> r >> c >> d;

    for(int j=1; j<=r; j++){
        for(int i=1; i<=c; i++){
            cin >> mat[i][j];
        }
    }

    for(int i=0; i<=d; i++){
        ways[r][c][i][0] = 1;
        ways[r][c][i][1] = 1;
    }

    for(int i=c; i>0; i--){
        for(int j=r; j>0; j--){
            if(i == c && j == r){
                continue;
            }
            if(mat[i][j]){
                ways[j][i][d][1] = ways[j][i+1][1][0];
                ways[j][i][d][0] = ways[j+1][i][1][1];

                for(int p=0; p<d; p++){
                    ways[j][i][p][0] = (ways[j][i+1][p+1][0] + ways[j+1][i][1][1]) % MOD;
                    ways[j][i][p][1] = (ways[j+1][i][p+1][1] + ways[j][i+1][1][0]) % MOD;
                }
            }
        }
    }

    cout << ways[1][1][0][0] << endl;

    return 0;
}
