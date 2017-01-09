#include <string.h>
#include <stdio.h>
#include <cmath>
#include <string>

using namespace std;

int distance(char *a, char* b, int i, int j){
    int dist = a[i] - b[j];
    return (dist>0)? dist : -dist;
}

int main(){
    int blank_value;
    char a[2001], b[2001];
    scanf("%s", a);
    scanf("%s", b);
    scanf("%d", &blank_value);
    int m = strlen(a), n = strlen(b);
    int c[m+1][n+1];
    c[0][0] = 0;
    for(int i=1; i<=m; i++){
        c[i][0] = c[i-1][0] + blank_value;
    }
    for(int j=1; j<=n; j++){
        c[0][j] = c[0][j-1] + blank_value;
    }

    for(int i=1;i<=m; i++){
        for(int j=1; j<=n; j++){
            c[i][j] = min( min(c[i-1][j] + blank_value, c[i][j-1] + blank_value),
                          distance(a, b, i-1, j-1) + c[i-1][j-1]);
        }
    }

    printf("%d\n", c[m][n]);
    return 0;
}
