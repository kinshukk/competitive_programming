#include <bits/stdc++.h>
using namespace std;

const int sz = (int)1E5 + 1,
          INFIN = INT_MAX - 10;
const float mn = 1e-6;
int number[sz], parent[sz];
float prob[sz];
vector<pair<int, float> > adj[sz];

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, u, v, p, src, dest;
    cin >> n >> m >> src >> dest;

    fill(number, number+n+1, INFIN);
    fill(parent, parent+n+1, -1);
    fill(prob, prob+n+1, 2.0);

    for(int i=0; i<m; i++){
        cin >> u >> v >> p;
        adj[u].push_back(make_pair(v, p));
        adj[v].push_back(make_pair(u, p));
    }

    queue<int> Q;
    Q.push(src);
    number[src] = 1;
    prob[src] = 1.0;

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].first;
            float pr = prob[u] * (1.0 - (adj[u][i].second*1.0)/100.0);
            if(number[ v ] > number[u] + 1){
                // cout << u << " -> " << v << " " <<  pr << endl;
                number[ v ] = number[u] + 1;
                prob[ v ] = pr;
                parent[ v ] = u;
                Q.push(v);
            }
            else if(number[ v ] == number[u] + 1){
                // cout << u << " -> " << v << " " <<  pr << endl;
                if( pr - prob[ v ] >= mn ){
                    parent[ v ] = u;
                    prob[ v ] = pr;
                }
            }
        }
    }

    cout << number[dest] << " " << 1.0 - prob[dest] << endl;

    vector<int> path;
    while(dest != -1){
        path.push_back(dest);
        dest = parent[dest];
    }
    for(int i=path.size()-1; i>=0; i--){
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}
