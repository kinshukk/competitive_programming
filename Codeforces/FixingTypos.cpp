#include <iostream>
#include <climits>
#include <string>

using namespace std;

typedef unsigned long long ull;
typedef unsigned long ll;

int main(){
    ios_base::sync_with_stdio(false);
    string prev = "", cur = "", outp = "", input = "";
    cin >> input;
    cur += input[0];
    int i = 1;
    while(i < input.size()){
        //cout << prev << " " << cur << " " << outp << endl;
        char inp = input[i];
        if(inp == cur[0]){
               cur += inp;
        }else{
            if(prev.length() > 1 && cur.length() > 1){
                cur = cur[0];
            }else if(cur.length() > 2){
                  cur.resize(2);
            }
            outp += cur;
            prev = cur;
            cur = inp;
        }
        i++;
    }
    if(prev.length() > 1 && cur.length() > 1){
            cur = cur[0];
        }else if(cur.length() > 2){
              cur.resize(2);
        }
        outp += cur;
    cout << outp << endl;

    return 0;
}
