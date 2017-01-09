//AC for all test cases
#include <stdio.h>
using namespace std;

int main(){
    //freopen("TIMBER.in", "r", stdin);
    int m, n;
    scanf("%d%d", &m, &n);
    int mat[m][n];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
            mat[i][j] += ( (i>0)? mat[i-1][j] : 0)
                        +( (j>0)? mat[i][j-1] : 0)
                        -( (i>0 && j>0)? mat[i-1][j-1] : 0);
        }
    }

    unsigned long c;
    scanf("%ld", &c);
    int x1=0, y1=0, x2=0, y2=0;
    long long count = 0;
    for(unsigned long i=0; i<c; i++){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        --x1; --x2; --y1; --y2;
        count = mat[x2][y2] - ( (x1 > 0)? mat[x1-1][y2] : 0 )
                            - ( (y1 > 0)? mat[x2][y1-1] : 0 )
                            + ( (x1 > 0 && y1 > 0)? mat[x1-1][y1-1] : 0);
        printf("%lld\n", count);
    }

    return 0;
}
