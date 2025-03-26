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
    ll a, b, l; cin >> a >> b >> l;

    ll ans = 0; set<int> dd;

    int loga = 0, logb = 0, mult = 1;
    while(mult <= l) mult *= a, loga++;
    mult = 1;
    while(mult <= l) mult *= b, logb++;

    for(int i = 0; i < loga; i++)
        for(int j = 0; j < logb; j++){
            ll ma = 1, mb = 1;
            rep(k, 0, i) ma *= a;
            rep(k, 0, j) mb *= b;
            if(l%(ma*mb) == 0) if(!dd.count(l/(ma*mb))) ans++, dd.insert(l/(ma*mb));
        }

    cout << ans << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}
