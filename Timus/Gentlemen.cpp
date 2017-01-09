#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, w;
    cin >> w >> n;
    bool dp[n][w+1];
    short count[w+1];
    int arr[n], parent[w+1];

    fill(count, count+w+1, 0);
    fill(parent, parent+1+w, -1);

    for(int i=0; i<n; i++){
        cin >> arr[i];
        fill(dp[i], dp[i]+w+1, false);
    }



    for(int i=0; i<n; i++){
        //zero weight always reachable
        dp[i][0] = true;
        //only ith card's weight always reachable
        if(arr[i] <= w){
            dp[i][arr[i]] = true;
            if(parent[arr[i]] == -1){
                parent[arr[i]] = i;
            }
            if(count[arr[i]] == 0){
                count[arr[i]] = 1;
            }
        }

        for(int j=1; j<=w; j++){
            if(i > 0 && dp[i-1][j]){
                dp[i][j] = true;
            }
            if(arr[i] <= j && i > 0 && dp[i-1][j-arr[i]]){
                dp[i][j] = true;
                if(count[j] == 0){
                    count[j] = count[j-arr[i]];
                }else{
                    count[j]++;
                }

                //avoiding overflow
                if(count[j] > 2){
                    count[j] = 2;
                }

                if(parent[j] == -1){
                    parent[j] = i;
                }
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<=w; j++){
    //         if(dp[i][j]){
    //             cout << i << " " << j << endl;
    //         }
    //     }
    //     cout << endl;
    // }

    if(count[w] > 1){
        cout << -1 << endl;
    }else if(count[w] == 0){
        cout << 0 << endl;
    }else{
        int temp;

        while(w > 0){
            temp = parent[w];
            w -= arr[ parent[w] ];
            arr[temp] = 0;
        }

        vector<pair<int, int> > kek;

        for(int i=0; i<n; i++){
            if(arr[i] != 0){
                kek.push_back(make_pair(i+1, arr[i]));
            }
        }

        sort(kek.begin(), kek.end(), comparator);

        for(int i=0; i<kek.size(); i++){
            cout << kek[i].first << " ";
        }

        cout << endl;
    }

    return 0;
}
