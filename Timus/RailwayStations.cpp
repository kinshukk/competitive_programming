#include <bits/stdc++.h>
using namespace std;

const long long INFIN = (long long)1E10 + 10;
long stations[10005];
long long dp[10005];

int main(){
    ios_base::sync_with_stdio(false);
    long l1, l2, l3, num_stations, start, end;
    long long c1, c2, c3;

    cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3;
    cin >> num_stations >> start >> end;

    fill(dp, dp+10010, INFIN);

    if(start == end){
        cout << 0 << endl;
    }else{
        if(start > end){
            swap(start, end);
        }

        stations[1] = 0;

        for(long i=2; i<=num_stations; i++){
            cin >> stations[i];
        }

        dp[start] = 0;

        for(long i=start; i<end; i++){
            if(dp[i] == INFIN)  continue;
            long ind1 = upper_bound(stations+i, stations+num_stations, stations[i]+l1) - stations - 1,
                 ind2 = upper_bound(stations+i, stations+num_stations, stations[i]+l2) - stations - 1,
                 ind3 = upper_bound(stations+i, stations+num_stations, stations[i]+l3) - stations - 1;

            ind1 = min(ind1, end);
            ind2 = min(ind2, end);
            ind3 = min(ind3, end);

            dp[ind1] = min(dp[ind1], dp[i] + c1);
            dp[ind2] = min(dp[ind2], dp[i] + c2);
            dp[ind3] = min(dp[ind3], dp[i] + c3);
        }

        cout << dp[end] << endl;
    }

    return 0;
}
