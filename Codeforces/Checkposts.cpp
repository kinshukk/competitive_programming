#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

const int sz = 1E5 + 1;
const int MOD = 1E9 + 7;
const long long INFIN = LLONG_MAX;

int n;
long costs[sz];
long long total_cost = 0, num_ways = 0;
vector<int> adj1[sz];
vector<int> adj2[sz];
bool done[sz];
stack<int> S_dist;

void dfs1(int src){
    for(int i=0; i<adj1[src].size(); i++){
        if(!done[ adj1[src][i] ]){
            done[ adj1[src][i] ] = true;
            dfs1(adj1[src][i]);
        }
    }
    S_dist.push(src);
}

void dfs2(int src){
    stack<int> S;
    S.push(src);
    long long mn = INFIN, count_mn = 0;

    while(!S.empty()){
        int u = S.top();
        S.pop();
        if(done[u]) continue;

        for(int i=0; i<adj2[u].size(); i++){
            int v = adj2[u][i];
            if(!done[v]){
                S.push(v);
            }
        }

        //min cost of checkpost in each SCC
        if(costs[u] == mn){
            count_mn++;
        }else if(costs[u] < mn){
            count_mn = 1;
            mn = costs[u];
        }
        done[u] = true;
    }

    total_cost += mn;
    num_ways = (num_ways > 0)? (num_ways * count_mn) % MOD : count_mn;
}

void kosaraju(){
    //first DFS
    fill(done, done+n+1, false);
    for(int i=1; i<=n; i++){
        if(!done[i]){
            dfs1(i);
        }
    }

    //second DFS
    fill(done, done+n+1, false);
    while(!S_dist.empty()){
        int u = S_dist.top();
        S_dist.pop();
        if(!done[u]){
            dfs2(u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> costs[i];
    }
    int m, f, s;
    cin >> m;

    for(int i=0; i<m; i++){
        cin >> f >> s;
        adj1[f].push_back(s);

        //transpose adj list
        adj2[s].push_back(f);
    }

    kosaraju();

    cout << total_cost << " " << num_ways << endl;
    return 0;
}
