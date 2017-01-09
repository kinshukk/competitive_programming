#include <bits/stdc++.h>
using namespace std;

const int sz = 1001;
vector<int> adj[sz];
int pos[sz];

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i=0; i<m; i++){
        cin >> v >> u;
        //constructing transpose adjacency list
        adj[u].push_back(v);
    }

    //cout << "\nPOSITIONS:" << endl;

    for(int i=0; i<n; i++){
        cin >> u;
        pos[u] = i;
        //cout << u << " " << pos[u] << endl;
    }

    bool flag = true;

    for(int i=1; i<=n; i++){
        for(int j=0; j<adj[i].size(); j++){
            v = adj[i][j];
            //cout << v << " " << pos[v] << " " << u << " " << pos[u] << endl;
            if(pos[v] > pos[i]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;

    return 0;
}
