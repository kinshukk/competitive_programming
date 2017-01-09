#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[(int)(2*(1E5) + 1)];
vector<int> arr1;
vector<int> arr2;

bool comparator(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    arr1.reserve(2 + (n/2));
    arr2.reserve(2 + (n/2));

    for(int i=0; i<n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr+n, comparator);

    unsigned long long s1=0, s2=0;
    int f, s, fi, si, ptr;
    ptr = 0;

    while(ptr+2 <= n){
        if(arr[ptr].first < arr[ptr+1].first){
            f = arr[ptr].first;
            fi = arr[ptr].second;
            s = arr[ptr+1].first;
            si = arr[ptr+1].second;
        }else{
            s = arr[ptr].first;
            si = arr[ptr].second;
            f = arr[ptr+1].first;
            fi = arr[ptr+1].second;
        }

        if(s1 < s2){
            s1 += s;
            s2 += f;
            arr1.push_back(si);
            arr2.push_back(fi);
        }else{
            s2 += s;
            s1 += f;
            arr2.push_back(si);
            arr1.push_back(fi);
        }
        ptr += 2;
    }

    if(ptr == n-1){
        if(s1 < s2){
            arr1.push_back(arr[ptr].second);
        }else{
            arr2.push_back(arr[ptr].second);
        }
    }

    cout << arr1.size() << "\n";
    for(int i=0; i<arr1.size(); i++){
        cout << arr1[i]+1 << " ";
    }
    cout << "\n";

    cout << arr2.size() << "\n";
    for(int i=0; i<arr2.size(); i++){
        cout << arr2[i]+1 << " ";
    }
    cout << endl;
    return 0;
}
