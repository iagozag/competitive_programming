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

const int MAX = 3001, MOD = 1e9+7;

int n;
vl v;
ll memo[MAX][MAX][2];

ll dp(int l, int r, int b){
    if(memo[l][r][b] != -1) return memo[l][r][b];

    if(l == r) return memo[l][r][b] = v[l]*(b ? -1 : 1);
    
    if(b) return memo[l][r][b] = min(dp(l+1, r, !b)-v[l], dp(l, r-1, !b)-v[r]);
    return memo[l][r][b] = max(dp(l+1, r, !b)+v[l], dp(l, r-1, !b)+v[r]);
}

void solve(){
    cin >> n;
    v = vl(n); forr(x, v) cin >> x;

    memset(memo, -1, sizeof memo);
    cout << dp(0, n-1, 0) << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
