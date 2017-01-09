#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct block{
    int x, y, z;
};

block make_block(int x, int y, int z){
    block b = {x, y, z};
    return b;
}

bool comparator(block a, block b){
    if(a.x > b.x){
        return false;
    }else if(a.x == b.x){
        if(a.y > b.y){
            return false;
        }else if(a.y == b.y){
            return a.z < b.z;
        }else{
            return true;
        }
    }else{
        return true;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    vector<block> arr;
    int a, b, c;
    while(n!=0){
        for(int i=0; i<n; i++){
            scanf("%d %d %d", &a, &b, &c);
            //dem permutations
            arr.push_back(make_block(a, b, c));
            arr.push_back(make_block(a, c, b));
            arr.push_back(make_block(b, a, c));
            arr.push_back(make_block(b, c, a));
            arr.push_back(make_block(c, a, b));
            arr.push_back(make_block(c, b, a));
        }
        int length = arr.size();

        sort(arr.begin(), arr.end(), comparator);

        int dp[length];
        dp[0] = arr[0].z;

        for(int i=1; i<length; i++){
            dp[i] = 0;
            for(int j=0; j<i; j++){
                if(arr[j].x < arr[i].x && arr[j].y < arr[i].y){
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += arr[i].z;
        }

        int mx = dp[0];
        for(int i=1; i<length; i++){
            mx = max(mx, dp[i]);
        }

        printf("%d\n", mx);

        arr.clear();

        scanf("%d", &n);
    }
}
