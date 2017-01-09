//NOTE: Not solved
#include <bits/stdc++.h>
using namespace std;

pair<int, int> dp[501];

bool comparator1(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

bool comparator2(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    //n-1 intersections
    //dp[i] indicates number of people passing
    //through ith span(0-based counting)
    for(int i=0; i<n-1; i++){
        dp[i] = make_pair(0, i);
    }

    vector<int> passengers;
    int tot = 0, inp = 0;
    for(int i=0; i<n-1; i++){
        passengers.clear();
        for(int j=i; j<n-1; j++){
            cin >> inp;
            passengers.push_back(inp);
        }
        int l=n-2;
        tot = 0;
        //cumulative sum from right to left
        for(int i=passengers.size()-1; i>=0; i--, l--){
            tot += passengers[i];
            dp[l].first += tot;
        }
    }

    // for(int i=0; i<n-1; i++){
    //     cout << dp[i].first << " " << dp[i].second << endl;
    // }

    //for getting greatest k values
    sort(dp, dp+n-1, comparator1);
    //for sorting into ascending order of span number
    sort(dp, dp+k, comparator2);

    tot = 0;
    for(int i=0; i<k; i++){
        tot += dp[i].first;
    }
    cout << tot << "\n";
    for(int i=0; i<k; i++){
        cout << dp[i].second + 1 << " ";
    }

    cout << endl;
    return 0;
}
