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

vl need(3), a(3), b(3);

bool check(ll x, ll k){
    vl tmp = need;
    for(auto& y: tmp) y *= x;

    for(int i = 0; i < 3; i++) tmp[i] -= a[i];
    for(int i = 0; i < 3; i++){
        if(tmp[i] <= 0) continue;

        k -= tmp[i]*b[i]; 
    }

    return k >= 0;
}

void solve(){
    string st; cin >> st;
    for(auto& x: st){
        if(x == 'B') need[0]++;
        else if(x == 'S') need[1]++;
        else need[2]++;
    }
    for(auto& x: a) cin >> x;
    for(auto& x: b) cin >> x;
    ll k; cin >> k;

    ll l = 0, r = 1e13, ans;
    while(l <= r){
        ll m = l+(r-l)/2;
        if(check(m, k)) ans = m, l = m+1;
        else r = m-1;
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

