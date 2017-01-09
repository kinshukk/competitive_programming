#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    int arr[n];
    //points[i].first is index of greatest point starting where
    //the sequence until i is non-decreasing
    //points[i].second is last index starting where sequence is
    //non-increasing
    pair<int, int> points[n];

    cin >> arr[0];
    points[0].first = points[0].second = 0;

    for(int i=1; i<n; i++){
        cin >> arr[i];
        if(arr[i] >= arr[i-1]){
            points[i].first = points[i-1].first;
        }else{
            points[i].first = i;
        }

        if(arr[i] <= arr[i-1]){
            points[i].second = points[i-1].second;
        }else{
            points[i].second = i;
        }
    }

    int start, end;

    for(int i=0; i<m; i++){
        cin >> start >> end;
        --start;
        --end;

        if(points[ points[end].second ].first <= start){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }

    return 0;
}
