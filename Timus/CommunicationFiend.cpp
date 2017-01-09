#include <bits/stdc++.h>
using namespace std;

//cuz why not
const long long INFIN = LLONG_MAX/2;

struct upgrade{
    long long start, end, cost, type;
};

bool comparator(upgrade a, upgrade b){
    return a.start < b.start;
}

long long n, m;

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("INPUT.in", "r", stdin);
    cin >> n >> m;
    upgrade arr[m+10];
    string s;
    for(long long i=0; i<m; i++){
        cin >> arr[i].start >> arr[i].end >> arr[i].cost >> s;
        if(s == "Licensed"){
            arr[i].type = 1;
        }else if(s == "Pirated"){
            arr[i].type = 2;
        }else if(s == "Cracked"){
            arr[i].type = 3;
        }
    }

    sort(arr, arr+m, comparator);

    if(n == 1){
        cout << "Online\n0" << endl;
    }

    //dp[0][i] -> min cost for reaching licensed version i, INFIN if not reachable
    //dp[1][i] -> min cost for reaching pirated version i, INFIN if not reachable
    long long dp[2][n+1];
    long long ind = 0, j = 0;
    fill(dp[0], dp[0]+n+1, INFIN);
    fill(dp[1], dp[1]+n+1, INFIN);
    dp[1][1] = dp[0][1] = 0;

    for(long long i=1; i<n; i++){
        for(j=ind; j<m; j++){
            if(arr[j].start!=i) break;
            if(arr[j].end > n)  continue;

            switch(arr[j].type){
                case 1:
                    dp[0][ arr[j].end ] = min( dp[0][ arr[j].end ], dp[0][i] + arr[j].cost);
                    break;
                case 2:
                    dp[1][ arr[j].end ] = min( dp[1][ arr[j].end ], dp[1][i] + arr[j].cost);
                    dp[1][ arr[j].end ] = min( dp[1][ arr[j].end ], dp[0][i] + arr[j].cost);
                    break;
                case 3:
                    dp[0][ arr[j].end ] = min( dp[0][ arr[j].end ], dp[0][i] + arr[j].cost);
                    dp[1][ arr[j].end ] = min( dp[1][ arr[j].end ], dp[1][i] + arr[j].cost);
            }
        }
        ind = j;
    }

    dp[0][n] = min(dp[0][n], dp[1][n]);

    if( dp[0][n] < INFIN ){
        cout << "Online\n" << dp[0][n] << endl;
    }else{
        cout << "Offline" << endl;
    }
    return 0;
}
