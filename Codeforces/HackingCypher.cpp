#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <climits>
#include <string>
using namespace std;
using std::pair;
using std::make_pair;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;

int main(){
    ios_base::sync_with_stdio(false);
    string num;
    ull a, b, num_size, l, index;
    ll i;
    bool found = false;
    cin >> num;
    cin >> a >> b;
    num_size = num.length();
    // cout << num_size << endl;
    l = 1;
    // cout << "ayy0" << endl;

    bool rem_a[num_size], rem_b[num_size];
    ul rem_prev = 0;
    for(i=0; i<num_size; i++){
        rem_prev = ( (rem_prev*10)%a + (num[i] - '0') )%a;
        rem_a[i] = (rem_prev > 0)? true : false;
        // cout << i << " " << rem_prev << endl;
    }
    rem_prev = 0;
    for(i=num_size-1; i>=0; i--){
        // cout << i << " ";
        rem_prev = ( ((num[i] - '0')*l)%b + rem_prev ) % b;
        l = (l*10) % b;
        rem_b[i] = (rem_prev > 0)? true : false;
        // cout << i << " " << rem_prev << endl;
    }
    // cout << "ayy1" << endl;

    for(index=0; index < num_size-1; index++){
        //cout << rem_b[index] << " " << rem_a[index] << " " << num[index+1] << endl;
        if(!rem_b[index+1] && !rem_a[index] && (num[index+1] != '0')){
            break;
        }
    }
    // cout << "ayy1" << endl;
    if(index < num_size-1){
        cout << "YES" << endl;
        for(i=0; i<=index; i++){
            cout << num[i];
        }
        cout << endl;
        for(i=index+1; i<num_size; i++){
            cout << num[i];
        }
        cout << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
