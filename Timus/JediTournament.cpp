#include <bits/stdc++.h>
using namespace std;

struct attributes{
    int a, b, c;
};

string names[200];
bool will_win[200], marked[200];
vector<int> adj[200];
attributes att[200];

bool rekt(attributes f, attributes s){
    if(f.a > s.a && f.b > s.b || f.a > s.a && f.c > s.c || f.c > s.c && f.b > s.b){
        return true;
    }else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> names[i] >> att[i].a >> att[i].b >> att[i].c;
    }

    fill(will_win, will_win+n, false);
    fill(marked, marked+n, false);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if( i != j && rekt(att[i], att[j]) ){
                adj[i].push_back(j);
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        fill(marked, marked+n, false);
        stack<int> S;
        S.push(i);
        cnt = 1;
        marked[i] = true;

        while(!S.empty()){
            int u = S.top();
            S.pop();
            for(int j=0; j<adj[u].size(); j++){
                if(!marked[ adj[u][j] ]){
                    S.push(adj[u][j]);
                    marked[ adj[u][j] ] = true;
                    cnt++;
                }
            }
        }

        if(cnt == n){
            will_win[i] = true;
        }
    }

    for(int i=0; i<n; i++){
        if(will_win[i]){
            cout << names[i] << "\n";
        }
    }

    return 0;
}
