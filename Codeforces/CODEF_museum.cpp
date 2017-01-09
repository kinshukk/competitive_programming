#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int dist(char cur, char dest){
    cur = cur % 97;
    dest = dest % 97;
    return min( (int)abs((int)abs(25-max(cur, dest)) + 1 + min(cur, dest)), (int)abs(cur - dest));
}

int main(){
    int count = 0;
    string st;
    cin >> st;
    char current = 'a';
    for(int i=0; i<st.length(); i++){
        count += dist(current, st[i]);
        current = st[i];
    }
    cout << count << "\n";

    return 0;
}
