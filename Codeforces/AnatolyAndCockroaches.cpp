#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string seq;
    cin >> seq;
    bool pos = 0;
    int x = 0, y = 0, fin = 0;

    for(int i=0; i<n; i++){
        if(pos){
            if(seq[i] != 'r'){
                x++;
            }
        }else{
            if(seq[i] != 'b'){
                y++;
            }
        }
        pos = !pos;
    }

    fin = max(x, y);
    x = y = 0;
    pos = 0;

    for(int i=0; i<n; i++){
        if(pos){
            if(seq[i] != 'b'){
                x++;
            }
        }else{
            if(seq[i] != 'r'){
                y++;
            }
        }
        pos = !pos;
    }

    fin = min(fin, max(x, y));

    cout << fin << endl;

    return 0;
}
