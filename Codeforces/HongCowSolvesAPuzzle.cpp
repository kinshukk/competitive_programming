#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    int count_vert[m], count_hor[n];
    int cnt = 0;
    int hor_start=INT_MAX, hor_end=0, vert_start=INT_MAX, vert_end =0;
    int tmp_vert = -1, tmp_hor = -1;

    int hor = 0, vert = 0;
    for(int i=0; i<n; i++){
        count_hor[i] = 0;
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'X'){
                count_hor[i]++;
            }
        }
        if(count_hor[i])    hor = count_hor[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 'X'){
                cnt++;
                if(hor_start == INT_MAX){
                    hor_start = j;
                }
                if(vert_start == INT_MAX){
                    vert_start = i;
                }
                tmp_hor = max(tmp_hor, j);
            }
        }
        if(!hor_end && (tmp_hor != -1)){
            hor_end = tmp_hor;
        }

    }

    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            if(arr[i][j] == 'X'){
                tmp_vert = max(tmp_vert, i);
            }
        }
        if(vert_end == 0 && (tmp_vert != -1)){
            vert_end = tmp_vert;
        }
    }

    int cnt2 = 0;

    for(int i=vert_start; i<=vert_end; i++){
        for(int j=hor_start; j<=hor_end; j++){
            if(arr[i][j] == 'X'){
                cnt2++;
            }
        }
    }



    for(int j=0; j<m; j++){
        count_vert[j] = 0;
        for(int i=0; i<n; i++){
            if(arr[i][j] == 'X'){
                count_vert[j]++;
            }
        }
        if(count_vert[j])   vert = count_vert[j];
    }

    for(int i=0; i<n; i++){
        if(count_hor[i] != 0 && count_hor[i] != hor){
            cout << "NO" << endl;
            return 0;
        }
    }

    for(int j=0; j<m; j++){
        if(count_vert[j] != 0 && count_vert[j] != vert){
            cout << "NO" << endl;
            return 0;
        }
    }

    if(cnt == cnt2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
