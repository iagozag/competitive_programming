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

const int MAX = 2e5+10, MOD = 998244353;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int m = sz(s), sum = 0;

    vector<vl> pre(n+1, vl(n+1)), suf(n+1, vl(n+1));
    pre[1][0] = 0, pre[1][1] = 1;
    rep(i, 1, n) rep(j, 0, n) pre[i][j] += pre[i-1][j-1], pre[i][j] %= MOD;
    rep(i, 1, n) rep(j, 0, n) pre[i][j] += pre[i-1][j+1], pre[i][j] %= MOD;

    suf[1][1] = 1;
    rep(i, 1, n) rep(j, 0, n) suf[i][j] += suf[i-1][j-1], suf[i][j] %= MOD;
    rep(i, 1, n) rep(j, 0, n) suf[i][j] += suf[i-1][j+1], suf[i][j] %= MOD;

    rep(i, 0, m) sum += s[i] == '(' ? 1 : -1;

    ll ans = 0;
    rep(i, 0, n-m) rep()
        ans += (pre[i][s]%MOD)*(suf[n-m-s][-s+sum]%MOD), ans %= MOD;

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
