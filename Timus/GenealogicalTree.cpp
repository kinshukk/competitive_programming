#include <bits/stdc++.h>
using namespace std;

list<int> members;
vector<int> adj[101];
bool done[101];

void dfs(int root){
    done[root] = true;
    for(int i=0; i<adj[root].size(); i++){
        if(!done[ adj[root][i] ]){
            dfs(adj[root][i]);
        }
    }
    members.push_front(root);
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

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
            dfs(i);
        }
    }

    for(list<int>::iterator iter = members.begin(); iter != members.end();iter++){
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
