#include <bits/stdc++.h>
using namespace std;

/**
We start DFS traversal from an arbitrary vertex.
Global value 'number' is kind of a DFS number for discovered edges, and we assign this to the vertices as we visit them.

Two cases arise:
    vertex with one adjacent vertex: Trivially we can give this edge any value

    vertex with more than one adjacent vertex: the parent edge and one of the other edges
        going out of this vertex will be x and x+1(DFS number).
        Now, since consecutive numbers are always co-prime, the GCD of all the adjacent edges
        from this vertex will be 1
*/

const int sz = 51;

vector<int> adj[sz];
int num[sz][sz];
//for output
vector<pair<int, int> > order;
int number = 1;

void dfs(int u){
    for(int i=0; i<adj[u].size(); i++){
        if(!num[u][ adj[u][i] ]){
            num[u][ adj[u][i] ] = num[ adj[u][i] ][u] = number;
            number++;
            dfs(adj[u][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=sz; i++){
        fill(num[i], num[i]+sz, 0);
    }

    int u, v;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        order.push_back(make_pair(u, v));
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    cout << "YES" << endl;

    for(int i=0; i<order.size(); i++){
        cout << num[ order[i].first ][ order[i].second ] << " ";
    }
    cout << endl;

    return 0;
}
