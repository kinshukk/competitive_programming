#include <bits/stdc++.h>
using namespace std;

const int sz = 301;
pair<int, int> parent[sz][sz];
int dp[sz][sz];
int arr1[sz], arr2[sz];
int n;
pair<int, int> mx_pair;

void n00b_LCS(){
    int mx = 0;
    mx_pair = make_pair(-1, -1);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=i+1; k<n; k++){
                for(int l=j+1; l<n; l++){
                    if(arr1[k]-arr1[i] == arr2[l] - arr2[j] && dp[i][j] + 1 >= dp[k][l]){
                        parent[k][l] = make_pair(i, j);
                        dp[k][l] = dp[i][j] + 1;
                    }
                }
            }
            if(mx < dp[i][j]){
                mx = dp[i][j];
                mx_pair = make_pair(i, j);
            }
        }
    }
}

void print_lcs(){
    pair<int, int> cur = mx_pair,
                   lel = make_pair(-1, -1);
    vector<int> bruh;
    bruh.reserve(n);
    while(cur != lel){
        bruh.push_back(arr1[cur.first]);
        cur = parent[cur.first][cur.second];
    }

    cout << bruh.size() << endl;

    for(int i=bruh.size()-1; i>=0; i--){
        cout << bruh[i] << " ";
    }
    cout << endl;
    bruh.clear();

    cur = mx_pair;
    while(cur != lel){
        bruh.push_back(arr2[cur.second]);
        cur = parent[cur.first][cur.second];
    }

    for(int i=bruh.size()-1; i>=0; i--){
        cout << bruh[i] << " ";
    }
    cout << endl;
    bruh.clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("INPUT.in", "r", stdin);
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }

    for(int i=0; i<n; i++){
        cin >> arr2[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = 0;
            parent[i][j] = make_pair(-1, -1);
        }
    }

    n00b_LCS();
    print_lcs();

    return 0;
}
