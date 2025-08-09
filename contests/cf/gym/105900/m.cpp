#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
#define int ll

struct edge {
    int v;
    int d;
    int m;

    edge(int a,int b, int c): v(a),d(b),m(c) {}
    
    bool operator<(const edge &o) const {
        if(d<o.d) return true;
        if(d>o.d) return false;
        return m<o.m;
    }

    bool operator>(const edge o) const {
        if(d>o.d) return true;
        if(d<o.d) return false;
        return m>o.m;
    }

   bool operator==(const edge o) {
        if(d==o.d and m==o.m) return true;
        return false;
        return m<o.m;
    }
};

bool operator<(edge a,edge o) {
    if(a.d<o.d) return true;
    if(a.d>o.d) return false;
    return a.m<o.m;
}

int32_t main(){ _
    int n,m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++) {
            int a,b,c;
            cin >> a >> b >> c;
            adj[a-1].push_back(make_pair(b-1,c));
    }

    vector<int> dist(n,LLONG_MAX),mx(n,0);
    priority_queue<edge,vector<edge>,greater<edge>> pq;
    pq.push(edge(0,0,0));
    dist[0] = mx[0] = 0;

    while(pq.size()) {
        int v = pq.top().v;
        int d = pq.top().d;
        int md = pq.top().m;
        pq.pop();

        if(dist[v]<d) continue;

        for(auto [u,w]:adj[v]) {
            if(dist[v]+w<dist[u]) {
                dist[u] = dist[v]+w;
                mx[u] = max(w,md);
                pq.push(edge(u,dist[u],mx[u]));
            } else if(dist[v]+w==dist[u] and max(w,md)<mx[u]) {
                mx[u] = max(w,md);
                pq.push(edge(u,dist[u],mx[u]));
            }
        }
    }

    cout << dist.back() << ' ' << mx.back() << '\n';
}