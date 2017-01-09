#include <bits/stdc++.h>
using namespace std;

map<int, int> m;

int main(){
    ios_base::sync_with_stdio(false);
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int inp;
    for(int i=0; i<n1; i++){
        cin >> inp;
        if(m.find(inp) == m.end()){
            m[inp] = 1;
        }else{
            m[inp] = m[inp] + 1;
        }
    }

    for(int i=0; i<n2; i++){
        cin >> inp;
        if(m.find(inp) == m.end()){
            m[inp] = 1;
        }else{
            m[inp] = m[inp] + 1;
        }
    }

    for(int i=0; i<n3; i++){
        cin >> inp;
        if(m.find(inp) == m.end()){
            m[inp] = 1;
        }else{
            m[inp] = m[inp] + 1;
        }
    }

    int count = 0;

    for(map<int, int>::iterator ind = m.begin();
        ind != m.end();
        ind++){

        if(m[(*ind).first] >= 2){
            count++;
        }
    }

    cout << count << "\n";

    for(map<int, int>::iterator ind = m.begin();
        ind != m.end();
        ind++){

        if(m[(*ind).first] >= 2){
            cout << (*ind).first << "\n";
        }
    }



    return 0;
}
