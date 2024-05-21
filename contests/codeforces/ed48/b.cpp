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

int n, m, q;
string s, s1;
vi z;

void z_function(){
    z = vi(n);
    int l = 0, r = 0;
    rep(i, 1, n){
        if(i < r) z[i] = min(r-i, z[i-l]);
        while(i+z[i] < n and s[z[i]] == s[i+z[i]]) z[i]++;
        if(i+z[i] > r) l = i, r = i+z[i];
    }
}

void solve(){
    cin >> n >> m >> q >> s >> s1;
    s = s1+'$'+s; n = sz(s);
    z_function();

    vector<int> v;
    rep(i, m+1, n) if(z[i] == m) v.eb(i-m-1);

    rep(i, 0, q){
        int a, b; cin >> a >> b; --a, --b;
        int lb = lower_bound(all(v), a)-v.begin();
        int rb = lower_bound(all(v), b-m+1)-v.begin();

        if(rb == sz(v) or v[rb] > b-m+1) rb--;
        if(rb >= lb) cout << rb-lb+1 << endl;
        else cout << 0 << endl;
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
