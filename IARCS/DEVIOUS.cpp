#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    //freopen("INPUT.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, sum_till_here, inp;
    cin >> n;
    pair<int, int> arr[n];
    //same as initial ordering
    int left_alone[n];

    for(int i=0; i<n; i++){
        cin >> inp;
        sum_till_here += inp;
        arr[i].first = sum_till_here;
        left_alone[i] = inp;
        arr[i].second = i;
    }

    //sorting cumulative sum array
    sort(arr, arr+n, comparator);

    int cur_sum = 0,
        best_sum = INT_MAX,
        best_start = 0,
        best_end = 0;

    for(int i=0; i<n-1; i++){
        cur_sum = arr[i+1].first - arr[i].first;
        if(cur_sum < best_sum){
            best_sum = cur_sum;
            best_start = arr[i+1].second;
            best_end =  arr[i].second;
        }else if(cur_sum == best_sum && abs(arr[i+1].second - arr[i].second) > abs(best_start - best_end) ){
            best_start = arr[i+1].second;
            best_end =  arr[i].second;
        }
    }

    int i1, i2;

    if(best_start >= best_end){
        i1 = best_end+1;
        i2 = best_start;
    }else{
        i1 = best_start+1;
        i2 = best_end;
    }

    int sum = 0;
    for(int i=i1; i<=i2; i++){
        sum += left_alone[i];
    }
    cout << sum << endl;
    cout << i1+1 << " " << i2+1;

    return 0;
}
