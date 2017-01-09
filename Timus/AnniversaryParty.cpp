#include <bits/stdc++.h>
using namespace std;

const int sz = 6001;
int rating[sz],
    dp[sz][2];
int n;
vector<int> adj[sz];

void dfs(int parent, int node){
    int sum1 = 0, sum2 = 0;

    for(int i=0; i<adj[node].size(); i++){
        if(adj[node][i] == parent)  continue;

        dfs(node, adj[node][i]);

        sum1 += dp[ adj[node][i] ][0];
        sum2 += max(dp[ adj[node][i] ][0],
                    dp[ adj[node][i] ][1]);
    }

    dp[node][1] = sum1 + rating[node];
    dp[node][0] = sum2;
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> rating[i];
    }

    int a, b;
    cin >> a >> b;
    while(a != 0 && b != 0){
        adj[a].push_back(b);
        adj[b].push_back(a);
        cin >> a >> b;
    }

    dfs(0, 1);

    cout << max(dp[1][1], dp[1][0]) << endl;

    return 0;
}
