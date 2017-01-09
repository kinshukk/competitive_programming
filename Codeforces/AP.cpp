#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using std::pair;
using std::make_pair;

int main(){
    unsigned int n;
    cin >> n;
    long arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    //storing frequencies of differencies along with differences
    pair<int, long> p1, p2;
    long diff_index = -1;

    //MUST...GET...ALL...EDGE...CASES.......uhhhhhh
    if(n == 1){
        cout << -1 << endl;
    }else if(arr[0] == arr[n-1]){
        cout << "1\n" << arr[0] << endl;
    }else if(n == 2){
        int mid = (arr[1] - arr[0]);
        if(mid == 0){
            cout << 1 << endl << arr[0] << endl;
        }else if(mid %2 == 0){
            cout << 3 << endl;
            cout << arr[0] - (arr[1] - arr[0]) << " " << (arr[0] + arr[1])/2 << " " << arr[1] + arr[1] - arr[0] << endl;
        }else{
            cout << "2\n" << arr[0] - mid << " " << arr[1] + mid << endl;
        }
    }else{
        int d = arr[1] - arr[0];
        for(int i=2; i<n; i++){
            d = min(d, (int)(arr[i] - arr[i-1]));
        }
        int lels = 0;
        long index = -1;
        for(int i=1; i<n; i++){
            int diff = arr[i] - arr[i-1];
            if(d == diff){
                continue;
            }

            if(d*2 == diff){
                index = i;
            }else{
                lels = 2;
            }
            lels++;
        }

        if(lels > 1){
            cout << "0" << endl;
        }else if(lels == 0){
            if(d == 0){
                cout << 1 << endl << arr[0] << endl;
            }else{
                cout << "2\n" << arr[0] - d <<  " " << arr[n-1] + d << endl;
            }
        }else if(lels == 1){
            cout << 1 << endl;
            cout << arr[index-1] + d << endl;
        }
    }

    return 0;
}
