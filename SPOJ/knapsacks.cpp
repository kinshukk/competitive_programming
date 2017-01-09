#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct item{
    unsigned int value, weight;
};

bool comparator(item first, item second){
    return first.weight > second.weight;
}

int main(){
    unsigned long long k;int n;
    vector<item> arr;
    scanf("%lld %d", &k, &n);
    unsigned int v, w;

    for(int i=0; i<n; i++){
        scanf("%d %d", &v, &w);
        item tmp;
        tmp.value = v; tmp.weight = w;
        arr.push_back(tmp);
    }
    int source = 1, dest = 0;

    sort(arr.begin(), arr.end(), comparator);

    //unsigned int knapsacks[n+1][k+1];
    unsigned long long lel[2][k+1];
    unsigned long long t1, t2;
    for(int i=0; i<=k; i++){
        lel[0][i] = 0;
    }
    for(int i=1; i<=n; i++){
        lel[source][0] = 0;
        for(int w=1; w<=k; w++){
            if(arr[i-1].weight <= (long long)w){
                lel[source][w] = max( (arr[i-1].value + lel[dest][w-arr[i-1].weight]), lel[dest][w]);
            }else{
                lel[source][w] = lel[dest][w];
            }
        }
        dest = source;
        source = (source == 1)? 0 : 1;
    }
    printf("%lld\n", lel[dest][k]);
    return 0;
}
