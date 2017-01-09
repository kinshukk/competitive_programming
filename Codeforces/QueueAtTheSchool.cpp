#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    string arr;
    cin >> arr;
    for(int i=0; i<t; i++){
        for(int j=0; j<n-1; j++){
            if(arr[j] == 'B' && arr[j+1] == 'G'){
                swap(arr[j], arr[j+1]);
                ++j;
            }
        }
    }

    cout << arr << endl;
    return 0;
}
