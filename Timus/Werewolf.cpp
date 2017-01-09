#include <bits/stdc++.h>
using namespace std;

int n;
//first value is vertex number
//second value indicates whether the adjacent vertex is a parent of this vertex
vector<pair<int, bool> > adj[1001];
vector<int> dead;
bool suspected[1001], visited[1001];

void dfs1(int root){
    suspected[root] = false;
    visited[root] = true;
    for(int i=0; i<adj[root].size(); i++){
        //if this adjacent vertex is a parent
        if(adj[root][i].second && !visited[adj[root][i].first]){
            dfs1(adj[root][i].first);
        }
    }
}

void dfs2(int root){
    suspected[root] = false;
    visited[root] = true;
    for(int i=0; i<adj[root].size(); i++){
        //if this adjacent vertex is a child
        if(!adj[root][i].second && !visited[adj[root][i].first]){
            dfs2(adj[root][i].first);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    string inp;
    cin >> inp;
    int u, v;
    while(inp != "BLOOD"){
        stringstream(inp) >> u;
        cin >> inp;
        stringstream(inp) >> v;
        adj[u].push_back(make_pair(v, true));
        adj[v].push_back(make_pair(u, false));
        cin >> inp;
    }



    int input;
    while(cin >> input){
        dead.push_back(input);
    }

    fill(suspected, suspected+n+1, true);
    fill(visited, visited+n+1, false);

    for(int i=0; i<dead.size(); i++){
        dfs1(dead[i]);
    }

    fill(visited, visited+n+1, false);
    for(int i=0; i<dead.size(); i++){
        dfs2(dead[i]);
    }

    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(suspected[i])    cnt++;
    }

    if(cnt == 0){
        cout << 0 << endl;
    }else{
        for(int i=1; i<=n; i++){
            if(suspected[i]){
                cout << i << " ";
            }
        }
        cout << endl;
    }


    return 0;
}
