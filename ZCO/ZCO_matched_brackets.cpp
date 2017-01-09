#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long n;
    cin >> n;
    long cur_depth = 0, mx_depth = 0, mx_depth_start = 1,
         cur_start = 1, mx_symbol = 0, cur_symbol_count = 0,
         mx_symbol_start = 1;
    long inp;
    cur_depth = 0;
    for(long i=1; i<=n; i++){

        ++cur_symbol_count;
        cin >> inp;
        if(inp == 1){
            ++cur_depth;
            if(cur_depth > mx_depth){
                mx_depth = cur_depth;
                mx_depth_start = i;
            }

        }else if(inp == 2){
            --cur_depth;
            if(cur_depth == 0){
                if(mx_symbol < cur_symbol_count){
                    mx_symbol = cur_symbol_count;
                    mx_symbol_start = cur_start;
                }
                cur_start = i+1;
                cur_symbol_count = 0;
            }
        }
        // cout << cur_depth << " " << cur_start << " " << cur_symbol_count << endl;
    }
    // cout << endl;

    cout << mx_depth << " " << mx_depth_start << " " << mx_symbol << " " << mx_symbol_start << endl;
    return 0;
}
