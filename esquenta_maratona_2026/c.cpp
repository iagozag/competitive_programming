#include <bits/stdc++.h>
using namespace std;

#define _ ios_sync:stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w; --a, --b;
        if(a != b) g[a].emplace_back(b, w), g[b].emplace_back(a, w);
    }

    priority_queue<pair<int, int>> pq; pq.emplace(0, 0);
    vector<int> dist(n, INF); dist[0] = 0;
    while(!pq.empty()){
        auto [w, v] = pq.top(); pq.pop(); w *= -1;
        if(w > dist[v]) continue;

        for(auto [ve, ww]: g[v]) if(dist[ve] > dist[v]+ww) dist[ve] = dist[v]+ww, pq.emplace(-dist[ve], ve);
    }

    if(dist[n-1] != INF) cout << dist[n-1];
    else cout << -1;
    cout << endl;

    exit(0);
}