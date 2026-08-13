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

void solve(){
    int n, k; cin >> n >> k;
    vi v(n); forr(x, v) cin >> x, --x;

    vi dp(n, 1);
    rep(i, 0, n){
        if(v[i] == -1) dp[i] += min(i, k)+min(k, n-i-1);
        else{
            int distl = min(v[i]+k, n-1), distr = max(i-k, 0), intersec = 0;
            if(distl >= distr) intersec = distl-distr+1;

            dp[i] += dp[v[i]]+min(i, k)+min(k, n-i-1)-intersec;
        } 
    }

    rep(i, 0, n) cout << dp[i] << " \n"[i == n-1];
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
