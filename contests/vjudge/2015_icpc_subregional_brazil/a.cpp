#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

const int LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
    int n, m; 
    while(cin >> n >> m){
        vector<vector<pair<int, int>>> g(n);
        for(int i = 0; i < m; i++){ 
            int a, b, c; cin >> a >> b >> c; --a, --b; 
            g[a].emplace_back(b, c), g[b].emplace_back(a, c);
        }

        vector<vector<int>> dist(n, vector<int>(2, LINF)); dist[0][0] = 0;
        priority_queue<tuple<int, int, int>> q; q.emplace(0, 0, 0);
        while(!q.empty()){
            auto [w, v, p] = q.top(); q.pop(); w *= -1;
            if(dist[v][p] < w) continue;

            for(auto [ve, ww]: g[v]) if(w+ww < dist[ve][p^1])
                dist[ve][p^1] = w+ww, q.emplace(-dist[ve][p^1], ve, p^1);
        }

        cout << (dist[n-1][0] == LINF ? -1 : dist[n-1][0]) << endl;
    }

    exit(0);
}