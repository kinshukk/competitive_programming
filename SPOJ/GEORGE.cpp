#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INFINITE = 1E6 + 1;

struct node{
    int ind, weight, g_start, g_end;
};

struct compare{
    bool operator()(const pair<int, int>& l, const pair<int, int>& r){
        return l.second < r.second;
    }
};

int n, m, a, b, k, g;

vector<node> adj[10000];
int times[1000];
bool done[1000];

int dijkstra(int start, int end){
    //first: vertex number, second: time taken to reach vertex
    times[start] = k;
    pair<int, int> src = make_pair(start, k);
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> Q;
    Q.push(src);

    while(!Q.empty()){
        pair<int, int> u = Q.top();
        Q.pop();

        for(int i=0; i<adj[u.first].size(); i++){
            int v = adj[u.first][i].ind;
            int t = 0;
            //if george is passing thru, road is blocked
            //luka will have to wait until george is gone
            //before beginning to traverse the road
            if(u.second >= adj[u.first][i].g_start && u.second <= adj[u.first][i].g_end){
                t = adj[u.first][i].g_end + adj[u.first][i].weight;
            }else{
                t = u.second + adj[u.first][i].weight;
            }

            if(t < times[v]){
                times[v] = t;
            }
            if(!done[v]){
                Q.push(make_pair(v, times[v]));
            }
        }
        done[u.first] = true;
    }

    return times[end];
}

int main(){
    cin >> n >> m >> a >> b >> k >> g;
    vector<int> g_vertices;
    int inp, inp_, inp__;

    for(int i=0; i<n; i++){
        done[i] = false;
        times[i] = INFINITE;
    }

    vector<node> temp;

    for(int i=0; i<m; i++){
        adj[i] = temp;
    }

    for(int i=0; i<g; i++){
        cin >> inp;
        --inp;
        g_vertices.push_back(inp);
    }

    for(int i=0; i<m; i++){
        cin >> inp >> inp_ >> inp__;
        inp--; inp_--;
        node n;
        n.weight = inp__;
        n.ind = inp_;
        n.g_start = -1;
        n.g_end = -1;
        adj[inp].push_back(n);
        n.ind = inp;
        adj[inp_].push_back(n);
        //^undirected graph
    }

    //populating times when george will start and end
    //visiting intersections
    int f = 0, s = g_vertices[0];
    int time_passed = 0;
    for(int i=1; i<g; i++){
        f = s;
        s = g_vertices[i];

        for(int i=0; i<adj[f].size(); i++){
            if(adj[f][i].ind == s){
                adj[f][i].g_start = time_passed;
                time_passed += adj[f][i].weight - 1;
                adj[f][i].g_end = time_passed;
                break;
            }
        }
    }

    //-1 because vertices are stored in 0-based numbering
    dijkstra(a-1, b-1);

    for(int i=0; i<n; i++){
        cout << i << " " << times[i] << endl;
    }

    return 0;
}
