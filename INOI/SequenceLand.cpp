#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

bool done[300];
vector<int> arr[300];

//returns true if a ids of a and b have k or more elements in
//common. ids of a and b are assumed to be sorted
bool is_relative(int a, int b, int k){
    int i1 = 0, i2 = 0, common = 0;
    while(i1<arr[a].size() && i2 < arr[b].size()){
        if(arr[a][i1] == arr[b][i2]){
            common++;
            i1++;
            i2++;
        }else if(arr[a][i1] < arr[b][i2]){
            i1++;
        }else{
            i2++;
        }
    }
    if(common >= k){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> inp;
    string temp;
    int num, tmp;
    for(int i=0; i<n; i++){
        done[i] = false;
        cin >> num;
        for(int j=0; j<num; j++){
            cin >> tmp;
            arr[i].push_back(tmp);
        }
        sort(arr[i].begin(), arr[i].end());
    }

    queue<int> Q;
    Q.push(0);

    int c = 0;

    //modified bfs
    while(!Q.empty()){
        int e = Q.front();
        Q.pop();
        if(!done[e]){
            done[e] = true;
            for(int i=0; i<n; i++){
                if( (!done[i]) && is_relative(e, i, k)){
                    Q.push(i);
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        if(done[i]){
            c++;//OOOOOOOOOO HAHAHAHAHAHA DAMN SON WHERE'D YOU FIND THAT
        }
    }

    cout << c << endl;

    return 0;
}
