#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char **argv){
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);

    vector<long long> arr;
    long long temp;
    for(int i=0; i<n; i++){
        scanf("%lld", &temp);
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    int count;
    for(int i=0; i<n; i++){
        temp = k - arr[i];
        for(int j=i+1; j<n; j++){
            if(arr[j] < temp){
                count = count + 1;
            }else{
                break;
            }
        }
    }
    cout << count << "\n";

    return  0;
}
