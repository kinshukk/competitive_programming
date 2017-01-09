#include <iostream>
#include <algorithm>

using namespace std;
using std::pair;

bool comparator(pair<int, bool> a, pair<int, bool> b){
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, count, piles, cur_weight;
    cin >> n;
    pair<int, bool> arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i].first;
        arr[i].second = false;
    }
    sort(arr, arr+n, comparator);
    //initializing
    count = piles = cur_weight = 0;

    while(count < n){
        cur_weight = 0;
        for(int i=0; i<n; i++){
            if(arr[i].first >= cur_weight && !arr[i].second){
                arr[i].second = true;
                ++cur_weight;
                ++count;
            }
        }
        ++piles;
    }

    cout << piles << endl;
    return 0;
}
