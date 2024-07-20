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
    ll n; cin >> n; string sn = to_string(n), s = "";

    if(n == 1){
        cout << 9999 << endl; 
        rep(i, 1, 10000) cout << i+1 << " " << i << endl;
        return;
    }

    int cnt = 0, ptr = 0;
    vector<pii> ans;
    rep(i, 0, 18){
        s += sn[ptr++]; if(ptr == sz(sn)) ptr = 0;
        ll num = stoll(s);
        if((num-sz(s)) % (n-sz(sn)) != 0) continue;
        ll x = (num-sz(s))/(n-sz(sn));
        ll y = n*x-num;
        if(x < 1 or x > 1e4 or y < 1 or y > min(1LL*10000, x*n)) continue;
        if(n*x-y == num) cnt++, ans.eb(x, y);
    }

    cout << cnt << endl;
    forr(x, ans) cout << x.ff << " " << x.ss << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

