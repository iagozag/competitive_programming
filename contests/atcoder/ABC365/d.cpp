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

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

// 0 - paper
// 1 - rock
// 2 - scissors

void solve(){
    int n; cin >> n;
    vi v(n);
    rep(i, 0, n){
        char c; cin >> c;
        if(c == 'P') v[i] = 0;
        else if(c == 'R') v[i] = 1;
        else v[i] = 2;
    }

    vector<vi> dp(n, vi(3, -INF));
    if(v[0] == 0) dp[0][0] = 0, dp[0][2] = 1;
    else if(v[0] == 1) dp[0][1] = 0, dp[0][0] = 1;
    else dp[0][2] = 0, dp[0][1] = 1;

    rep(i, 1, n){
        rep(j, 0, 3){
            if(j == v[i]) continue;
            ckmax(dp[i][v[i]], dp[i-1][j]);
        }
        int inv;
        if(v[i] == 0) inv = 2;
        else if(v[i] == 1) inv = 0;
        else inv = 1;

        rep(j, 0, 3){
            if(j == inv) continue;
            ckmax(dp[i][inv], dp[i-1][j]+1);
        }
    }

    int ma = -1;
    rep(i, 0, 3) ckmax(ma, dp[n-1][i]);
    cout << ma << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
