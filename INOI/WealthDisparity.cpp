#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> adj[100001];
long A[100001];
bool done[100001];
long lowest[100001];
long max_diff = LONG_MIN;

long dfs(int src){
    lowest[src] = A[src];
    for(int i=0; i<adj[src].size(); i++){
        //memoization
        lowest[src] = min( ( (done[adj[src][i]])? lowest[adj[src][i]] : dfs(adj[src][i])), lowest[src]);
    }
    max_diff = max( ( (A[src] - lowest[src] > 0)? A[src] - lowest[src] : 0) , max_diff);
    done[src] = true;
    return lowest[src];
}

int main(){
    int n;
    cin >> n;
    vector<int> temp;
    for(int i=1; i<=n; i++){
        cin >> A[i];
        adj[i] = temp;
        done[i] = false;
    }

    int inp, src;

    for(int i=1; i<=n; i++){
        cin >> inp;
        if(inp != -1){
            adj[inp].push_back(i);
        }else{
            src = i;
        }
    }

    dfs(src);

    cout << max_diff << endl;

    return 0;
}
