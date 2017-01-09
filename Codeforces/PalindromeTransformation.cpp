#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int dist(int a, int b){
    a = a - 'a' + 1, b = b - 'a' + 1;
    return min(abs(b - a), abs(26 - max(a, b) + min(a, b)));
}

int main(){
    ios_base::sync_with_stdio(false);
    long n, p, last, temp, min_index, max_index;
    ll moves = 0;
    cin >> n >> p;
    char arr[n];
    last = n/2, min_index = n, max_index = 0;
    for(long i=0; i<n; i++){
        cin >> arr[i];
    }

    for(long i=0; i<last; i++){
        temp = (long long)dist((int)arr[i], (int)arr[n-i-1]);
        if(temp != 0){
            min_index = min(min_index, i);
            max_index = max(max_index, i);
        }
        moves += temp;
    }
    if(p > last){
        p = n-p;//mirror to the first half
    }else{
        --p;
    }
    // cout << moves << endl;
    // cout << max_index << " " << min_index << endl;
    if(min_index == n && max_index == 0){
        //no changes to make
        moves = 0;
    }else{
        //movement of cursor
        moves += max_index - min_index + min(abs(max_index - p), abs(p - min_index));
    }
    cout << moves << endl;
    return 0;
}
