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

ll fexp(ll n, ll k) {
    n %= MOD;
    ll ans = 1;
    while(k > 0){
        if(k&1) ans = ((ans%MOD)*(n%MOD))%MOD;
        n = ((n%MOD)*(n%MOD))%MOD;
        k>>=1;
    }

    return ans;
}

vi id, sz;

int find(int x){
    return id[x] = (id[x] == x ? x : find(id[x]));
}

void unio(int a, int b){
     a = find(a), b = find(b);
     if(a == b) return;

     if(sz[a] < sz[b]) swap(a, b);
     id[b] = a, sz[a] += sz[b];
}

void solve(){
    ll n, k; cin >> n >> k;

    vector<tuple<ll, ll, ll>> edges;
    rep(i, 0, n-1){
        ll a, b, c; cin >> a >> b >> c; --a, --b;
        edges.eb(a, b, c); 
    }

    ll ans = fexp(n, k);

    id = vi(n), sz = vi(n, 1); iota(all(id), 0);
    rep(i, 0, n-1){
        auto [a, b, w] = edges[i];
        if(w == 1) continue;

        unio(a, b);
    }

    set<int> st;
    rep(i, 0, n){
        if(!st.count(find(i))){
            st.insert(id[i]);
            ll exp = fexp(sz[id[i]], k);
            ans = (ans%MOD-exp%MOD+MOD)%MOD;
        }
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
