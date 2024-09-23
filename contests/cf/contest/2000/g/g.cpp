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

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m; ll t0, t1, t2;
vector<vector<tuple<int, ll, ll>>> g;

int op(ll x){
    if(x < t1) return 0;
    else if(x >= t2) return 2;
    return 1;
}

bool good(ll x){
    vector<vl> dist(n, vl(3, LINF)); vector<vi> vis(n, vi(3));

    priority_queue<tuple<ll, int, int>> pq; pq.push({-x, 0, op(x)});
    dist[0][op(x)] = x;

    while(!pq.empty()){
        auto [w, v, opp] = pq.top(); w *= -1; pq.pop();
        if(v == n-1 and w <= t0){
            // rep(i, 0, n) rep(j, 0, 3) cout << i << " " << j << ": " << dist[i][j] << endl;
            // cout << endl;
            return true;
        }

        if(vis[v][opp]) continue;

        if(w < t2) dist[v][2] = t2, pq.push({-t2, v, 2});

        vis[v][opp] = 1;
        for(auto [ve, w1, w2]: g[v]){
            int newop1 = op(w+w1), newop2 = op(w+w2);
            if(((!opp and (!newop1 or w+w1==t1)) or opp == 2) and w+w1 < dist[ve][newop1])
                dist[ve][newop1] = w+w1, pq.push({-w-w1, ve, newop1}); 
            if(w+w2 < dist[ve][newop2]) dist[ve][newop2] = w+w2, pq.push({-w-w2, ve, newop2});
        }
    }

    return false;
}

void solve(){
    cin >> n >> m >> t0 >> t1 >> t2;
    g = vector<vector<tuple<int, ll, ll>>>(n);

    rep(i, 0, m){
        int u, v; ll l1, l2; cin >> u >> v >> l1 >> l2; --u, --v;
        g[u].eb(v, l1, l2), g[v].eb(u, l1, l2);
    }

    ll l = -1, r = t0-1, ans = -1;
    while(l <= r){
        ll mid = l+(r-l)/2;
        // cout << mid << endl;
        if(good(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
