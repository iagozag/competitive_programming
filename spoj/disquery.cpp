#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vector<vector<pair<int, int>>> g;
vector<int> dist;
vector<pair<int, int>> par;

void dfs(int v, int p){
    for(auto [ve, w]: g[v]) if(ve != p) par[ve] = {v, w}, dist[ve] = dist[v]+1, dfs(ve, v);
}

void solve(){
    cin >> n; int k = 0;
    while((1<<k) <= n) k++;

    g = vector<vector<pair<int, int>>>(n);
    for(int i = 0; i < n-1; i++){
        int a, b, w; cin >> a >> b >> w; --a, --b;
        g[a].emplace_back(b, w), g[b].emplace_back(a, w);
    }

    dist = vector<int>(n), par = vector<pair<int, int>>(n);
    dfs(0, -1);

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, {0, INF, 0}));
    for(int i = 0; i < n; i++) dp[i][0] = {par[i].first, par[i].second, par[i].second}; 
    for(int j = 1; j < k; j++) for(int i = 0; i < n; i++){
        dp[i][j] = {dp[dp[i][j-1][0]][j-1][0], 
                    min(dp[i][j-1][1], dp[dp[i][j-1][0]][j-1][1]), 
                    max(dp[i][j-1][2], dp[dp[i][j-1][0]][j-1][2])};  
    }

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b; --a, --b;
        if(dist[a] > dist[b]) swap(a, b);

        int mi = INF, ma = 0, need = dist[b]-dist[a];
        for(int j = k-1; j >= 0; j--) if(need&(1<<j))
            mi = min(mi, dp[b][j][1]), ma = max(ma, dp[b][j][2]), b = dp[b][j][0];

        if(a == b){ cout << mi << " " << ma << endl; continue; }

        for(int j = k-1; j >= 0; j--) if(dp[a][j][0] != dp[b][j][0]){
            mi = min(mi, dp[a][j][1]), ma = max(ma, dp[a][j][2]), a = dp[a][j][0];
            mi = min(mi, dp[b][j][1]), ma = max(ma, dp[b][j][2]), b = dp[b][j][0];
        }
        
        mi = min(mi, dp[a][0][1]), ma = max(ma, dp[a][0][2]);
        mi = min(mi, dp[b][0][1]), ma = max(ma, dp[b][0][2]);

        cout << mi << " " <<  ma << endl;

    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
