#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define f first
#define s second
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

int n, c, t;
vl v;

bool check(ll x){
    ll cc = 1, pops = t*x;
    for(int i = 0; i < n; i++){
        if(pops >= v[i]){ pops -= v[i]; continue; }

        cc++, pops = t*x, i--;
        if(cc > c) return false;
    }

    return true;
}

void solve(){
    cin >> n >> c >> t; ll ma = -1;
    v = vl(n); for(auto& x: v){ cin >> x; ma = max(ma, x); }

    ll l = (ma+t-1)/t, r = 1e9+10, ans;
    while(l <= r){
        ll m = l+(r-l)/2;
        if(check(m)) ans = m, r = m-1;
        else l = m+1;
    }

    cout << ans << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

