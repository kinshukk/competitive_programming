#include <bits/stdc++.h>
using namespace std;

const long long sz = 200005;
int n;
long long mx_subtree[sz], sum_subtree[sz], values[sz];
long long global_ans = LLONG_MIN;
vector<int> adj[sz];

bool comparator(pair<long long, int> a, pair<long long, int> b){
    return a.first > b.first;
}

void dfs1(int root, int parent){
    sum_subtree[root] = values[root];
    for(int i=0; i<adj[root].size(); i++){
        if(adj[root][i] != parent){
            dfs1(adj[root][i], root);

            sum_subtree[root] += sum_subtree[ adj[root][i] ];
            mx_subtree[root] = max(mx_subtree[root], mx_subtree[ adj[root][i] ]);
        }
    }
    mx_subtree[root] = max(mx_subtree[root], sum_subtree[root]);
}

void dfs2(int root, int parent, long long max_not_here){
    if(max_not_here != LLONG_MIN){
        global_ans = max(global_ans, sum_subtree[root] + max_not_here);
    }

    //max_set contains two maximum valued subtree sums
    vector<pair<long long, int> > max_set;
    for(int i=0; i<adj[root].size(); i++){
        if(adj[root][i] != parent){
            max_set.push_back( make_pair( mx_subtree[ adj[root][i] ], adj[root][i] ) );

            sort(max_set.begin(), max_set.end(), comparator);
            if(max_set.size() > 2){
                max_set.pop_back();
            }
        }
    }
    //sentinel value
    max_set.push_back( make_pair( LLONG_MIN, 0 ) );
    for(int i=0; i<adj[root].size(); i++){
        if(adj[root][i] != parent){
            long long other_max = (max_set[0].second == adj[root][i] )? max_set[1].first : max_set[0].first;
            dfs2(adj[root][i], root, max(max_not_here, other_max));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(long long i=1; i<=n; i++){
        cin >> values[i];
        mx_subtree[i] = LLONG_MIN;
    }

    long long a, b;
    for(long long i=0; i<n-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1, 0);
    dfs2(1, 0, LLONG_MIN);

    if(global_ans == LLONG_MIN){
        cout << "Impossible" << endl;
    }else{
        cout << global_ans << endl;
    }

    return 0;
}
