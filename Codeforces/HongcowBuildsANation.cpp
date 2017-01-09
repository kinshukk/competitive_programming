#include <bits/stdc++.h>
using namespace std;

vector<long long> adj[1001];
vector<long long> nations;
long long verts_reached = 0, max_verts = 1;
long long verts_to_add = 0;
bool done[1001];

void dfs(long long root){
    stack<long long> S;
    S.push(root);
    long long verts = 0, edges = 0;

    while(!S.empty()){
        long long v = S.top();
        S.pop();
        if(done[v]) continue;
        verts++;
        done[v] = true;
        edges += adj[v].size();

        for(long long i=0; i<adj[v].size(); i++){
            if(!done[adj[v][i]]){
                S.push(adj[v][i]);
            }
        }
    }

    verts_reached += verts;

    //undirected graph
    edges /= 2;
    long long max_possible = (verts * (verts-1))/2;
    verts_to_add += max(max_possible - edges, (long long)0);

    max_verts = max(max_verts, verts);
}

int main(){
    ios_base::sync_with_stdio(false);
    long long n, m, k;
    cin >> n >> m >> k;
    long long inp;
    fill(done, done+n+1, false);
    for(long long i=0; i<k; i++){
        cin >> inp;
        nations.push_back(inp);
    }

    long long u, v;
    for(long long i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(long long i=0; i<k; i++){
        dfs(nations[i]);
    }

    if(verts_reached < n){
        long long rem = 0;
        for(int i=1; i<=n; i++){
            if(done[i])continue;
            for(int j=0; j<adj[i].size(); j++){
                rem++;
            }
        }
        rem /= 2;

        long long remaining = n - verts_reached;
        verts_to_add += -rem + (remaining * (remaining-1))/2;
        verts_to_add += remaining*max_verts;
    }

    cout << verts_to_add << endl;

    return 0;
}
