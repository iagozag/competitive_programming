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

vl v, pref;
vector<vl> memo;

ll dp(int l, int r){
    if(memo[l][r] != LINF) return memo[l][r];

    if(l == r) return memo[l][r] = 0;

    ll sum = v[r];
    per(j, r-1, l) ckmin(memo[l][r], dp(l, j)+(pref[j]-(l ? pref[l-1] : 0))+dp(j+1, r)+sum), sum += v[j];
    return memo[l][r];
}

void solve(){
    int n; cin >> n;
    v = pref = vl(n); forr(x, v) cin >> x;
    pref[0] = v[0]; rep(i, 1, n) pref[i] = pref[i-1]+v[i];

    memo = vector<vl>(n, vl(n, LINF));
    cout << dp(0, n-1) << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
