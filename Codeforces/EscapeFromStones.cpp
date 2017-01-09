#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int l = s.length();

    list<int> stones;
    list<int>::iterator iter = stones.begin();

    //t = clock();
    stones.push_back(1);
    for(int i=0; i<l-1; i++){
        if(s[i] == 'l'){
            iter--;
            stones.insert(iter, i+2);
        }else if(s[i] == 'r'){
            stones.insert(iter, i+2);
        }

    }
    //t = clock() - t;
    //cout << ((float)t/CLOCKS_PER_SEC) << endl;

    for(iter = stones.begin(); iter != stones.end(); iter++){
        cout << *iter << "\n";
    }
    // cout << ((float)t/CLOCKS_PER_SEC) << endl;

    return 0;
}
