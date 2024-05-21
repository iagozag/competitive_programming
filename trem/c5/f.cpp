#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m, qnt;
vector<vi> g, g_t;
vi color;

void no(){ cout << string(n, '0') << endl; }
void yes(){ cout << "YES" << endl; }

bool dfs(int v) {
    color[v] = 1;
    for (int u : g[v]) {
        if (color[u] == 0 and dfs(u)) return true;
        else if (color[u] == 1) return true;
    }
    color[v] = 2;
    return false;
}

vi in, out;

int dp(int v){
    bool ok = false;
    forr(ve, g[v]) if(in[ve] == -1) in[v] += dp(ve), ok = true;
    if(!ok) in[v] = 1;
    return in[v];
}

int dp2(int v){
    bool ok = false;
    forr(ve, g_t[v]) if(out[ve] == -1) out[v] += dp2(ve), ok = true;
    if(!ok) out[v] = 1;
    return out[v];
}

void solve(){
    cin >> n >> m;
    g = g_t = vector<vi>(n), color = vi(n); bool cant = 0;
    rep(i, 0, m){
        int a, b; cin >> a >> b; --a, --b; if(a == b) cant = 1;
        g[a].eb(b), g_t[b].eb(a);
    }
    if(cant) return no();

    rep(i, 0, n) if(color[i] == 0 and dfs(i)) return no();

    in = out = vi(n, -1);
    vector<int> sourcesg, sourcesgt;
    rep(i, 0, n){
        if(g_t[i].size() == 0) sourcesg.eb(i), in[i] = 0;
        if(g[i].size() == 0) sourcesgt.eb(i), out[i] = 0;
    }

    rep(i, 0, sz(sourcesg)) in[i] = dp(i);
    rep(i, 0, sz(sourcesgt)) out[i] = dp2(i);

    // rep(i, 0, n) cout << in[i] << ", ";
    // cout << endl;
    // rep(i, 0, n) cout << out[i] << ", ";
    // cout << endl;

    string res = string(n, '0');
    rep(i, 0, n){
        if(in[i] == out[i]){ res[i] = '1'; break; }
    }
    
    cout << res << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
