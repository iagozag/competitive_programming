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

int n, m, t;
vector<vector<tuple<int, ll, ll>>> g;
vl dist;
vector<bool> vis;

void dijkstra(){
    priority_queue<pair<ll, int>> pq;
    pq.push({-t, 0}), dist[0] = t;
    while(!pq.empty()){
        auto [w, v] = pq.top(); pq.pop(), w *= -1; 
        if(vis[v]) continue;
        vis[v] = 1;
        for(auto [ve, t1, t2]: g[v]){
            if((w%(t1+t2)) < t1 and dist[ve] > w) dist[ve] = w, pq.push({-w, ve});
            else if((w%(t1+t2)) >= t1 and dist[ve] > w+(t1+t2)-(w%(t1+t2)))
                dist[ve] = w+(t1+t2)-(w%(t1+t2)), pq.push({-dist[ve], ve});
        }
    }
}

void solve(){
    cin >> n >> m >> t;
    g.resize(n), dist = vl(n, LINF), vis.resize(n);
    rep(i, 0, m){
        int a, b; ll c, d; cin >> a >> b >> c >> d; --a, --b;
        g[a].eb(b, c, d), g[b].eb(a, c, d); 
    }

    dijkstra();
    cout << dist[n-1] << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
