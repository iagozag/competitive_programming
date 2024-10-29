#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> par, dist;

int dfs(int v){
    if(dist[v] != -1) return dist[v];
    dist[v] = dfs(par[v])+1;
    return dist[v];
}

void solve(){
    int n; cin >> n; int k = 0;
    while((1<<k) <= n) k++;
    par = vector<int>(n); dist = vector<int>(n, -1);
    for(int i = 0; i < n; i++){
        int m; cin >> m; for(int j = 0; j < m; j++){ int a; cin >> a; --a, par[a] = i; }
    }

    vector<vector<int>> dp(n, vector<int>(k));
    for(int i = 0; i < n; i++) dp[i][0] = par[i];
    for(int i = 1; i < k; i++) for(int v = 0; v < n; v++) dp[v][i] = dp[dp[v][i-1]][i-1];

    dist[0] = 0;
    for(int i = 0; i < n; i++) dfs(i);

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b; --a, --b;
        if(dist[a] > dist[b]) swap(a, b);

        int need = dist[b]-dist[a];
        for(int j = k-1; j >= 0; j--) if(need&(1<<j)) b = dp[b][j];

        if(a == b){ cout << a+1 << endl; continue; }

        for(int j = k-1; j >= 0; j--) 
            if(dp[a][j] != dp[b][j]) a = dp[a][j], b = dp[b][j];

        cout << par[a]+1 << endl;
    }
}

int main(){ _
    int ttt = 1; cin >> ttt;

    for(int i = 1; i <= ttt; i++){ cout << "Case " << i << ":" << endl; solve(); }

    exit(0);
}
