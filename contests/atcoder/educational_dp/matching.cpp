#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;

    vector<vi> mat(n, vi(n));
    forr(x, mat) forr(y, x) cin >> y;

    vector<vi> dp(n, vi(1<<n));
    dp[0][(1<<n)-1] = 1; 

    queue<int> q; q.push((1<<n)-1);
    rep(i, 0, n-1){
        int m = sz(q);
        rep(j, 0, m){
            int v = q.front(); q.pop(); unordered_set<int> cnt; 
            rep(k, 0, n) if((1<<k)&v and mat[i][k]){
                dp[i+1][v-(1<<k)] += dp[i][v], dp[i+1][v-(1<<k)] %= MOD;
                if(!cnt.count(v-(1<<k))) q.push(v-(1<<k)), cnt.insert(v-(1<<k));
            }
        }
    }

    int ans = 0;
    rep(i, 0, 1<<n) ans += dp[n-1][i], ans %= MOD;
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
