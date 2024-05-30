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
void yes(int n){ cout << n << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    ll n, l = 1, ma = 0; cin >> n;
    vl v(n); map<ll, ll> mp; rep(i, 0, n) cin >> v[i], ma = max(ma, v[i]), mp[v[i]]++;
    rep(i, 0, n){
        l = lcm(l, v[i]);
        if(l > ma) return yes(n);
    }

    set<ll> div;
    rep(i, 1, sqrt(ma)+1) if(ma%i == 0) div.insert(i), div.insert(ma/i);

    ll ans = 0;
    forr(x, div){
        if(mp.count(x)) continue;
        ll cur = 0, cnt = 0;
        forr(y, mp){
            if(x%y.ff == 0){
                if(cur == 0) cur = y.ff;
                else cur = lcm(cur, y.ff);
                cnt += y.ss;
            }
        }
        if(cur == x) ans = max(ans, cnt);
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
