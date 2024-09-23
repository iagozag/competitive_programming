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

vector<vi> pref;

void solve(){
    int n; cin >> n;
    map<int, pii> pos;
    vi v(n), need(5001); forr(x, v) cin >> x, need[x]++;


    pref = vector<vi>(n, vi(n, -INF));

    vi mp(5001); int sum = 0, sum_n = 0;
    rep(i, 1, n+1){
        int x = 0;
        rep(j, 0, i) {
            mp[v[j]]++, sum++;
            if(mp[v[j]] == 1) x ^= v[j], sum_n += need[v[j]];
        }
        if(sum == sum_n) pref[0][i-1] = x;

        rep(j, i, n){
            if(mp[v[j-i]] == 1) x ^= v[j-i], sum_n -= need[v[j-i]];
            mp[v[j-i]]--, sum--;

            mp[v[j]]++, sum++;
            if(mp[v[j]] == 1) x ^= v[j], sum_n += need[v[j]];
            if(sum_n == sum) pref[j-i+1][j] = x;
        }
        rep(j, n-i, n) mp[v[j]]--;
        sum = 0, sum_n = 0;
    }

    vector<vi> can(n);
    rep(i, 0, n) rep(j, 0, n) if(pref[i][j] >= 0) can[j].eb(i);

    vi dp(n);
    rep(i, 0, n){
        if(i) ckmax(dp[i], dp[i-1]);
        forr(x, can[i]) ckmax(dp[i], (x ? dp[x-1] : 0)+pref[x][i]);
    }

    cout << dp[n-1] << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
