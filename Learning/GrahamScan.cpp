#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<double, double>, double> > points;

bool comparator2(pair<pair<double, double>, double> a, pair<pair<double, double>, double> b){
    return a.second < b.second;
}

bool left_turn(pair<pair<double, double>, double> a, pair<pair<double, double>, double> b, pair<pair<double, double>, double> c){
    double x1 = b.first.first - a.first.first,
           y1 = b.first.second - a.first.second,
           x2 = c.first.first - b.first.first,
           y2 = c.first.second - b.first.second;

    // if determinant of [ (x1, x2), (y1, y2) ] > 0, left turn
    if( ( (x1 * y2) - (x2 * y1) ) > 0.0 ){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    pair<pair<double, double>, double> tmp;
    for(int i=0; i<n; i++){
        cin >> tmp.first.first >> tmp.first.second;
        points.push_back(tmp);
    }

    pair<pair<double, double>, double> p = points[0];
    int ind = 0;
    for(int i=1; i<n; i++){
        if(points[i].first.second < p.first.second){
            p = points[i];
            ind = i;
        }
    }

    swap(points[0], points[ind]);

    for(int i=1; i<n; i++){
        //atan2(y2 - y1, x2 - x1)
        points[i].second = atan2(points[i].first.second - points[0].first.second,
                                 points[i].first.first - points[0].first.first);
    }
    points[0].second = 0.0;

    sort(points.begin() + 1, points.end(), comparator2);

    stack < pair < pair < double, double >, double > > S;

    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for(int i=3; i<n; i++){
        //top
        pair<pair<double, double>, double> a = S.top();
        S.pop();
        //next to top
        pair<pair<double, double>, double> b = S.top();
        S.push(a);

        while( !left_turn(b, a, points[i]) ){
            S.pop();
            a = b;
            S.pop();
            b = S.top();
            S.push(a);
        }
        S.push(points[i]);
    }

    while(!S.empty()){
        cout << "x: " << S.top().first.first << ", y: " << S.top().first.second << endl;
        S.pop();
    }
    cout << endl;

    return 0;
}
