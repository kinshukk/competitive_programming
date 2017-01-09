#include <bits/stdc++.h>
using namespace std;

const int sz = 1001;
int dist[sz][sz];
char perm[sz][sz][4];
bool done[sz][sz];

struct comp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return dist[a.first][a.second] > dist[b.first][b.second];
    }
};

priority_queue<pair<int, int>, vector<pair<int, int> >, comp > Q;

void dijkstra(int r, int c){
    Q.push( make_pair(0, 0) );
    dist[0][0] = 0;
    int x, y;

    while( !Q.empty() ){
        x = Q.top().first;
        y = Q.top().second;
        Q.pop();
        done[x][y] = true;
        int p = 0;

        for(int rot=0; rot<4; rot++){
            //up
            p = (4-rot-4 >= 0? 4-rot-4 : 4-rot);

            if(y > 0 && ( perm[x][y][ p ] == perm[x][y-1][2] ) ){
                //relax vertex above
                if(dist[x][y-1] > dist[x][y] + rot){
                    dist[x][y-1] = dist[x][y] + rot;
                }
                //add to queue if not yet visited
                if(!done[x][y-1]){
                    Q.push( make_pair(x, y-1) );
                }
            }

            //right
            p = (5-rot-4 >= 0? 5-rot-4 : 5-rot);
            if(x < c-1 && ( perm[x][y][ p ] == perm[x+1][y][3] ) ){
                //relax vertex to right
                if(dist[x+1][y] > dist[x][y] + rot){
                    dist[x+1][y] = dist[x][y] + rot;
                }

                if(!done[x+1][y]){
                    Q.push( make_pair(x+1, y) );
                }
            }

            //down
            p = (6-rot-4 >= 0? 6-rot-4 : 6-rot);
            if(y < r-1 && perm[x][y][ p ] == perm[x][y+1][0]){
                //relax vertex down below
                if(dist[x][y+1] > dist[x][y] + rot){
                    dist[x][y+1] = dist[x][y] + rot;
                }

                if(!done[x][y+1]){
                    Q.push( make_pair(x, y+1) );
                }
            }

            //left
            p = (7-rot-4 >= 0? 7-rot-4 : 7-rot);
            if(x > 0 && perm[x][y][ p ] == perm[x-1][y][1]){
                //relax vertex to left
                if(dist[x-1][y] > dist[x][y] + rot){
                    dist[x-1][y] = dist[x][y] + rot;
                }

                if(!done[x-1][y]){
                    Q.push( make_pair(x-1, y) );
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    string inp;
    int r, c;
    cin >> r >> c;
    // time_t t = clock();
    //cout << r << c;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            //cout << "INPUT: " << inp << endl;
            for(int k=0; k<4; k++){
                cin >> perm[j][i][k];
            }

            done[j][i] = false;
            //-1000 cuz y not
            dist[j][i] = INT_MAX - 1000;
        }
    }

    // t = clock() - t;
    // cout << ((float)t/CLOCKS_PER_SEC) << " seconds" << endl;
    // t = clock();


    dijkstra(r, c);

    cout << dist[c-1][r-1] << endl;

    // t = clock() - t;
    // cout << ((float)t/CLOCKS_PER_SEC) << " seconds" << endl;

    return 0;
}
