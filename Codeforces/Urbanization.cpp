#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[100001];

bool comparator(int a, int b){
    return a > b;
}

int main(){
    int n, n1, n2;

    scanf("%d%d%d", &n, &n1, &n2);

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n, comparator);

    double mean = 0.0;
    double sum = 0.0, ind = min(n1, n2);

    for(int i=0; i<ind; i++){
        sum += arr[i];
    }
    mean += (sum)/((double)ind);
    sum = 0.0;

    for(int i=ind; i<ind+max(n1, n2); i++){
        sum += arr[i];
    }
    mean += ((double)sum)/((double)max(n1, n2));

    printf("%0.16g\n", mean);

    return 0;
}
