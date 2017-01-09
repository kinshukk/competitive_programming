#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool weights[10];
int m;
vector<int> arr;

bool dfs(int balance, int parent, int moves){
    if(moves == m){
        cout << "YES" << endl;
        for(int i=0; i<arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return true;
    }

    bool result = false;

    for(int i=1; i<=10; i++){
        if(weights[i-1] && (parent != i) ){
            if(balance==0){
                arr.push_back(i);
                result = dfs(balance+i, i, moves+1);
                arr.pop_back();
            }else if( (moves%2 == 0) && (balance+i)*balance < 0){
                arr.push_back(i);
                result = dfs(balance+i, i, moves+1);
                arr.pop_back();
            }else if((balance-i)*balance < 0){
                arr.push_back(i);
                result = dfs(balance-i, i, moves+1);
                arr.pop_back();
            }
        }
        if(result){
            break;
        }
    }
    return result;
}

int main(){
    string inp;
    cin >> inp >> m;

    for(int i=0; i<10; i++){
        weights[i] = (inp[i] - '0' == 1)? true : false;
    }

    if(!dfs(0, 0, 0)){
        cout << "NO" << endl;
    }
    return 0;
}
