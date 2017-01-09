#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
using std::pair;

bool comparator(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2){
    return p1.second > p2.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, a, b; long diff = 0;
    //pair< pair<int, int>, int> book_pair;
    // long long sum1, sum2;
    cin >> n;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    int diffs[n];
    for(int i=0; i<n; i++){
        cin >> a >> b;
        diffs[i] = abs(a-b);
    }

    sort(diffs, diffs+n);
    reverse(diffs, diffs+n);

    for(int i=0; i<n; i++){
        diff = abs(diff - diffs[i]);
    }
    // pair< pair<int, int>, int> arr[n];
    //
    // for(int i=0; i<n; i++){
    //     cin >> book_pair.first.first >> book_pair.first.second;
    //     if(book_pair.first.second > book_pair.first.first){
    //         swap(book_pair.first.second, book_pair.first.first);
    //     }
    //     book_pair.second = abs(book_pair.first.first - book_pair.first.second);
    //     arr[i] = book_pair;
    // }
    // sort(arr, arr+n, comparator);
    //
    // sum1 = 0; sum2 = 0;
    // for(int i=0; i<n; i++){
    //     if(sum1 > sum2){
    //         sum1 += arr[i].first.second;
    //         sum2 += arr[i].first.first;
    //     }else{
    //         sum2 += arr[i].first.second;
    //         sum1 += arr[i].first.first;
    //     }
    // }
    //
    // cout << abs(sum2 - sum1) << endl;

    cout << diff << endl;
    return 0;
}
