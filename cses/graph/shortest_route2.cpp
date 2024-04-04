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

#ifndef _DEBUG
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 
#else
#define dbg(...) 0
#define dbgc(...) 0
#endif

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<vl> memo(n, vl(n, LINF)); 
    rep(i, 0, n) memo[i][i] = 0;
    rep(i, 0, m){
        ll a, b, w; cin >> a >> b >> w; --a, --b;
        memo[a][b] = min(memo[a][b], w), memo[b][a] = min(memo[b][a], w);
    }

    rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) memo[i][j] = min(memo[i][j], memo[i][k]+memo[k][j]);

    rep(i, 0, q){
        int a, b; cin >> a >> b; --a, --b;
        cout << (memo[a][b] != LINF ? memo[a][b] : -1) << endl;
    }
    
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
