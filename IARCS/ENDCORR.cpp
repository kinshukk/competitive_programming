#include <iostream>
#include <queue>
using namespace std;

int main(){
    //freopen("INPUT.in", "r", stdin);
    priority_queue<long, vector<long>, less<long> > Q;
    long m, n,inp;
    cin >> n >> m;
    while(m > 0 || n > 0){
        cin >> inp;
        if(inp == -1){
            cout << Q.top() << "\n";
            Q.pop();
            m--;
        }else{
            Q.push(inp);
            n--;
        }
    }
}
