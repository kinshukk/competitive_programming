#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int N = 1E5 + 1;

vector<int> adj[N];
//dp[i][1] indicates the max costs
//of the tree rooted at element i taking
//the ith element. dp[i][0] indicates the
//cost excluding ith element
int costs[N], dp[N][2];

void dfs(int node, int parent){
    int sum0 = 0, sum1 = 0;

    for(int i=0; i<adj[node].size(); i++){
        int vert = adj[node][i];
        if(vert == parent){
            continue;
        }

        dfs(vert, node);

        sum1 += dp[vert][0];
        sum0 += max(dp[vert][1], dp[vert][0]);
    }

    dp[node][1] = costs[node] + sum1;
    dp[node][0] = sum0;
}


int main(){
    int n, inp, inp2;
    cin >> n;
    vector<int> temp;
    for(int i=0; i<n; i++){
        cin >> inp;
        costs[i] = inp;
        adj[i] = temp;
    }

    for(int i=0; i<n-1; i++){
        cin >> inp >> inp2;
        --inp; --inp2;
        adj[inp].push_back(inp2);
        adj[inp2].push_back(inp);
    }

    dfs(0, -1);

    cout << max(dp[0][1], dp[0][0]) << endl;

    return 0;
}
