#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    bool adj[6][6];
    for(int i=0; i<6; i++){
        fill(adj[i], adj[i]+6, false);
    }

    int m, u, v;
    cin >> m;

    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u][v] = adj[v][u] = true;
    }

    for(int i=1; i<=5; i++){
        for(int j=i+1; j<=5; j++){
            for(int k=j+1; k<=5; k++){
                if(adj[i][j] && adj[j][k] && adj[i][k]){
                    cout << "WIN" << endl;
                    return 0;
                }else if(!adj[i][j] && !adj[j][k] && !adj[i][k]){
                    cout << "WIN" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "FAIL" << endl;

    return 0;
}
