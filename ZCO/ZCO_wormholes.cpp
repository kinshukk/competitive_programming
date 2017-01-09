#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    unsigned long N, X, Y;
    cin >> N >> X >> Y;

    vector<pair<unsigned long, unsigned long> > contests (N);
    vector<unsigned long> a (X), b (Y);

    for(int i=0; i<N; i++){
        cin >> contests[i].first >> contests[i].second;
    }
    for(int i=0; i<X; i++){
        cin >> a[i];
    }
    for(int i=0; i<Y; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    unsigned long min_time = ULONG_MAX;
    for(int i=0; i<N; i++){
        //-1 because upper_bound gives index with value strictly greater than contest start time
        int reach = upper_bound(a.begin(), a.end(), contests[i].first) - a.begin() - 1;
        int leave = lower_bound(b.begin(), b.end(), contests[i].second) - b.begin();
        if(reach >= 0 && leave < b.size()){
            min_time = min(min_time, b[leave] - a[reach] + 1);
        }
    }

    cout << min_time << endl;

    return 0;
}
