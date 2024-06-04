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

void solve(){
    ll n, k, pb, ps; cin >> n >> k >> pb >> ps; --pb, --ps;
    vi p(n), v(n); forr(x, p) cin >> x, --x; forr(x, v) cin >> x;

    set<int> st; vl bo, sa; int l = 0;
    while(!st.count(pb) and l < k) bo.eb(v[pb]), st.insert(pb), pb = p[pb], l++;

    st.clear(); l = 0;
    while(!st.count(ps) and l < k) sa.eb(v[ps]), st.insert(ps), ps = p[ps], l++;

    int szb = sz(bo), szs = sz(sa);
    vl prefb(szb), prefs(szs);
    rep(i, 1, szb) prefb[i] = prefb[i-1]+bo[i-1];
    rep(i, 1, szs) prefs[i] = prefs[i-1]+sa[i-1];

    ll mab = 0, mas = 0;
    rep(i, 0, szb) mab = max(mab, prefb[i]+(k-i)*bo[i]);
    rep(i, 0, szs) mas = max(mas, prefs[i]+(k-i)*sa[i]);

    cout << (mab > mas ? "Bodya" : mas > mab ? "Sasha" : "Draw") << endl; 
}

int main(){ _
    int ttt; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
