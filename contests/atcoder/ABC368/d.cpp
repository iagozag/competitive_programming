#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
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

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

int n, k;
vector<vi> g;
set<int> s;
vi need;

int dfs(int v, int p){
    int ans = 0;
    if(s.count(v)) ans = 1;

    forr(ve, g[v]) if(ve != p) ans |= dfs(ve, v);
    return need[v] = ans;
}

void solve(){
    cin >> n >> k;
    g = vector<vi>(n), need = vi(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b; --a, --b;
        g[a].eb(b), g[b].eb(a);
    }

    rep(i, 0, k){ int a; cin >> a; --a, s.insert(a); }

    dfs(*s.begin(), -1);

    int ans = 0;
    rep(i, 0, n) if(need[i]) ans++;
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
