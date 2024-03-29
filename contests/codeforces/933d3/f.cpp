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

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vi a(n), d(m), f(k); 
    forr(x, a) cin >> x; 
    forr(x, d) cin >> x; 
    forr(x, f) cin >> x;

    sort(all(d)), sort(all(f));

    vector<vi> dist(n-1, vi(3));
    rep(i, 1, n){
        dist[i-1][0] = a[i]-a[i-1], dist[i-1][1] = a[i-1], dist[i-1][2] = a[i];
    }
    sort(all(dist), [](const vi i, const vi j){
        return i[0] > j[0];
    });

    if(dist.size() > 1 and dist[0][0] == dist[1][0]){ cout << dist[0][0] << endl; return; }
    
    int ans = dist[0][0], mi = dist[0][1], ma = dist[0][2], bet = mi+(ma-mi)/2;
    rep(i, 0, m){
        if(d[i] >= ma) break;
        int need = bet-d[i];
        int ub = upper_bound(all(f), need)-f.begin();
        
        if(ub >= 1 and d[i]+f[ub-1] > mi) ans = min(ans, ma-(d[i]+f[ub-1]));
        if(ub < k and f[ub]+d[i] < ma) ans = min(ans, (f[ub]+d[i])-mi);
    } 

    if(dist.size() > 1) ans = max(ans, dist[1][0]);
    cout << ans << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}
