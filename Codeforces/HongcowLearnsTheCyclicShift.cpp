#include <bits/stdc++.h>
using namespace std;

string arr[100];

int main(){
    ios_base::sync_with_stdio(false);
    int ind = 0;
    string inp;
    cin >> inp;
    arr[0] = inp;
    bool flag = false;
    for(int i=0; i<inp.size(); i++){
        flag = false;
        inp = inp[inp.size()-1] + inp.substr(0, inp.size()-1);
        for(int j=0; j<=ind; j++){
            if(arr[j]== inp){
                flag = true;
                break;
            }
        }
        if(flag)    continue;
        ind++;
        arr[ind] = inp;
    }

    cout << ind + 1 << endl;


    return 0;
}
