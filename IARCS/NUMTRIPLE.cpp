#include <bits/stdc++.h>
using namespace std;

const int sz = 2001;
const long long INFIN = (long long) 1E8;
vector<pair<int, long long> > adj[sz];
long long dist[sz];
bool done[sz];

struct comp{
    bool operator()(pair<long long, int> a, pair<long long, int> b){
        return a.first > b.first;
    }
};

void dijkstra(int src){
    priority_queue<pair<long long, int> , vector<pair<long long, int> >, comp > Q;
    dist[src] = 0;
    Q.push(make_pair(0, src));

    while(!Q.empty()){
        int u = Q.top().second;
        long long d = Q.top().first;
        Q.pop();
        if(done[u]) continue;
        done[u] = true;

        for(int i=0; i<adj[u].size(); i++){
            if(dist[u] + adj[u][i].second < dist[ adj[u][i].first ]){
                dist[ adj[u][i].first ] = dist[u] + adj[u][i].second;
                Q.push(make_pair(adj[u][i].second, adj[u][i].first));
            }

        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("INPUT.in", "r", stdin);
    int m, a, b;
    cin >> m >> a >> b;
    fill(dist, dist+sz, INFIN);
    fill(done, done+sz, false);
    int u, v;
    long long w;
    for(int i=0; i<m; i++){
        cin >> u >> w >> v;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    dijkstra(a);

    if(dist[b] == INFIN){
        cout << "NO" << endl;
    }else{
        cout << "YES\n" << dist[b] << endl;
    }

    //for(int i=0; i<sz; i++){
    //    if(dist[i] != INFIN){
    //        cout << INFIN << " not equal to " << dist[i] << endl;
    //        cout << i << " " << dist[i] << endl;
    //    }
    //}

    return 0;
}
