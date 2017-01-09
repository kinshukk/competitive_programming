#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string pass;
    cin >> pass;
    string arr[10];
    for(int i=0; i<10; i++){
        cin >> arr[i];
    }
    for(int i=0; i<8; i++){
        string s1 = pass.substr(i*10, 10);
        // cout << s1 << endl;
        // cout << (i*10) << " " << (i*10)+10 << endl;
        for(int j=0; j<10; j++){
            if(arr[j] == s1){
                cout << j;
            }
        }
    }

    cout << endl;

    return 0;
}
