#include <bits/stdc++.h>
using namespace std;

const int sz = (int)1E5 + 10;

vector<int> adj[sz];
bool value[sz],
     req[sz];
vector<int> changed;
int n;
int flip[2];

void dfs(int node, int parent, int level){
    int parity = level%2;
    bool done = (value[node] == req[node]);

    if(flip[parity]%2 != 0){
        done = !done;
    }

    if(!done){
        changed.push_back(node);
        flip[parity]++;
    }

    for(int i=0; i<adj[node].size(); i++){
        if(adj[node][i] != parent){
            dfs(adj[node][i], node, level+1);
        }
    }

    if(!done) flip[parity]--;

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;

    int u, v;
    for(int i=0; i<n-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++){
        cin >> value[i+1];
    }

    for(int i=0; i<n; i++){
        cin >> req[i+1];
    }

    dfs(1, 0, 0);
    flip[0] = flip[1] = 0;

    //sort(changed.begin(), changed.end());

    cout << changed.size() << "\n";
    for(int i=0; i<changed.size(); i++){
        cout << changed[i] << "\n";
    }

    return 0;
}
