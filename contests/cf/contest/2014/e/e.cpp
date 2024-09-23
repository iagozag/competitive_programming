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

int n, m, h;
vector<vector<pair<int, ll>>> g;
vi ride;

void dijkstra(vector<vl>& d, int s){
    rep(i, 0, n) rep(j, 0, 2) d[i][j] = LINF; 
    d[s][0] = 0; vector<vi> vis(n, vi(2));

    priority_queue<tuple<ll, int, int>> q; q.push({0, s, 0});
    while(!q.empty()){
        auto [w, v, horse] = q.top(); w *= -1, q.pop();
        if(vis[v][horse]) continue;

        vis[v][horse] = 1;
        if(ride[v]) horse = 1;
        for(auto [ve, ww]: g[v]){
            if(horse) ww >>= 1;
            if(w+ww < d[ve][horse]) d[ve][horse] = w+ww, q.push({-d[ve][horse], ve, horse});
        }
    }
}

void solve(){
    cin >> n >> m >> h;
    g = vector<vector<pair<int, ll>>>(n);
    ride = vi(n); rep(i, 0, h){ int a; cin >> a; --a; ride[a] = 1; } 

    rep(i, 0, m){ int a, b; ll c; cin >> a >> b >> c; --a, --b, g[a].eb(b, c), g[b].eb(a, c); }

    vector<vl> dist1(n, vl(2)), dist2(n, vl(2));
    dijkstra(dist1, 0), dijkstra(dist2, n-1);

    ll ans = LINF;
    rep(i, 0, n) rep(j, 0, 4) ckmin(ans, max(dist1[i][j&1], dist2[i][(j&2) > 0]));

    cout << (ans < LINF ? ans : -1) << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
