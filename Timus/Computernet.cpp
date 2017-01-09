#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[10001];
int dist[10001],
    dist2[10001];
queue<int> Q;

int bfs(int root){
    fill(dist, dist+n+1, -1);
    //clear queue
    while(!Q.empty()){
        Q.pop();
    }

    Q.push(root);
    dist[root] = 0;

    int u;
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for(int i=0; i<adj[u].size(); i++){
            if(dist[ adj[u][i] ] == -1){
                Q.push( adj[u][i] );
                dist[ adj[u][i] ] = dist[u] + 1;
            }
        }
    }

    //return most distant vertex
    //cout << "distances from " << root << endl;
    int mx = 0, mx_vertex = 0;
    for(int i=1; i<=n; i++){
        //cout << "distance of " << i << " " << dist[i] << endl;
        if(mx < dist[i]){
            mx = dist[i];
            mx_vertex = i;
        }
    }

    return mx_vertex;
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n;

    int inp;
    for(int i=2; i<=n; i++){
        cin >> inp;
        adj[inp].push_back(i);
        adj[i].push_back(inp);
    }

    //a: most distant vertex from arbitrary vertex 1
    //b: most distant vertex from a
    //the vertices in between a and b are the ones we're looking for
    int a = bfs(1);
    int b = bfs(a);
    //dist2 contains distances from a while dist1 will contain distances from b
    for(int i=1; i<=n; i++){
        dist2[i] = dist[i];
    }
    //third bfs run to restore distances from b
    bfs(b);

    vector<int> ans;

    //cout << "a: " << a << " b: " << b << endl;

    if(dist[a]%2 == 0){
        int d = (dist[a]) / 2;

        for(int i=1; i<=n; i++){
            if(dist[i] == d && dist2[i] == d){
                ans.push_back(i);
            }
        }
    }else{
        int d1 = (dist[a]) / 2,
            d2 = d1 + 1;

        for(int i=1; i<=n; i++){
            if((dist[i] == d1 && dist2[i] == d2) || (dist[i] == d2 && dist2[i] == d1)){
                ans.push_back(i);
            }
        }
    }

    //output in ascending order
    sort(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}
