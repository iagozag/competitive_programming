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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void DBG() {
    cerr << "]" << endl;
}

void DBGC() {
    cerr << "]" << endl;
}

template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t)) cerr << ", ";
    DBG(t...);
}

template<class H, class... T> void DBGC(H h, T... t) {
    for(auto& x: h) cerr << x << " ";
    if(sizeof...(t)) cerr << "], [ ";
    DBGC(t...);
}

#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

vector<vector<pair<ll, ll>>> g(MAX);
vector<pair<ll, int>> dist(MAX, {INF, 0});
vi par(MAX);
vector<bool> vis(MAX);

void dijkstra(){
    dist[0] = {0, 1}, par[0] = -1;
    priority_queue<pair<ll, ll>> pq; pq.push({0, 0});
    while(!pq.empty()){
        auto [w, v] = pq.top(); pq.pop(); w *= -1;

        if(vis[v]) continue;
        
        vis[v] = 1;
        for(auto [ww, ve]: g[v]){
            if(w+ww < dist[ve].ff or (w+ww == dist[ve].ff and dist[v].ss+1 > dist[ve].ss))
                dist[ve].ff = w+ww, dist[ve].ss = dist[v].ss+1, pq.push({-dist[ve].ff, ve}), par[ve] = v;
        }
    }
}

void solve(){
    ll n, m, k; cin >> n >> m >> k;

    rep(i, 0, m){
        int a, b; ll c; cin >> a >> b >> c; --a, --b;
        g[a].eb(b, c);
    }

    dijkstra();

    int v = 0;
    rep(i, 1, n){
        if(dist[i].ff > k) continue;
        if(dist[i].ss > dist[v].ss) v = i;
    }

    vi ans;
    while(true){
        ans.eb(v); if(par[v] == -1) break; v = par[v]; 
    }
    reverse(all(ans));

    cout << ans.size() << endl; n = ans.size();
    rep(i, 0, n) cout << ans[i]+1 << " \n"[i == n-1];
    cout << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
