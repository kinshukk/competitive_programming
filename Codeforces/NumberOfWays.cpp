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
    unsigned int n;
    cin >> n;
    long long s = 0, inp = 0, count = 0, tmp = 0;
    long long arr[n];
    for(int i=0; i<n; i++){
        cin >> inp;
        s += inp;
        arr[i] = s;
    }
    if(s % 3){
        cout << "0" << endl;
        return 0;
    }else{
        s /= 3;
        for(int i=0; i<n-1; i++){
            if(arr[i] == 2*s){
                count += tmp;
            }
            if(arr[i] == s){
                ++tmp;
            }

        }
        cout << count << endl;
    }
    return 0;
}
