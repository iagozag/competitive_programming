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
    vector<string> v(n); forr(x, v) cin >> x;
    sort(all(v));

    ll ans = 0;
    map<string, ll> mp;
    rep(i, 0, n){
        string s = "";
        rep(j, 0, sz(v[i])){
            s += v[i][j];
            if(mp[s] == 1 and sz(s) == 1) ans += 2;
            else if(mp[s] > 1) ans++;
            mp[s]++;
        }
    }

    cout << mp.size() << endl;
    forr(x, mp) cout << x.ff << " " << x.ss << endl;
    
    cout << ans << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
