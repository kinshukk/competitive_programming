#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct point{
    unsigned int x, y;
};

bool comparator(point a, point b){
    if(a.y != b.y){
        return b.y > a.y;
    }else{
        return b.x > a.x;
    }
}

int main(){
    unsigned int n;
    scanf("%d", &n);
    vector<point> arr;
    arr.reserve(n+1);
    point p;
    for(unsigned int i=0; i<n; i++){
        scanf("%d %d", &p.x, &p.y);
        arr.push_back(p);
    }
    // p.x = 0; p.y = 0;
    // arr.push_back(p);
    p.x = 100000; p.y = 500;
    arr.push_back(p);
    sort(arr.begin(), arr.end(), comparator);

    // for(int i=0; i<n; i++){
    //     printf("\n%d %d\n", arr[i].x, arr[i].y);
    // }

    unsigned int y_mx = 0, width_mx = 0, y_prev = 0;
    vector<unsigned int> x_arr;
    x_arr.reserve(n+1);
    x_arr.push_back(0);
    unsigned int mx = 0;

    // printf("%ld\n", x_arr.size());

    for(int i=0; i<arr.size(); i++){
        width_mx = 0;
        y_mx = arr[i].y;
        for(int j=0; j<x_arr.size()-1; j++){
            width_mx = max(width_mx, x_arr[j+1] - x_arr[j]);
        }
        width_mx = max(width_mx, 100000 - x_arr[i]);
        mx = max(mx, y_mx*width_mx);
        y_prev = y_mx;
        x_arr.push_back(arr[i].x);
        // printf("\n");
        // for(int lel=0; lel<x_arr.size(); lel++){
        //     printf("%d ", x_arr[lel]);
        // }
        // printf("\n");
        // printf("\ni:%d width_mx:%d mx:%d\n", i, width_mx, mx);
        sort(x_arr.begin(), x_arr.end());
    }

    printf("%d\n", mx);
    return 0;
}
