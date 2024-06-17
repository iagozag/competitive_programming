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
void yes(int ans){ cout << ans << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<pii> v(n); map<string, int> mp; int c = 0;
    rep(i, 0, n){
        string s1, s2 ; cin >> s1 >> s2;
        if(mp.count(s1)) v[i].ff = mp[s1];
        else mp[s1] = c, v[i].ff = c++;
        if(mp.count(s2)) v[i].ss = mp[s2];
        else mp[s2] = c, v[i].ss = c++;
    }

    bool dp[1<<n][n]; memset(dp, 0, sizeof dp);
    rep(i, 0, n) dp[0][i] = 1;
    rep(i, 0, 1<<n){
        rep(j, 0, n) if(dp[i][j]){
            rep(k, 0, n) if(!(i&(1<<k))){
                if(i == 0 or v[j].ff == v[k].ff or v[j].ss == v[k].ss) 
                    dp[i|(1<<k)][k] = 1;
            }
        }
    }

    int mi = INF;
    rep(i, 0, 1<<n) rep(j, 0, n) if(dp[i][j]){
        mi = min(mi, (int)(n-bitset<16>(i).count()));
    }
    cout << mi << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
