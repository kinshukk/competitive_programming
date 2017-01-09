#include <bits/stdc++.h>
using namespace std;

const int sz = 5005;
bool palindrome[sz][sz];
char inp[sz];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> inp[i];
    }

    for(int i=0; i<n; i++){
        fill(palindrome[i], palindrome[i]+i, true);
        fill(palindrome[i]+i+1, palindrome[i]+n, false);
        palindrome[i][i] = true;
    }

    for(int i=0; i<n-1; i++){
        if(inp[i] == inp[i+1]){
            palindrome[i][i+1] = true;
        }
    }

    int mx = 0;
    pair<int, int> ans = make_pair(0, 0);

    for(int l=1; l<n; l++){
        for(int i=0; i<=(n-l); i++){
            if(inp[i] == inp[i+l] && palindrome[i+1][i+l-1]){
                palindrome[i][i+l] = true;
                if(mx < l+1){
                    mx = l+1;
                    ans = make_pair(i, i+l);
                }
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << (palindrome[i][j]? 'O' : '.');
    //     }
    //     cout << endl;
    // }

    cout << mx << endl;
    for(int i=ans.first; i<=ans.second; i++){
        cout << inp[i];
    }
    cout << endl;
}
