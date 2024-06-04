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

ll n, k;
vl v;

bool good(ll x){
    ll have = k;
    rep(i, 0, n){
        if(v[i] < x) have -= x-v[i];
        if(have < 0) return false;
    }
    return true;
}

void solve(){
    cin >> n >> k; v = vl(n);
    rep(i, 0, n) cin >> v[i];

    ll l = 0, r = 1e18+10, need = 0;
    while(l <= r){
        ll m = l+(r-l)/2;
        if(good(m)) need = m, l = m+1;
        else r = m-1;
    }


    rep(i, 0, n) if(v[i] < need) k -= (need-v[i]), v[i] = need;

    ll ma = 0, cnt = 0, tmp = k;
    rep(i, 0, n){
        if(v[i] > need) cnt++;
        else if(v[i] == need and tmp > 0) cnt++, tmp--;
    }
    ma = max(ma, cnt), cnt = 0, tmp = k;
    repr(i, n-1, 0){
        if(v[i] > need) cnt++;
        else if(v[i] == need and tmp > 0) cnt++, tmp--; 
    }
    ma = max(ma, cnt);

    cout << ma+(1+n*(need-1)) << endl;
}

int main(){ _
    int ttt; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
