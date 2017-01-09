//NOTE: Incorrect solution
#include <stdio.h>
#include <cmath>
using namespace std;

int main(){
    int n, x, y;
    long double cw_min, acw_min, cw_max, acw_max, pivot, cur_angle, diff, rev;
    long double PI = 3.14159265358979323846;
    long double TAU = 2.0 * PI;
    cw_min = acw_min = 0.0;
    cw_max = acw_max = 0.0;
    scanf("%d", &n);

    scanf("%d%d", &x, &y);
    pivot = atan2((long double)x, (long double)y);

    for(int i=1; i<n; i++){
        scanf("%d%d", &x, &y);
        cur_angle = atan2((long double)x, (long double)y);
        diff = cur_angle - pivot;
        rev = TAU - diff;
        cw_min = (cw_min > diff)? diff : cw_min;
        acw_min = (acw_min > rev)? rev : acw_min;
        cw_max = (cw_max < diff)? diff : cw_max;
        acw_max = (acw_max < rev)? rev : acw_max;
    }

    double view_angle = ( ( (cw_max - cw_min < acw_max - acw_min)? cw_max - cw_min : acw_max - acw_min)*180.0)/PI;
    printf("%0.10g\n", view_angle);
    return 0;
}
