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

void no(){ cout << "-1" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vector<vi> g;
vi qnt, vis;

int dfs(int v){
    vis[v] = 1, qnt[v] = 1;
    forr(ve, g[v]) if(!vis[ve]) qnt[v] += dfs(ve);
    return qnt[v];
}

void solve(){
    cin >> n;
    g = vector<vi>(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b; --a, --b;
        g[a].eb(b), g[b].eb(a);
    }

    if(n&1) return no();

    vis = qnt = vi(n);
    dfs(0);

    ll ans = -1;
    forr(x, qnt) if(x%2 == 0) ans++;

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
