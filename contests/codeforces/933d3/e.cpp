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

ll n, m, k, d;
ll grid[101][MAX];

ll dp(int i){
    vl memo(m); memo[0] = 1;
    multiset<ll> ms; ms.insert(1LL);

    int j = 0, r = 1;
    while(r < m and r <= d+1) memo[r] = grid[i][r]+2, ms.insert(memo[r]), r++;
    while(r < m){
        ms.erase(ms.find(memo[j])), j++;
        memo[r] = grid[i][r]+1+*ms.begin();
        ms.insert(memo[r]), r++;
    }
    return memo[m-1];
}

void solve(){
    cin >> n >> m >> k >> d;
    rep(i, 0, n) rep(j, 0, m) cin >> grid[i][j];

    vl dist(n);
    rep(i, 0, n) dist[i] = dp(i);

    ll sum = 0; int i = 0, j = 0;
    for(; j < k; j++) sum += dist[j];

    ll ans = sum;
    while(j < n){
        sum -= dist[i], sum += dist[j];
        ans = min(ans, sum), i++, j++;
    }

    cout << ans << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}
