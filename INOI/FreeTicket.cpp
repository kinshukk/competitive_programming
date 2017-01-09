#include <bits/stdc++.h>
using namespace std;

const long INF = 1E7;
long dist[240][240];
int c, f;

void floyd_warshall(){
    for(int i=1; i<=c; i++){
        dist[i][i] = 0;
    }

    for(int k=1; k<=c; k++){
        for(int i=1; i<=c; i++){
            for(int j=1; j<=c; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    long x, y, p;
    cin >> c >> f;
    for(int i=0; i<240; i++){
        fill(dist[i], dist[i]+240, INF);
    }

    for(int i=0; i<f; i++){
        cin >> x >> y >> p;
        dist[x][y] = dist[y][x] = p;
    }

    floyd_warshall();

    long mx = 0;

    for(int i=1; i<=c; i++){
        for(int j=1; j<=c; j++){
            mx = max(mx, dist[i][j]);
        }
    }

    cout << mx << endl;

    return 0;
}
