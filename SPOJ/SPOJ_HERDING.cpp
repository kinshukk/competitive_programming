#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <climits>

using namespace std;
using std::pair;
using std::make_pair;

typedef long long l64;
typedef unsigned long long ul64;
typedef long l32;
typedef unsigned long ul32;


int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int cycles = 0;
    pair<char, int> matrix[m][n];
    //first value for direction, second for group
    int cur_group = 1;


    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++){
            cin >> matrix[i][j].first;
            matrix[i][j].second = 0;
        }
    }

    pair<int, int> adj[m*n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j].first == 'S'){
                adj[i*n + j] = make_pair(i, j+1);
            }else if(matrix[i][j].first == 'E'){
                adj[i*n + j] = make_pair(i+1, j);
            }else if(matrix[i][j].first == 'W'){
                adj[i*n + j] = make_pair(i-1, j);
            }else{
                adj[i*n + j] = make_pair(i, j-1);
            }
        }
    }

    stack<pair<int, int> > stk;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j].second != 2){
                stk.push(make_pair(i, j));
                matrix[i][j].second = 1;
                while(!stk.empty()){
                    pair<int, int> next_node = adj[stk.top().first*n + stk.top().second];

                    if(matrix[next_node.first][next_node.second].second == 0){
                        //unvisited node, push to stack
                        stk.push(next_node);
                        matrix[next_node.first][next_node.second].second = 1;
                    }else if(matrix[next_node.first][next_node.second].second == 1){
                        //set color of all previous nodes in stack to finished(2) and empty stack; cycle found
                        ++cycles;
                        while(!stk.empty()){
                            pair<int, int> temp = stk.top();
                            stk.pop();
                            matrix[temp.first][temp.second].second = 2;
                        }
                    }else{
                        //previous cycle found, empty stack
                        while(!stk.empty()){
                            pair<int, int> temp = stk.top();
                            stk.pop();
                            matrix[temp.first][temp.second].second = 2;
                        }
                    }
                }
            }
        }
    }

    cout << cycles << endl;
    return 0;
}
