#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <climits>

using namespace std;
using std::pair;
using std::make_pair;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    ull arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    // count += min(r, min(g, b));
    //
    // r -= count;
    // g -= count;
    // b -= count;
    //
    // if(r == 0){
    //     first = min(g, b), second = max(g, b);
    // }else if(g == 0){
    //     first = min(r, b), second = max(r, b);
    // }else{
    //     first = min(r, g), second = max(r, g);
    // }
    //
    // if(second >= 2*first){
    //     count += ;
    // }else{
    //     count += (second + first) / 3;
    // }
    sort(arr, arr+3);

    if(2*(arr[0] + arr[1]) <= arr[2]){
        cout << arr[0] + arr[1] << endl;
    }else{
        cout << (arr[0] + arr[1] + arr[2])/3 << endl;
    }

    return 0;
}
