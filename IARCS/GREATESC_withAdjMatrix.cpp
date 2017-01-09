//NOTE: Try Again
//Runtime Error in one test
#include <iostream>
using namespace std;

bool adj[3500][3500];
short level[3500];
short Q[3500];

int main(){

    const short mx = 5000;
    short n, inp1, inp2;
    long m;

    cin >> n >> m;
    for(short j=0; j<n; j++){
        for(short i=0; i<n; i++){
            adj[i][j] = false;
        }
    }


    for(short j=0; j<3500; j++){
        level[j] = mx;
    }

    for(long i=0; i<m; i++){
        cin >> inp1 >> inp2;
        --inp1; --inp2;
        adj[inp1][inp2] = true;
        adj[inp2][inp1] = true;
    }

    short src, dest;
    cin >> src >> dest;
    --src; --dest;

    short end = 0, start = 0;

    Q[end] = src;
    level[src] = 0;

    while(end >= start){
        short u = Q[start];

        for(short k=0; k<n; k++){
            if(adj[u][k] == true && level[k] == mx){
                level[k] = level[u] + 1;
                Q[++end] = k;
            }
        }
        start++;
    }

    if(level[dest] != mx){
        cout << level[dest] << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}
