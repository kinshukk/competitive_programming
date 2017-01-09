#include <bits/stdc++.h>
using namespace std;

pair<int, pair<int, int> > drifts[100];
vector<int> adj[100];
int num_trees = 0, n = 0;
bool done[100];

bool comparator1(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    return a.second.first < b.second.first;
}

bool comparator2(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    return a.second.second < b.second.second;
}

void dfs_visit(int src){
    queue<int> Q;
    Q.push(src);

    int v;
    while(!Q.empty()){
        v = Q.front();
        Q.pop();
        for(int i=0; i<adj[v].size(); i++){
            if(!done[ adj[v][i] ]){
                Q.push(adj[v][i]);
                done[ adj[v][i] ] = true;
            }
        }
    }
}

void dfs(){
    for(int i=0; i<n; i++){
        if(!done[i]){
            dfs_visit(i);
            num_trees++;
        }
    }
}

int main(){
    cin >> n;
    vector<int> temp;
    for(int i=0; i<n; i++){
        cin >> drifts[i].second.first >> drifts[i].second.second;
        drifts[i].first = i;
        adj[i] = temp;
        done[i] = false;
    }

    sort(drifts, drifts+n, comparator1);
    for(int i=0; i<n-1; i++){
        if(drifts[i].second.first == drifts[i+1].second.first){
            adj[drifts[i].first].push_back(drifts[i+1].first);
            adj[drifts[i+1].first].push_back(drifts[i].first);
            //cout << drifts[i].first+1 << " neighbor of " << drifts[i+1].first+1 << endl;
        }
    }

    sort(drifts, drifts+n, comparator2);
    for(int i=0; i<n-1; i++){
        if(drifts[i].second.second == drifts[i+1].second.second){
            adj[drifts[i].first].push_back(drifts[i+1].first);
            adj[drifts[i+1].first].push_back(drifts[i].first);
            //cout << drifts[i].first+1 << " neighbor of " << drifts[i+1].first+1 << endl;
        }
    }

    dfs();

    cout << num_trees-1 << endl;

    return 0;
}
