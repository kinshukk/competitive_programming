#include <bits/stdc++.h>
using namespace std;

int dist(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int vert = 0, hor = 0;
    char inp;
    int cnt = 1;
    pair<int, int> prev = make_pair(0, 0),
                   last = prev;
    int prev_dist = 0;
    int d = 0;
    for(int i=0; i<n; i++){
        prev = make_pair(vert, hor);
        cin >> inp;
        if(inp == 'R'){
            hor++;
        }else if(inp == 'L'){
            hor--;
        }else if(inp == 'U'){
            vert++;
        }else{
            vert--;
        }
        d = dist(last, make_pair(vert, hor));
        if(d <= prev_dist){
            cnt++;
            prev_dist = 0;
            last = prev;
        }else{
            prev_dist = d;
        }
    }

    cout << cnt << endl;

    return 0;
}
