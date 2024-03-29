#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
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

#ifndef _DEBUG
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 
#else
#define dbg(...) 0
#define dbgc(...) 0
#endif

const int MAX = 2e5+10;

int n, m, x;
vector<vector<ii>> g(MAX);
vector<ll> dist;

void dijkstra(int s){
    dist = vl(n, LINF);
    priority_queue<ii> pq; pq.push({0, s});
    while(!pq.empty()){
        auto [w, v] = pq.top(); w -= 2*w; pq.pop();
        if(w >= dist[v]) continue;
        dist[v] = w;
        forr(ve, g[v]) if(ve.ss+w < dist[ve.ff]) pq.push({-ve.ss-w, ve.ff});
    }
}

void solve(){
    cin >> n >> m >> x;
    rep(i, 0, m){ 
        int a, b, w; cin >> a >> b >> w; --a, --b;
        g[a].eb(b, w), g[b].eb(a, w);
    }

    dijkstra(0);

    vector<pair<int,ll>> f(x);
    forr(y, f) cin >> y.ff, --y.ff, y.ss = dist[y.ff];

    dijkstra(n-1);

    ll ans = LINF;
    forr(y, f){ ans = min(ans, y.ss+dist[y.ff]); }

    cout << ans << endl;
}

int main(){ _
    int t = 1;

    while(t--) solve();

    exit(0);
}
