#include <bits/stdc++.h>
using namespace std;

const int sz = 200005;
const long long MOD = (long long)1E9 + 7;
pair<long long, long long> dfs_number[sz];
int adj[sz];
long long verts_done = 0;
long long cnt = 0, cycle_num = 0;
long long pow2[sz];

void dfs(int root){
    dfs_number[root] = make_pair(1, cycle_num);
    ++cycle_num;
    stack<int> S;
    S.push(root);

    while(!S.empty()){
        int v = S.top();
        S.pop();

        if(dfs_number[adj[v]].second == dfs_number[v].second){
            cnt = (cnt+(
                    (pow2[dfs_number[v].first - dfs_number[adj[v]].first + 1 ]) > 2 ? pow2[dfs_number[v].first - dfs_number[adj[v]].first + 1 ] - 2 : 0
                  )) % MOD;
            verts_done += dfs_number[v].first - dfs_number[adj[v]].first + 1;
        }else if(dfs_number[adj[v]].second == -1){
            dfs_number[adj[v]] = make_pair(dfs_number[v].first+1, dfs_number[v].second);
            S.push(adj[v]);
        }else{
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    fill(dfs_number, dfs_number+n+1, make_pair(-1, -1));
    for(int i=1; i<=n; i++){
        cin >> adj[i];
    }

    pow2[0] = 1;
    for(int i=1; i<=n; i++){
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }

    for(int i=1; i<=n; i++){
        if(dfs_number[i].first == -1){
            dfs(i);
        }
    }

    cnt = (cnt * pow2[n - verts_done]) % MOD;

    cout << cnt << endl;

    return 0;
}
