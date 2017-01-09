#include <bits/stdc++.h>
using namespace std;

const int sz = 1001;
vector<int> adj[sz];
bool present[sz];

// void dfs(int root, int cur_depth){
//     done[root] = true;
//     max_depth[root] = cur_depth;
//     for(int j=0; j<adj[root].size(); j++){
//         if(!done[ adj[root][j] ]){
//             dfs(adj[root][j], cur_depth + 1);
//         }
//         max_depth[root] = max(max_depth[root], max_depth[ adj[root][j] ]);
//     }
// }

// void dfs2(int root, int parent){
//
// }

int main(){
    ios_base::sync_with_stdio(false);
    int u, v;
    fill(present, present+sz, false);

    while(cin >> u >> v){
        adj[u].push_back(v);
        adj[v].push_back(u);
        present[v] = present[u] = true;
    }

    // for(int i=1; i<=1000; i++){
    //     if(!done[i] && present[i]){
    //         dfs(i, 1);
    //     }
    // }

    // fill(done, done+sz, false);
    //
    // for(int i=0; i<=1000; i++){
    //     if(!done[i] && present[i]){
    //         dfs2(i);
    //     }
    // }

    bool rekt = false;
    for(int i=1; i<=1000; i++){
        if(present[i]){
            if(adj[i].size() > 1){
            }else if(adj[ adj[i][0] ].size() > 1){
            }else{
                rekt = true;
                break;
            }
        }
    }

    // for(int i=1; i<1000; i++){
    //     if(present[i]){
    //         cout << i << "'s max depth: " << max_depth[i] << endl;
    //         if(max_depth[i] < 3){
    //             rekt = true;
    //         }
    //
    //     }
    // }

    if(rekt){
        cout << 0 << endl;
    }else{
        cout << 1 << endl;
    }

    return 0;
}
