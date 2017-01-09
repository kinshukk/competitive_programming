#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int main(){
    stack<int> stck;
    int n;
    int pos = 1, inp = 0, sp = 0, i = 0;
    bool rekt = false;
    cin >> n;
    while(n > 0){
        rekt = false;
        for(i=0; i<n; i++){

            cin >> inp;
            if(inp == pos){
                ++pos;
                cout << "first one :" << inp << endl;
            }else if(sp != 0){
                cout << "second one :" << inp << endl;
                if(pos == stck.top()){
                    while(pos == stck.top() && sp != 0){
                        sp--;
                        stck.pop();
                        pos++;
                    }
                }else{
                    stck.push(inp);
                    ++sp;
                }
            }else{
                cout << "third one :" << inp << endl;
                stck.push(inp);
                ++sp;
            }
        }
        while(pos <= n && stck.top() == pos && sp != 0){
            cout << stck.top() << endl;
            stck.pop();
            ++pos;
            --sp;
        }
        if(sp != 0){
            cout << "no" << endl;
            while(sp!=0){
                stck.pop();
                --sp;
            }
        }else{
            cout << "yes" << endl;
        }

        cin >> n;
    }
    return 0;
}
