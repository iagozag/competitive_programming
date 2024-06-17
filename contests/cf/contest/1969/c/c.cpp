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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

// dp[i][j] = min sum that i can do with the first i elements and done j operations;

void solve(){
    ll n, k; cin >> n >> k;
    vl v(n); forr(x, v) cin >> x;

    vector<vector<ll>> dp(n+1, vl(k+1, LINF)); 
    dp[0][0] = 0; 
    rep(i, 0, n) rep(j, 0, k+1){
        ll mi = INF;
        for(int d = 0; i+d < n and j+d <= k; d++){
            mi = min(mi, v[i+d]);
            dp[i+d+1][j+d] = min(dp[i+d+1][j+d], dp[i][j]+mi*(d+1));
        }
    }

    ll ans = LINF;
    rep(i, 0, k+1) ans = min(ans, dp[n][i]);
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
