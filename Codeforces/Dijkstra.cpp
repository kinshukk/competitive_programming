#include <stdio.h>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

const long mx = 1E6 + 10;
long long parents[mx];

void print_path(long long vertex){
    if(parents[vertex] == -1){
        printf("%lld ", vertex+1);
    }else{
        print_path(parents[vertex]);
        printf("%lld ", vertex+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("INPUT.in", "r", stdin);

    for(long long i=0; i<=mx; i++){
        parents[i] = LLONG_MAX;
    }

    long long v, e;
    scanf("%lld%lld", &v, &e);
    unsigned long long d[v];
    bool done[v];

    vector<pair<long, long> > G[v];
    long long f, s, wt;
    for(long long i=0; i<e; i++){
        scanf("%lld%lld%lld", &f, &s, &wt);
        --f; --s;
        G[f].push_back(make_pair(wt, s));
        G[s].push_back(make_pair(wt, f));
    }

    long long start = 0;

    parents[start] = -1;
    for(long long i=0; i<v; i++){
        d[i] = LLONG_MAX;
        done[i] = false;
    }
    d[start] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > Q;
    Q.push(make_pair(d[start], start));
    while(!Q.empty()){
        long long u = Q.top().second;
        long long cur_dist = Q.top().first;
        Q.pop();

        if(done[u]){
            continue;
        }else{
            done[u] = true;
        }

        for(long long i=0; i<G[u].size(); i++){
            long long v = G[u][i].second;
            long long dist_uv = G[u][i].first;
            if(cur_dist + dist_uv < d[v]){
                parents[v] = u;
                d[v] = cur_dist + dist_uv;
                if(!done[v]){
                    Q.push(make_pair(d[v], v));
                }
            }
        }
    }

    if(parents[v-1] == LLONG_MAX){
        printf("-1\n");
    }else{
        long long cur = v-1;
        print_path(cur);
        printf("\n");
    }

    return 0;
}
