#include <bits/stdc++.h>
using namespace std;

bool arr[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    int count = 0;
    int r, c;
    cin >> r >> c;

    int leftmost = INT_MAX, rightmost = 0;
    for(int i=0; i<r; i++){
        leftmost = INT_MAX, rightmost = 0;
        int cnt = 0;
        for(int j=0; j<c; j++){
            cin >> arr[i][j];
            if(arr[i][j]){
                leftmost = min(leftmost, j);
                rightmost = max(rightmost, j);
                cnt++;
            }
        }
        //cout << leftmost << " leftmost : rightmost " << rightmost << endl;
        if(rightmost < leftmost) continue;
        count += leftmost +
                 c - rightmost - 1 +
                 2 * ( (rightmost != leftmost)? max(0, rightmost - leftmost - 1 - (cnt - 2) ) : 0) ;
        //cout << count << endl;
    }


    int topmost = INT_MAX, bottom = 0;
    for(int j=0; j<c; j++){
        int cnt = 0;
        topmost = INT_MAX, bottom = 0;
        for(int i=0; i<r; i++){
            if(arr[i][j]){
                topmost = min(topmost, i);
                bottom = max(bottom, i);
                cnt++;
            }
        }
        //cout << bottom << " bottom : topmost " << topmost << endl;
        if(bottom < topmost) continue;
        count += topmost +
                 r - bottom - 1 +
                 2 * ( (topmost != bottom)? max(0, bottom - topmost - 1 - (cnt - 2) ) : 0 );
        //cout << count << endl;
    }

    cout << count << endl;
    return 0;
}
