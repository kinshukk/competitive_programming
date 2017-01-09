#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k, g, t;

    cin >> n >> k;

    char arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i] == 'G'){
            g = i;
        }
        if(arr[i] == 'T'){
            t = i;
        }
    }

    int max_obs = 0, cur = 0;

    if(g < t){
        for(int i=g; i<=t; i+=k){
            if(arr[i] == '#'){
                cout << "NO" << endl;
                return 0;
            }else if(arr[i] == 'T'){
                cout << "YES" << endl;
                return 0;
            }
        }
    }else{
        for(int i=t; i<=g; i+=k){
            if(arr[i] == '#'){
                cout << "NO" << endl;
                return 0;
            }else if(arr[i] == 'G'){
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
