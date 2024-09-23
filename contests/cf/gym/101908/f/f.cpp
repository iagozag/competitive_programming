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
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (y > x) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 86401, MOD = 1e9+7;

struct st{
    int in, id, val;
    st(int in_, int id_, int val_): in(in_), id(id_), val(val_){}
};

void solve(){
    int n; cin >> n;
    vector<vector<st>> stand(MAX);

    rep(i, 0, n){
        int m; cin >> m;
        rep(j, 0, m){
            int a, b, c; cin >> a >> b >> c;
            stand[b].eb(a, i, c);
        }
    }

    vector<vi> dp(1<<n, vi(MAX, -INF));
    dp[0][0] = 0;

    rep(t, 1, MAX) per(i, (1<<n)-1, 0){
        dp[i][t] = dp[i][t-1];
        forr(s, stand[t]) if(i&(1<<s.id))
            ckmax(dp[i][t], max(dp[i][s.in], dp[i^(1<<s.id)][s.in])+s.val);
    }

    cout << (dp[(1<<n)-1][MAX-1] < 0 ? -1 : dp[(1<<n)-1][MAX-1]) << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
