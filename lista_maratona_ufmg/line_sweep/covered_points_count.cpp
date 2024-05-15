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

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<pair<ll, bool>> v;
    rep(i, 0, n){ ll a, b; cin >> a >> b; v.eb(a, 0), v.eb(b, 1); }
    sort(all(v));

    ll prev = 0, cnt = 0; vl ans(n+1); n = sz(v);
    rep(i, 0, n){
        auto [val, type] = v[i];

        if(type == 0){
            ans[cnt] += max(val-prev-1, 0LL), prev = val;
            cnt++;
            while(v[i+1].ff == val and v[i+1].ss == 0) i++, cnt++;
            ans[cnt]++;
        } else{
            ans[cnt] += max(val-prev, 0LL), prev = val; 
            cnt--;
        }
    }

    rep(i, 1, sz(ans)) cout << ans[i] << " \n"[i == sz(ans)-1]; 
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
