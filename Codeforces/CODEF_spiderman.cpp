#include <iostream>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long splits = 0, temp = 0;
    for(long long i=0; i<n; i++){
        cin >> temp;
        splits += (temp - 1)%2;
        if(splits%2 == 0){
            cout << "2" << endl;
        }else{
            cout << "1" << endl;
        }
    }
    return 0;
}
