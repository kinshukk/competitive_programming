#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string n;
    cin >> n;
    int len = n.length();
    long long result = 0;
    bool change = false;

    for(int i=0; i<len; i++){
        if(change || (n[i]-'0') == 1){
            result += 1 << (len-i-1);
        }else if( (n[i]-'0') > 1){
            result += 1 << (len-i-1);
            change = true;
        }
    }
    cout << result << endl;
    return 0;
}
