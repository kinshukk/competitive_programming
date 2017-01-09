#include <bits/stdc++.h>
using namespace std;

long fee[101][501];
long long dp[101][501];
pair<int, int> parent[101][501];
const pair<int, int> no_parent = make_pair(-1, -1);

void print(pair<int, int> lel){
    if(lel == no_parent){
        return;
    }else{
        print(parent[lel.first][lel.second]);
        cout << lel.second+1 << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> m >> n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> fee[i][j];
        }
    }

    for(int i=0; i<n; i++){
        dp[0][i] = fee[0][i];
        parent[0][i] = no_parent;
    }

    for(int i=1; i<m; i++){
        dp[i][0] = dp[i-1][0] + fee[i][0];
        parent[i][0] = make_pair(i-1, 0);
        //left to right
        for(int j=1; j<n; j++){

            if(dp[i-1][j] < dp[i][j-1]){
                parent[i][j] = make_pair(i-1, j);
                dp[i][j] = fee[i][j] + dp[i-1][j];
            }else{
                parent[i][j] = make_pair(i, j-1);
                dp[i][j] = fee[i][j] + dp[i][j-1];
            }
        }

        //right to left
        for(int j=n-2; j>=0; j--){
            if(dp[i][j] > fee[i][j] + dp[i][j+1]){
                dp[i][j] = fee[i][j] + dp[i][j+1];
                parent[i][j] = make_pair(i, j+1);
            }
        }
    }

    long long mn = LLONG_MAX;
    pair<int, int> mn_element = no_parent;
    for(int j=0; j<n; j++){
        if(mn > dp[m-1][j]){
            mn = dp[m-1][j];
            mn_element = make_pair(m-1, j);
        }
    }

    print(mn_element);

    cout << endl;

    return 0;
}
