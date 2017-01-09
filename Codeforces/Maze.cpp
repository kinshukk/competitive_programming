#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

char maze[502][502];
bool done[502][502];
int total = 0;
int n, m, k;

void dfs(int x, int y){
    done[x][y] = true;
    if(maze[x-1][y] == '.' && !done[x-1][y]){
        dfs(x-1, y);
    }
    if(maze[x][y-1] == '.' && !done[x][y-1]){
        dfs(x, y-1);
    }
    if(maze[x][y+1] == '.' && !done[x][y+1]){
        dfs(x, y+1);
    }
    if(maze[x+1][y] == '.' && !done[x+1][y]){
        dfs(x+1, y);
    }

    if(total < k){
        ++total;
        maze[x][y] = 'X';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    bool found = false;
    int src_x, src_y;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> maze[j][i];
            done[j][i] = false;
            if(!found){
                if(maze[j][i] == '.'){
                    found = true;
                    src_x = j;
                    src_y = i;
                }
            }
        }
    }

    for(int i=0; i<=n+1; i++){
        maze[0][i] = '#';
        maze[m+1][i] = '#';
        done[0][i] = true;
        done[m+1][i] = true;
    }
    for(int j=0; j<=m+1; j++){
        maze[j][0] =  '#';
        maze[j][n+1] = '#';
        done[j][0] = true;
        done[j][n+1] = true;
    }

    dfs(src_x, src_y);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << maze[j][i];
        }
        cout << endl;
    }

    return 0;
}
