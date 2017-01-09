#include <bits/stdc++.h>
using namespace std;

const int sz = 1010;
const pair<int, int> no_parent = make_pair(-1, -1);
int r, c;
pair<int, int> src, dest, parent[sz][sz];
char mat[sz][sz];
queue<pair<int, int> > Q;

void bfs(){
    Q.push(src);
    parent[src.first][src.second] = no_parent;

    pair<int, int> left, right, up, down, u;

    while(!Q.empty()){
        u = Q.front();
        Q.pop();

        left = make_pair((u.first + c - 1)%c, u.second);
        if(mat[left.first][left.second] != '#' && parent[left.first][left.second] == no_parent){
            parent[left.first][left.second] = u;
            Q.push(left);
        }

        right = make_pair((u.first + 1)%c, u.second);
        if(mat[right.first][right.second] != '#' && parent[right.first][right.second] == no_parent){
            parent[right.first][right.second] = u;
            Q.push(right);
        }

        up = make_pair(u.first, (u.second + r - 1)%r);
        if(mat[up.first][up.second] != '#' && parent[up.first][up.second] == no_parent){
            parent[up.first][up.second] = u;
            Q.push(up);
        }

        down = make_pair(u.first, (u.second + 1)%r);
        if(mat[down.first][down.second] != '#' && parent[down.first][down.second] == no_parent){
            parent[down.first][down.second] = u;
            Q.push(down);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.in", "r", stdin);
    cin >> r >> c;

    for(int j=0; j<r; j++){
        for(int i=0; i<c; i++){
            cin >> mat[i][j];
            if(mat[i][j] == 'D')    dest = make_pair(i, j);
            if(mat[i][j] == 'M')    src = make_pair(i, j);
            parent[i][j] = no_parent;
        }
    }

    bfs();

    if(parent[dest.first][dest.second] == no_parent){
        cout << "NO" << endl;
    }else{
        cout << "YES\n";

        //mark path with 'X's
        pair<int, int> vert = parent[dest.first][dest.second];
        while(vert != src){
            mat[vert.first][vert.second] = 'X';
            vert = parent[vert.first][vert.second];
        }

        for(int j=0; j<r; j++){
            for(int i=0; i<c; i++){
                cout << mat[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
