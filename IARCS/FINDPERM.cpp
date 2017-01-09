#include <iostream>
#include <list>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    list<int> L;
    int n;
    cin >> n;
    int arr[n], outp[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
        L.push_back(i);
    }

    int inv = 0, final_index = 0;
    for(int i=n-1; i>=0; i--){
        inv = arr[i];
        final_index = *(L.end()-inv);
        L.remove(L.end()-inv);
        arr[final_index] = i;
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
