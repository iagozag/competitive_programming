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

void solve(){
    int n; cin >> n;
    vi v(n+4); rep(i, 0, n) cin >> v[i]; 

    vi dp(n+4, INF);
    dp[0] = 0;

    rep(i, 0, n){
        if(v[i] == 0) ckmin(dp[i+1], dp[i]);

        ckmin(dp[i+1], dp[i]+1);

        if(v[i] <= 2 and v[i+1] <= 2) ckmin(dp[i+2], dp[i]+1);

        if(v[i] <= 2){
            int j = 1, k = i+1;
            while(k < n and v[k] > 2 and v[k] <= 4) j++, k++;
            if(k < n and v[k] <= 2 and j%2) ckmin(dp[k+1], dp[i]+j);
            else ckmin(dp[k+1], dp[i]+j+1);
        }
    }

    int mi = INF;
    rep(i, n, n+4) ckmin(mi, dp[i]); 
    cout << mi << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
