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

const int MAX = 2e5+10, MOD = 1e8;

void sum(int& a, int b){
    a += b, a %= MOD;
}

void solve(){
    int n0, n1, k0, k1; cin >> n0 >> n1 >> k0 >> k1;

    int dp[n0+1][n1+1][2][11]; memset(dp, 0, sizeof dp);
    dp[1][0][0][1] = 1;
    dp[0][1][1][1] = 1;

    rep(i, 0, n0+1) rep(j, 0, n1+1) rep(k, 0, 2) rep(l, 0, (k == 0 ? k0+1 : k1+1)){
        if(k==0){
            if(l < k0 and i+1 <= n0) sum(dp[i+1][j][k][l+1], dp[i][j][k][l]);
            if(j+1 <= n1) sum(dp[i][j+1][1][1], dp[i][j][k][l]);
        } else{
            if(l < k1 and j+1 <= n1) sum(dp[i][j+1][k][l+1], dp[i][j][k][l]);
            if(i+1 <= n0) sum(dp[i+1][j][0][1], dp[i][j][k][l]);
        }

    }

    
    int ans = 0;
    rep(k, 0, 2) rep(l, 0, (k == 0 ? k0+1 : k1+1)) sum(ans, dp[n0][n1][k][l]);
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
