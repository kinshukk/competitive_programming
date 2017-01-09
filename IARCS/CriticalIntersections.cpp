#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> adj[300+1];
//low[u] denotes lowest possible node reachable from u
int dfs_number[300+1], low[300+1], parent[300+1];
bool visited[300+1], critical[300+1];
int c = 0;

void dfs(int node){
    visited[node] = true;
    dfs_number[node] = low[node] = c;
    ++c;

    for(int i=0; i<adj[node].size(); i++){
        int v = adj[node][i];
        if(visited[v]){
            if(v != parent[node]){
                low[node] = min(low[node], dfs_number[v]);
                //calculate min edge reachable from node except parent
                //because if only parent were the lowest edge reachable
                //from node then node won't be a a critical intersection
            }
        }else{
            parent[v] = node;
            dfs(v);
            low[node] = min(low[node], low[v]);
            if(dfs_number[node] <= low[v] && parent[node] != 0){
                critical[node] = true;
            }
        }
    }
    return;
}

int main(){
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    vector<int> temp;

    for(int i=0; i<m; i++){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    fill(low, low+n+1, 100000);
    fill(visited, visited+n+1, false);
    fill(parent, parent+n+1, -1);
    fill(critical, critical+n+1, false);
    dfs_number[0] = 0;
    parent[1] = 0;
    dfs(1);

    //second dfs run from a different vertex
    //to check if 1 is a critical intersection
    //hackish and non optimal but works
    fill(low, low+n+1, 100000);
    fill(visited, visited+n+1, false);
    fill(parent, parent+n+1, -1);
    parent[2] = 0;
    dfs_number[0] = 0;
    dfs(2);

    int count = 0;

    for(int i=1; i<=n; i++){
        if(critical[i]){
            count++;
        }
    }

    printf("%d\n", count);

    for(int i=1; i<=n; i++){
        if(critical[i]){
            printf("%d\n", i);
        }
    }

    return 0;
}
