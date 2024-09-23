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

void solve(){
    int n, h, w; cin >> h >> w >> n;

    vector<pii> edges; edges.eb(1, 1), edges.eb(h, w);
    rep(i, 0, n){
        int a, b; cin >> a >> b;
        edges.eb(a, b);
    }
    sort(all(edges));

    vi dp(n+3, INF), id(n+3, -1), par(n+3, -1); dp[0] = -INF;
    rep(i, 0, n+2){
        int ub = upper_bound(all(dp), edges[i].ss)-dp.begin();
        dp[ub] = edges[i].ss, id[ub] = i, par[i] = id[ub-1];
    }

    int ma = n+2;
    rep(i, 0, n+3) if(dp[i] == INF){ ma = i-1; break; }

    string ans = ""; int now = id[ma];
    while(par[now] != -1){
        auto [a, b] = edges[now];
        auto [c, d] = edges[par[now]];
        ans += string(a-c, 'D')+string(b-d, 'R');
        now = par[now]; 
    }

    reverse(all(ans));
    cout << ma-2 << endl << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
