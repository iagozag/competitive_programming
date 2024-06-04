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

void solve(){
    int n; scanf("%d", &n); 
    vector<ii> a(n); vi maxx(n);
    rep(i, 0, n){ scanf("%d%d", &a[i].ff, &a[i].ss); maxx[i] = a[i].ss; }
    sort(all(a)), sort(all(maxx));

    ll ans = 0, len = n-1;
    rep(i, 0, n-1){
        int l = 0, r = len, idx;
        while(l <= r){
            int m = l+(r-l)/2;
            if(maxx[m] <= a[i].ss) idx = m, l = m+1;
            else r = m-1;
        }

        ans += idx, len--;
        maxx.erase(maxx.begin()+idx);
    }

    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
