//All test cases passed
#include <bits/stdc++.h>
using namespace std;

const int sz = 3001;

vector<int> adj[sz];
int degree[sz];
bool take[sz];

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, k;

    cin >> n >> m >> k;

    fill(degree, degree+sz, 0);
    fill(take, take+sz, true);

    int m1, m2;
    for(int i=0; i<m; i++){
        cin >> m1 >> m2;
        --m1; --m2;
        adj[m1].push_back(m2);
        adj[m2].push_back(m1);
        degree[m1]++;
        degree[m2]++;
    }

    /*
    As long as minimum in/out degree of haters' graph
    is less than k, remove the vertex with minimum degree
    and remove connection with adjacent vertices.
    The number of vertices left after completion of this loop
    is the max number of members possible in the task force
    */

    int min_degree = INT_MAX, minister = 0, num_left = n;

    for(int i=0; i<n; i++){
        if(degree[i] < min_degree && take[i]){
            min_degree = degree[i];
            minister = i;
        }
    }

    while(min_degree < k && num_left > 0){
        take[minister] = false;
        num_left--;

        for(int j=0; j<adj[minister].size(); j++){
            //remove connection with haters
            degree[ adj[minister][j] ]--;
        }

        //find min_degree for next iteration of removal of haters
        min_degree = INT_MAX;

        for(int i=0; i<n; i++){
            if(take[i] && degree[i] < min_degree){
                min_degree = degree[i];
                minister = i;
            }
        }
    }

    if(num_left > 0){
        cout << "YES\n" << num_left << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
