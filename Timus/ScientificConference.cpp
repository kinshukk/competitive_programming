#include <iostream>
#include <algorithm>
using namespace std;

bool comparator(pair<long, long> a, pair<long, long> b){
    return a.second < b.second;
}

int main(){
    long n;
    cin >> n;
    pair<long, long> arr[n];

    for(long i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr+n, comparator);

    long count = 1;
    long prev_finish = arr[0].second;
    for(long i=1; i<n; i++){
        if(arr[i].first > prev_finish){
            count++;
            prev_finish = arr[i].second;
        }
    }

    cout << count << endl;

    return 0;
}
