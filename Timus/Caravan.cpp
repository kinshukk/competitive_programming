//NOTE: Incorrect solution
#include <bits/stdc++.h>
using namespace std;

const int sz = (int)1E5 + 1,
          INFIN = INT_MAX - 10;

int n, m, src, des, rob;
vector<int> adj[sz];
int r_dist[sz],
    s_dist[sz],
    parent[sz];
//first is parent of max distance from robbers
//second is distance of that parent from robbers
// pair<int, int> max_dist_parent[sz];

void bfs1(int root){
    queue<int> Q;
    Q.push(root);
    r_dist[root] = 0;

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++){
            if(r_dist[ adj[u][i] ] == INFIN){
                Q.push(adj[u][i]);
                r_dist[ adj[u][i] ] = r_dist[u] + 1;
            }
        }
    }
}

void bfs2(){
    // max_dist_parent[src] = make_pair(-1, INFIN);
    queue<int> Q;
    s_dist[src] = 0;
    parent[src] = -1;

    for(int i=0; i<adj[src].size(); i++){
        Q.push(adj[src][i]);
        s_dist[ adj[src][i] ] = 1;
        parent[ adj[src][i] ] = src;
    }

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++){
            if(s_dist[ adj[u][i] ] == INFIN){
                parent[ adj[u][i] ] = u;
                s_dist[ adj[u][i] ] = s_dist[u] + 1;
                Q.push(adj[u][i]);
            }else{
                //if parent vertex with greater distance from robbers is found, set this as parent of the vertex
                if(r_dist[ parent[ adj[u][i] ] ] < r_dist[u] && s_dist[u] == s_dist[ parent[ adj[u][i] ] ]){
                    parent[ adj[u][i] ] = u;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    fill(r_dist, r_dist+n, INFIN);
    //fill(max_dist_parent, max_dist_parent+n, make_pair(-1, 0));
    fill(s_dist, s_dist+n, INFIN);
    fill(parent, parent+n, -1);

    int u, v;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> src >> des >> rob;
    src--; des--; rob--;

    bfs1(rob);
    bfs2();

    int min_dist = INT_MAX, vert = des;
    while(vert != -1){
        //cout << vert << " -> ";
        min_dist = min(min_dist, r_dist[vert]);
        vert = parent[vert];
    }

    cout << min_dist << endl;

    return 0;
}
