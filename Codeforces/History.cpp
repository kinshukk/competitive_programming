#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int sz = 100001;

pair<int, int> events[sz];

bool comparator(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> events[i].first >> events[i].second;
    }

    sort(events, events+n, comparator);
    int cnt = 0;

    unsigned int mx_end = 0;
    for(int i=0; i<n; i++){
        if(events[i].second < mx_end){
            cnt++;
        }else{
            mx_end = events[i].second;
        }
    }

    cout << cnt << endl;

    return 0;
}
