#include <stdio.h>
#include <algorithm>

using namespace std;

bool comparator(pair<long, long> a, pair<long, long> b){
    long d1 = abs(a.first) + abs(a.second),
         d2 = abs(b.first) + abs(b.second);
    return d1 < d2;
}

int main(){
    //freopen("Bombs.in", "r", stdin);
    int n;
    scanf("%d", &n);

    long count = 0;
    pair<long, long> arr[n];

    for(int i=0; i<n; i++){
        scanf("%ld %ld", &arr[i].first, &arr[i].second);
        if( (arr[i].second == 0) || (arr[i].first == 0) ){
            count += 4;
        }else{
            count += 6;
        }
    }
    sort(arr, arr+n, comparator);

    printf("%ld\n", count);

    long x, y;
    for(int i=0; i<n; i++){
        x = arr[i].first, y = arr[i].second;

        if(x > 0){
            printf("1 %ld R\n", x);
        }else if(x < 0){
            printf("1 %ld L\n", -x);
        }

        if(y > 0){
            printf("1 %ld U\n", y);
        }else if(y < 0){
            printf("1 %ld D\n", -y);
        }

        printf("2\n");

        if(x > 0){
            printf("1 %ld L\n", x);
        }else if(x < 0){
            printf("1 %ld R\n", -x);
        }

        if(y > 0){
            printf("1 %ld D\n", y);
        }else if(y < 0){
            printf("1 %ld U\n", -y);
        }
        printf("3\n");
    }
}
