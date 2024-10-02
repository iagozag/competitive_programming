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
    vector<vl> mat(n, vl(n));
    forr(x, mat) forr(y, x) cin >> y;

    vl sums(1<<n, -1); sums[0] = 0;
    rep(i, 0, 1<<n) rep(j, 0, n) if(!(i&(1<<j)) and sums[i|(1<<j)] == -1){
        sums[i|(1<<j)] = sums[i];
        rep(k, 0, n) if(i&(1<<k)) sums[i|(1<<j)] += mat[j][k];
    }

    vl dp(1<<n);
    rep(i, 0, 1<<n){
        rep(j, 0, i+1) if((i&j) == j) ckmax(dp[i], sums[j]+dp[i-j]);
    }

    cout << dp[(1<<n)-1] << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
