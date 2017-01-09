#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > segments, ranges;

bool comparator(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second > b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int m;
    segments.reserve(100000);
    cin >> m;
    int a, b;
    cin >> a >> b;

    while(a != 0 || b != 0){
        if(a > b)   swap(a, b);
        segments.push_back( make_pair(a, b) );
        cin >> a >> b;
    }

    sort(segments.begin(), segments.end(), comparator);

    int i = 0, ind = 0;
    pair<int, int> max_forward = segments[0];
    if(ind < max_forward.first){
        cout << "No solution\n";
        return 0;
    }

    while(ind < m){
        while(i < segments.size() && segments[i].first <= ind){
            if(segments[i].second > max_forward.second && segments[i].second > ind){
                max_forward = segments[i];
            }
            i++;
        }

        if(max_forward.second <= ind){
            cout << "No solution\n";
            return 0;
        }else{
            ind = max_forward.second;
            ranges.push_back(max_forward);
        }
    }

    cout << ranges.size() << endl;
    for(int i=0; i<ranges.size(); i++){
        cout << ranges[i].first << " " << ranges[i].second << "\n";
    }


    return 0;
}
