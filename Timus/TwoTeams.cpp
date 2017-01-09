#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool done[101];
int bfs_number[101];
int n;

bool bfs(int root){
    queue<int> Q;
    Q.push(root);
    if(adj[root].size() == 0){
        return false;
    }

    done[root] = true;
    bfs_number[root] = 1;

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++){
            if(!done[ adj[u][i] ]){
                bfs_number[ adj[u][i] ] = (bfs_number[u] + 1)%2;
                done[ adj[u][i] ] = true;
                Q.push( adj[u][i] );
            }
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fill(bfs_number, bfs_number+101, -1);
    fill(done, done+101, false);

    int inp;
    for(int i=1; i<=n; i++){
        cin >> inp;
        while(inp != 0){
            adj[i].push_back(inp);
            cin >> inp;
        }
    }

    for(int i=1; i<=n; i++){
        if(!done[i]){
            if(!bfs(i)){
                cout << 0 << endl;
                return 0;
            }
        }
    }

    int count = 0;

    for(int i=1; i<=n; i++){
        count += bfs_number[i];
    }

    cout << count << endl;

    for(int i=1; i<=n; i++){
        if(bfs_number[i]){
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}
