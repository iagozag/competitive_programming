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

const int MAX = 2e4+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<vl> t(n, vl(3));
    rep(i, 0, n) cin >> t[i][1] >> t[i][0] >> t[i][2];
    sort(all(t));

    vi w(n), s(n); vl v(n);
    rep(i, 0, n) w[i] = t[i][1], s[i] = t[i][0], v[i] = t[i][2];

    ll dp[n][MAX]; fill(&dp[0][0], &dp[0][0]+n*MAX, 0);
    rep(i, w[0], MAX) dp[0][i] = v[0];
    rep(i, 0, n-1) rep(j, 0, MAX){
        ckmax(dp[i+1][j], dp[i][j]);
        if(s[i+1] >= j) ckmax(dp[i+1][j+w[i+1]], dp[i][j]+v[i+1]);
    }

    ll ma = 0;
    rep(i, 0, MAX) ckmax(ma, dp[n-1][i]);
    cout << ma << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
