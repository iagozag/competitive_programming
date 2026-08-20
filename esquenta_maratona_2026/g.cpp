#include <bits/stdc++.h>
using namespace std;

#define _ ios_sync:stdio(0);cin.tie(0);
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f3f3f3f3fll;

int n;
vector<int> child, dp1, dp2;
vector<vector<pair<int, int>>> g;

void dfs(int v, int p){
    child[v] = 1;

    for(auto [ve, w]: g[v]) if(ve != p){
        dfs(ve, v);
        child[v] += child[ve];
        dp1[v] += dp1[ve]+w*child[ve];
    }
}

void dfs2(int v, int p){
    for(auto [ve, w]: g[v]) if(ve != p){
        dp2[ve] += (dp1[v] - dp1[ve] - w*child[ve]) + dp2[v];
        dp2[ve] += (n - child[ve])*w;
        dfs2(ve, v);
    }
}

int32_t main(){
    cin >> n;
    child = dp1 = dp2 = vector<int>(n);
    g = vector<vector<pair<int, int>>>(n);

    for(int i = 0; i < n-1; i++){
        int a, b, w; cin >> a >> b >> w; --a, --b;
        g[a].emplace_back(b, w), g[b].emplace_back(a, w);
    }

    dfs(0, -1);
    dfs2(0, -1);

    // for(int i = 0; i < n; i++) cout << dp1[i] << ' ';
    // cout << endl;
    // for(int i = 0; i < n; i++) cout << dp2[i] << ' ';
    // cout << endl;
    // for(int i = 0; i < n; i++) cout << child[i] << ' ';
    // cout << endl;


    int ans = INF;
    for(int i = 0; i < n; i++) ans = min(ans, dp1[i] + dp2[i]);
    cout << ans << endl;
}