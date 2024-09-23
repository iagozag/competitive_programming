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

void no(){ cout << "-1" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    ll n; cin >> n;
    vector<pair<ll, ll>> v(n); rep(i, 0, n) cin >> v[i].ff >> v[i].ss;

    ll mi = v[0].ff, ma = v[0].ss, idx = 0;
    rep(i, 1, n){
        if(v[i].ff < mi) mi = v[i].ff, ma = v[i].ss, idx = i;
        else if(v[i].ff == mi){
            mi = v[i].ff;
            if(ma < v[i].ss) ma = v[i].ss, idx = i;
        }
    }

    rep(i, 0, n) if(v[i].ff < mi or v[i].ss > ma) return no();
    cout << idx+1 << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
