#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1E6;

//cnt[i].first: number of '.' in ith vertical line
//also number of repaints required to make entire line '#'
//cnt[i].second: number of '#' in ith vertical line
//also number of repaints required to make entire line '.'
pair<int, int> cnt[1001];
pair<long, long> dp[1001];

int main(){
    ios_base::sync_with_stdio(false);

    fill( cnt, cnt+1001, make_pair(0, 0) );
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    string inp;
    for(int i=1; i<=n; i++){
        cin >> inp;
        for(int j=1; j<=m; j++){
            if(inp[j-1] == '.'){
                cnt[j].first++;
            }else{
                cnt[j].second++;
            }
        }
    }

    dp[0].first = dp[0].second = 0;

    for(int i=1; i<=m; i++){
        dp[i].first = dp[i].second = INF;
    }

    for(int i=x; i<=m; i++){
        int cost1 = 0, cost2 = 0;
        for(int k=i; k>i-x; k--){
            cost1 += cnt[k].second;
            cost2 += cnt[k].first;
        }

        //'.' from i, '#' from i-x backwards
        dp[i].first = min(dp[i].first, cost1 + dp[i-x].second);
        dp[i].second = min(dp[i].second, cost2 + dp[i-x].first);

        for(int j=i-x; j>max(i-y, 0); j--){
            cost1 += cnt[j].second;
            cost2 += cnt[j].first;

            //cost of one color till here + cost starting with other color from j-1
            dp[i].first = min(dp[i].first, cost1 + ((j-1 > 0)? dp[j-1].second : 0));
            dp[i].second = min(dp[i].second, cost2 + ((j-1 > 0)? dp[j-1].first : 0));
        }
    }

    cout << min(dp[m].second, dp[m].first) << endl;

    return 0;
}
