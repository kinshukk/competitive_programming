#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
using namespace std;

char mat[40][40];
bool done[40][40];
int n;

int dfs(pair<int, int>root){
    if(done[root.first][root.second]){
        return 0;
    }
    stack<pair<int, int> > S;
    S.push(root);
    done[root.first][root.second] = true;

    int total = 0;
    while(!S.empty()){
        pair<int, int> u = S.top();
        S.pop();

        if(u.first > 0 && mat[u.first-1][u.second] == '.'){
            if(!done[u.first-1][u.second]){
                S.push(make_pair(u.first-1, u.second));
                done[u.first-1][u.second] = true;
            }
        }else{
            total++;
        }

        if(u.first < n-1 && mat[u.first+1][u.second] == '.'){
            if(!done[u.first+1][u.second]){
                S.push(make_pair(u.first+1, u.second));
                done[u.first+1][u.second] = true;
            }
        }else{
            total++;
        }

        if(u.second > 0 && mat[u.first][u.second-1] == '.'){
            if(!done[u.first][u.second-1]){
                S.push(make_pair(u.first, u.second-1));
                done[u.first][u.second-1] = true;
            }
        }else{
            total++;
        }

        if(u.second < n-1 && mat[u.first][u.second+1] == '.'){
            if(!done[u.first][u.second+1]){
                S.push(make_pair(u.first, u.second+1));
                done[u.first][u.second+1] = true;
            }
        }else{
            total++;
        }
    }

    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
            done[i][j] = false;
        }
    }

    int walls = dfs(make_pair(0, 0));
    if(!done[n-1][n-1]){
        walls += dfs(make_pair(n-1, n-1));
    }

    walls -= 4;

    cout << (walls*9) << endl;

    return 0;
}
