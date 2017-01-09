#include <stdio.h>
#include <algorithm>
using namespace std;

const int mx = (int)1E6 + 10;
int blocks[mx];

int main(){
    int m, a, b;
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        blocks[i] = min(a, b);
    }
    sort(blocks, blocks+m);
    int side = 0;
    for(int i=0; i<m; i++){
        if(blocks[i] >= side+1){
            side++;
        }
    }

    printf("%d\n", side);

    return 0;
}
