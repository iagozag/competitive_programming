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
    int n, m; cin >> n >> m;
    vector<string> v(n); forr(x, v) cin >> x;

    vector<string> ans1, ans2; string mid = "";
    vector<bool> vis(n);
    rep(i, 0, n){
        if(vis[i]) continue;
        string r = v[i]; reverse(all(r));
        if(v[i] == r and r.size() > mid.size()){ mid = v[i]; continue; }

        rep(j, 0, n){
            if(i == j or vis[j]) continue;
            if(v[j] == r) vis[j] = 1, ans1.eb(v[i]), ans2.eb(v[j]);
        }
    }

    string ans = "";
    forr(x, ans1) ans += x;
    ans += mid;
    reverse(all(ans2));
    forr(x, ans2) ans += x;
    cout << ans.size() << endl << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
