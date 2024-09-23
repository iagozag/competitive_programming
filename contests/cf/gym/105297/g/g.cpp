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

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vl v;
vector<vl> memo;

ll dp(int i, int j){
    if(i == n-1) return memo[i][j] = 0;
    if(memo[i][j] != LINF) return memo[i][j];

    return memo[i][j] = min(dp(i+1, j)+abs(v[i+1]-v[i]), dp(i+1, i)+abs(v[i+1]-v[j])); 
}

void solve(){
    cin >> n; n++;
    v = vl(n); rep(i, 1, n) cin >> v[i];

    memo = vector<vl>(n, vl(n, LINF));
    dp(0, 0); 
    
    ll ans = LINF;
    rep(i, 0, n) ckmin(ans, memo[0][0]);
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
