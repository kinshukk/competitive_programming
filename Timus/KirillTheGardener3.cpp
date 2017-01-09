#include <bits/stdc++.h>
using namespace std;

struct type{
    long long start, end, time;
};

bool comparator(pair<long long, long long> a, pair<long long, long long> b){
    if(a.second == b.second){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    pair<long long, long long> arr[n];

    vector<type> vec;

    for(long long i=0; i<n; i++){
        cin >> arr[i].second;
        arr[i].first = i;
    }

    sort(arr, arr+n, comparator);

    long long i, kind, num;
    type cur;
    cur.start = arr[0].first;
    kind = arr[0].second;
    num = 1;

    for(i=1; i<n; i++){
        if(arr[i].second != kind){
            cur.end = arr[i-1].first;
            cur.time = num + cur.end - cur.start;
            vec.push_back(cur);
            num = 1;
            cur.start = arr[i].first;
            kind = arr[i].second;
        }else{
            num++;
        }
    }

    cur.end = arr[i-1].first;
    cur.time = num + cur.end - cur.start;
    vec.push_back(cur);

    long long l = vec.size();
    long long dp[l+1][2];

    dp[0][0] = vec[0].start + vec[0].time;
    dp[0][1] = vec[0].end + vec[0].time;

    for(long long i=1; i<l; i++){
        dp[i][0] = vec[i].time + min(dp[i-1][1] + abs(vec[i-1].start - vec[i].start),
                                     dp[i-1][0] + abs(vec[i-1].end - vec[i].start) );
        dp[i][1] = vec[i].time + min(dp[i-1][1] + abs(vec[i-1].start - vec[i].end),
                                     dp[i-1][0] + abs(vec[i-1].end - vec[i].end) );
    }

    cout << min(dp[l-1][1], dp[l-1][0]) << endl;

    return 0;
}
