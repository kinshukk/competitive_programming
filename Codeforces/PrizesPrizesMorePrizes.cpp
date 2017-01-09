#include <bits/stdc++.h>
using namespace std;

struct item{
    int index;
    long value;
    long long count;
};

bool comparator1(item a, item b){
    return a.value > b.value;
}

bool comparator2(item a, item b){
    return a.index < b.index;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    long arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    item items[5];
    for(int i=0; i<5; i++){
        items[i].index = i+1;
        cin >> items[i].value;
        items[i].count = 0;
    }

    sort(items, items+5, comparator1);

    long long sum = 0, lel = 0;

    for(int i=0; i<n; i++){
        sum += arr[i];
        for(int j=0; j<5; j++){
            lel = sum/items[j].value;
            sum %= items[j].value;
            items[j].count += lel;
        }
    }

    sort(items, items+5, comparator2);

    for(int i=0; i<5; i++){
        cout << items[i].count << " ";
    }

    cout << "\n" << sum << endl;
    return 0;
}
