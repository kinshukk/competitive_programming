#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <climits>

using namespace std;
using std::pair;
using std::make_pair;

typedef long long ll;
typedef unsigned long long ull;

bool comparator(pair<ull, ull> a, pair<ull, ull> b){
    if(a.first == b.first){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    //pair<ull, ull> max_actual_pair = make_pair(0, 0);
    pair<ull, ull> arr[n];
    ull actual, previous, best;
    best = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr+n, comparator);
    for(int i=0; i<n; i++){
        if(best <= arr[i].second){
            best = arr[i].second;
        }else{
            best = arr[i].first;
        }
    }
    cout << best << endl;

    return 0;
}
