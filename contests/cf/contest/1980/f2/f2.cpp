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

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<pii> v(k); map<pii, int> mp;
    rep(i, 0, k) cin >> v[i].ff >> v[i].ss, mp[v[i]] = i;
    sort(all(v), [](const pii& a, const pii& b){
        if(a.ss != b.ss) return a.ss < b.ss;
        return a.ff < b.ff;
    });

    int prev = v[0].ff; vi fount(k);
    fount[mp[v[0]]] = 1;
    rep(i, 1, k){
        if(v[i].ff <= prev) continue;
        if(v[i].ss == v[i-1].ss) fount[mp[v[i-1]]] = 0;
        fount[mp[v[i]]] = 1, prev = v[i].ff;
    }

    ll ans = 0, l = n, c = 1;
    rep(i, 0, k){
        if(!fount[mp[v[i]]]) continue;
        ans += l*(v[i].ss-c), l = n-v[i].ff, c = v[i].ss;
    }
    ans += l*(m-c+1);

    cout << ans << endl;
    forr(x, fount) cout << x << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
