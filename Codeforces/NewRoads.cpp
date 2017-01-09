//NOTE: Solution is WRONG
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, t, k;
    cin >> n >> t >> k;
    int dists[t+1];
    int max_num = 0;
    bool verdict = true;
    for(int i=1; i<=t; i++){
        cin >> dists[i];
        max_num = max(max_num, dists[i]);
        if(dists[i] == 0){
            verdict = false;
        }
    }

    if(!verdict || k < max_num){
        cout << -1 << endl;
    }else{
        vector<int> adj[n+1];
        vector<int> prev_verts[2];
        bool src = 0, dest = 1;
        prev_verts[src].push_back(0);

        int vert_number = 1;
        int connect_to;
        for(int i=1; i<=t; i++){
            for(int j=0; j<dists[i]; j++){
                connect_to = min((int)prev_verts[src].size()-1, j);
                adj[ prev_verts[src][ connect_to ] ].push_back(vert_number);
                prev_verts[dest].push_back(vert_number);
                vert_number++;
            }

            prev_verts[src].clear();
            swap(dest, src);
        }

        cout << n << "\n";

        for(int i=0; i<=n; i++){
            for(int j=0; j<adj[i].size(); j++){
                cout << i+1 << " " << adj[i][j]+1 << "\n";
            }
        }
    }

    return 0;
}
