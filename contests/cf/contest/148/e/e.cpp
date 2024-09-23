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

const int MAX = 1e4+1, MOD = 1e9+7;

void solve(){
    int n, m; cin >> n >> m;
    vector<vi> best(n);
    rep(i, 0, n){
        int s; cin >> s;
        vi v(s); forr(x, v) cin >> x;

        best[i].resize(s+1);
        rep(j, 1, s+1){
            int sum = 0;
            rep(l, 0, j) sum += v[l], best[i][j] += v[l];
            int l = j-1, r = s-1;
            while(l >= 0)
                sum -= v[l--], sum += v[r--], ckmax(best[i][j], sum);
        }
    }

    int dp[n][MAX]; memset(dp, -INF, sizeof dp);
    rep(i, 0, sz(best[0])) dp[0][i] = best[0][i];
    rep(i, 1, n) rep(j, 0, sz(best[i])) rep(k, 0, m+1) 
        if(k+j <= m) ckmax(dp[i][k+j], dp[i-1][k]+best[i][j]);

    cout << dp[n-1][m] << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
