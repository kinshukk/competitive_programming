#include <bits/stdc++.h>
using namespace std;

string arr[101];
//transpose adjacency matrix
vector<int> adj[101];
int n;
bool done[101];
//topologically sorted list
list<int> sorted;
int dp[101];

void dfs(int root){
    done[root] = true;
    for(int i=0; i<adj[root].size(); i++){
        if(!done[ adj[root][i] ]){
            dfs(adj[root][i]);
        }
    }
    sorted.push_front(root);
}

int main(){
    freopen("INPUT.in", "r", stdin);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        done[i] = false;
        dp[i] = 1;
    }

    //constructing adjacency list
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j)  continue;
            if(abs( (int)arr[i].size() - (int)arr[j].size() ) > 1){
                continue;
            }

            string s1, s2;
            if(arr[i].size() >= arr[j].size()){
                s1 = arr[i];
                s2 = arr[j];
            }else{
                continue;
            }
            for(int k=0; k<s1.size(); k++){
                if((s1.substr(0, k) + s1.substr(k+1, s1.size()-k-1)) == s2){
                    adj[j].push_back(i);
                    break;
                }
            }

            if(s1.size() == s2.size() && adj[j].size() > 0 && adj[j][ adj[j].size()-1 ] != i){
                int numdiff = 0;
                bool hopped = true;

                for(int k=0; k<s1.size(); k++){
                    if(s1[k] != s2[k]){
                        hopped = false;
                        numdiff++;
                        for(int l=k+1; l<s1.size(); l++){
                            if(s1[k] < s1[l] && s1[l] == s2[k]){
                                hopped = true;
                                break;
                            }
                        }
                        if(hopped == false){
                            break;
                        }
                    }
                }

                if(hopped && numdiff <= 1){
                    adj[j].push_back(i);
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        if(!done[i]){
            dfs(i);
        }
    }

    int mx = 1;
    sorted.reverse();

    for(list<int>::iterator iter=sorted.begin(); iter != sorted.end(); iter++){
        int vert = *iter;
        for(int i=0; i<adj[vert].size(); i++){
            dp[vert] = max(dp[vert], dp[ adj[vert][i] ] + 1);
        }
        cout << vert << " " << dp[vert] << " " << adj[vert].size() << endl;
        mx = max(dp[vert], mx);
        cout << arr[vert] << " from ";
        for(int i=0; i<adj[vert].size(); i++){
            cout << arr[ adj[vert][i] ] << " ";
        }
        cout << endl;
    }

    cout << mx << endl;

    return 0;
}
