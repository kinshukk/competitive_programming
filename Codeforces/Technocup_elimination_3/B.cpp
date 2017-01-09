#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    map<char, char> m;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]){
            if(m.find(a[i]) == m.end() && m.find(b[i]) == m.end()){
                m[a[i]] = b[i];
                m[b[i]] = a[i];
            }else{
                if(m.find(a[i]) != m.end() && m[a[i]] != b[i]){
                    cout << -1 << endl;
                    return 0;
                }else if(m.find(b[i]) != m.end() && m[b[i]] != a[i]){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    vector<pair<char, char> > ans;
    for(map<char, char>::iterator iter = m.begin();
        iter != m.end();
        iter++){
            if(find(ans.begin(), ans.end(), make_pair(iter->first, iter->second)) != ans.end() || find(ans.begin(), ans.end(), make_pair(iter->second, iter->first)) != ans.end()){
                continue;
            }else{
                ans.push_back(make_pair(iter->first, iter->second));
            }
        }

    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
