#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repr(i,n,x) for(int i=n;i>=x;i--)
#define forr(v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ff first
#define ss second
#define pb push_back

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

const int MAX = 1e5+10;

int n, m, d;
vector<vi> g(MAX);
vi dist(MAX), par(MAX);
map<ii, int> mp;

vi make_path(int s){
    vi ans;
    while(par[s] != s) ans.pb(s), s = par[s];
    ans.pb(0);

    reverse(all(ans));
    return ans;
}

bool bfs(int x){
    dist[0] = 0;

    int v;
    queue<int> q; q.push(0);
    while(!q.empty()){
        v = q.front(); q.pop();

        for(auto ve: g[v]){
            if(mp[{v, ve}] > x) continue;

            dist[ve] = dist[v]+1, par[ve] = v;
            if(dist[ve] <= d){
                if(ve == n-1) return 1;
                q.push(ve);
            }
        }
    }

    return 0;
}

void solve(){
    int ma = -1, mi = INF; cin >> n >> m >> d;
    rep(i, 0, m){
        int a, b, x; cin >> a >> b >> x; a--, b--;
        g[a].pb(b), mp[{a, b}] = x, ma = max(ma, x), mi = min(mi, x);
    }

    int l = mi, r = ma; vi ans = {-1};
    while(l <= r){
        int m = l+(r-l)/2;
        if(bfs(m)) r = m-1, ans = make_path(n-1);
        else l = m+1;
    }

    if(ans[0] != -1){
        cout << ans.size()-1 << endl;
        forr(ans) cout << x+1 << " ";
    } else cout << -1;
    cout << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
