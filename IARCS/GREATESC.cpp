#include <iostream>
#include <queue>
#include <list>
using namespace std;

list<short> adj[3500];
short level[3500];
const short mx = 10000;

bool bfs(short src, short dest){
    queue<short> Q;
    Q.push(src);
    level[src] = 0;

    while(!Q.empty()){
        short u = Q.front(), v = 0;
        Q.pop();

        for(list<short>::iterator iter = adj[u].begin();
            iter != adj[u].end();
            iter++){
            v = *iter;
            //cout << "v: " << v << endl;
            if(level[v] == mx){
                level[v] = level[u] + 1;
                Q.push(v);
            }
            if(v == dest){
                return true;
            }
        }
    }
    if(level[dest] < mx){
        return true;
    }else{
        return false;
    }
}

int main(){
    //freopen("INPUT.in", "r", stdin);
    short n, inp1, inp2; long m;
    cin >> n >> m;


    for(short j=0; j<3500; j++){
        list<short> temp;
        adj[j] = temp;
        level[j] = mx;
    }

    for(long i=0; i<m; i++){
        cin >> inp1 >> inp2;
        --inp1; --inp2;
        adj[inp1].push_back(inp2);
        adj[inp2].push_back(inp1);
    }

    short src, dest;
    cin >> src >> dest;
    --src; --dest;

    if(bfs(dest, src)){
        cout << level[src] << endl;
    }else{
        cout << 0 << endl;
    }

    // for(short i=0; i<n; i++){
    //     cout << i << " " << level[i] << endl;
    // }
    return 0;
}
