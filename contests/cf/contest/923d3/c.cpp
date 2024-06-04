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

const int MAX = 2e5+10;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    set<int> a, b;
    rep(i, 0, n){ int x; cin >> x; a.insert(x); }
    rep(i, 0, m){ int x; cin >> x; b.insert(x); }

    int ka = 0, kb = 0, kc = 0;
    rep(i, 1, k+1){
        if(a.count(i) and !b.count(i)){ 
            if(ka < k/2) ka++;
            else{ cout << "NO" << endl; return; }
        } else if(!a.count(i) and b.count(i)){ 
            if(kb < k/2) kb++;
            else{ cout << "NO" << endl; return; }
        } else if(a.count(i) and b.count(i)){
            kc++;
        } else{ cout << "NO" << endl; return; }
    }

    cout << (ka+kb+kc == k ? "YES" : "NO") << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
