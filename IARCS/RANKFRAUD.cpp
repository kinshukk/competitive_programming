#include <bits/stdc++.h>
using namespace std;

const int sz = 2005;
bool adj[sz][sz];

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("INPUT.in", "r", stdin);
    int n;
    cin >> n;
    for(int i=0; i<=n; i++){
        fill(adj[i], adj[i]+n+1, false);
    }

    int num, v;
    for(int i=1; i<=n; i++){
        cin >> num;
        for(int j=0; j<num; j++){
            cin >> v;
            adj[i][v] = true;
        }
    }

    list<int> L;
    L.push_back(1);
    for(int i=2; i<=n; i++){
        if(adj[ L.back() ][i]){
            L.push_back(i);
        }else if(adj[i][ L.front() ]){
            L.push_front(i);
        }else{
            list<int>::iterator iter = L.begin(),
                                tmp = iter;
            for(;iter != L.end(); iter++){
                tmp = iter;
                tmp++;
                if(adj[*iter][i] && adj[i][*tmp]){
                    L.insert(tmp, i);
                    break;
                }
            }
        }
    }

    cout << "YES" << endl;

    for(list<int>::iterator iter=L.begin(); iter != L.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
