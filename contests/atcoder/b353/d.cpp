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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const ll MAX = 2e5+10, MOD = 998244353;

void solve(){
    ll n; cin >> n;
    vl v(n); forr(x, v) cin >> x;

    map<ll, ll> mp;
    rep(i, 0, n){
        string s = to_string(v[i]);
        mp[sz(s)]++;
    }

    ll ans = 0;
    rep(i, 0, n){
        string s = to_string(v[i]);
        mp[sz(s)]--;
        if(mp[sz(s)] == 0) mp.erase(sz(s));

        ans += ((i%MOD)*(v[i]%MOD))%MOD;
        ans %= MOD;

        forr(x, mp){
            ll pot = pow(10, x.ff);
            pot %= MOD;

            ans += ((((v[i]%MOD)*pot)%MOD)*x.ss)%MOD;
            ans %= MOD;
        }
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
