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

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10;

int n, k, res;
vector<vi> g;

int dfs(int v, int p, int x){
    int sz = 1;
    forr(ve, g[v]){
        if(ve == p) continue;
        sz += dfs(ve, v, x);
    }

    if(sz >= x) res++, sz = 0;
    return sz;
}

bool check(int m){
    res = 0;
    int t = dfs(0, -1, m);
    return res > k or (res == k and t >= m);
}

void solve(){
    cin >> n >> k; g = vector<vi>(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b; --a, --b;
        g[a].eb(b), g[b].eb(a);
    }
    
    int l = 1, r = n/(k+1)+1, ans;
    while(l <= r){
        int m = l+(r-l)/2;
        if(check(m)) ans = m, l = m+1;
        else r = m-1;
    }

    cout << ans << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}
