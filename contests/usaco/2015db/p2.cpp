#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repr(i,n,x) for(int i=n;i>=x;i--)
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
    int n, m; cin >> n >> m;
    vector<ii> r(n), b(m); forr(x, r) cin >> x.ff >> x.ss; forr(x, b) cin >> x.ff >> x.ss;
    rep(i, 1, n) r[i].ff += r[i-1].ff;
    rep(i, 1, m) b[i].ff += b[i-1].ff;

    vi road(101), bessie(101);
    int cnt = 0;
    rep(i, 1, 101){
        if(i <= r[cnt].ff) road[i] = r[cnt].ss;
        else cnt++, i--;
    }

    cnt = 0;
    rep(i, 1, 101){
        if(i <= b[cnt].ff) bessie[i] = b[cnt].ss;
        else cnt++, i--;
    }

    int ans = 0;
    rep(i, 1, 101) ans = max(ans, bessie[i]-road[i]);
    cout << ans << endl;
}

int main(){ _
    if (fopen("speeding.in", "r")) {
		freopen("speeding.in", "r", stdin);
		freopen("speeding.out", "w", stdout);
	}

    int t = 1;

    while(t--) solve();

    exit(0);
}


