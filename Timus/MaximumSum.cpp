#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int mat[n+1][n+1];
    for(int j=1; j<=n; j++){
        for(int i=1; i<=n; i++){
            cin >> mat[i][j];
        }
    }

    for(int i=0; i<=n; i++){
        mat[0][i] = mat[i][0] = 0;
    }

    //calculating cumulative sums
    for(int j=1; j<=n; j++){
        for(int i=1; i<=n; i++){
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        }
    }


    int mx = -10000;
    for(int j=1; j<=n; j++){
        for(int i=1; i<=n; i++){
            for(int y=0; y<=j; y++){
                for(int x=0; x<=i; x++){
                    if(x == i && y == j){
                        continue;
                    }
                    mx = max(mx, mat[i][j] - ((y != j)? mat[i][y] : 0) - ((x != i)? mat[x][j] : 0) + mat[x][y]);
                }
            }
        }
    }

    cout << mx << endl;

    return 0;
}
