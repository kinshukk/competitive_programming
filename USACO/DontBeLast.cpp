#include <bits/stdc++.h>
using namespace std;

pair<int, string> cows[101];

bool comparator(pair<int, string> a, pair<int, string> b){
    if(a.first == b.first){
        if(a.second.compare(b.second) <= 0){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

int main(){
    freopen("notlast.in", "r", stdin);
    //freopen("notlast.out", "w", stdout);

    int n;
    cin >> n;

    return 0;
}
