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
    int n, m, k, x, y, num;
    cin >> n >> m >> k;
    bool direction = true;//true for right, false for left;
    int lentubes = (n*m)/k;
    x = y = 1;
    num = 0;

    for(int i=0; i<k-1; i++){
        cout << lentubes << " ";
        for(int j=0; j<lentubes; j++){
            if(j < lentubes - 1){
                cout << y << " " << x << " ";
            }else{
                cout << y << " " << x << "\n";
            }
            if(direction){
                if(x < m){
                    ++x;
                }else{
                    ++y;
                    direction = false;
                }
            }else{
                if(x > 1){
                    --x;
                }else{
                    ++y;
                    direction = true;
                }
            }
            ++num;
        }
    }

    cout << (n*m) - num << " ";

    while(num < m*n){
        if(num < ( (m*n) - 1) ){
            cout << y << " " << x << " ";
        }else{
            cout << y << " " << x;
        }
        if(direction){
            if(x < m){
                ++x;
            }else{
                ++y;
                direction = false;
            }
        }else{
            if(x > 1){
                --x;
            }else{
                ++y;
                direction = true;
            }
        }
        ++num;
    }
    cout << endl;

    return 0;
}
