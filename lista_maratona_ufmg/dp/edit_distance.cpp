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

const int MAX = 3000, MOD = 1e9+7;

int dp[MAX][MAX];

void solve(){
    string a, b; cin >> a >> b;
    int n = sz(a), m = sz(b);

    memset(dp, INF, sizeof dp); dp[0][0] = 0;
    
    rep(i, 0, n+1) dp[i][0] = i;
    rep(i, 0, m+1) dp[0][i] = i;
    rep(i, 1, n+1) rep(j, 1, m+1)
        ckmin(dp[i][j], min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+(a[i-1] != b[j-1])}));

    cout << dp[n][m] << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
