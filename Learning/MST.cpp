#include <bits/stdc++.h>
using namespace std;

const int sz = 2001;
int adj[sz][sz];
vector<pair<int, pair<int, int> > > edgeList;
int n, parent[sz], rank[sz];

bool comparator(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    return a.first < b.first;
}

int findSet(int a){
    if(parent[a] == a){
        return a;
    }else{
        parent[a] = findSet(a);
        return parent[a];
    }
}

bool isSameSet(int a, int b){
    return ( findSet(a) == findSet(b) );
}

//assumes a and b are not in the same set
void unionSet(int a, int b){
    int x = findSet(a), y = findSet(b);

    if(rank[x] > rank[y]){
        parent[y] = x;
    }else{
        parent[x] = y;

        if(rank[x] == rank[y]){
            rank[y]++;
        }
    }
}

long long MST(){
    parent[0] = -1;
    rank[0] = INT_MAX;
    for(int i=1; i<=n; i++){
        parent[i] = i;
        rank[i] = 0;
    }

    sort(edgeList.begin(), edgeList.end(), comparator);

    int l = (int)edgeList.size(), numEdges = 0;
    long long total = 0;
    for(int i=0; i<l; i++){
        int u = edgeList[i].second.first, v = edgeList.second.second, w = edgeList[i].first;

        if(!isSameSet(u, v)){
            numEdges++;
            total += w;
            unionSet(u, v);
        }
        if(numEdges == n-1){
            break;
        }
    }

    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> adj[i][j];
        }
    }

    for(int i=1; i<n; i++){
        for(int j=i+1; j<n; j++){
            edgeList.push_back( make_pair(adj[i][j], make_pair(i, j) ) );
        }
    }

    cout << MST() << endl;

    return 0;
}
