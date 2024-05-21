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

ll calc(vector<tuple<int, int, int>> t){
    ll sum = 0, n = sz(t);
    rep(i, 0, n){
        auto [a, b, c] = t[i];
        tuple<int, int, int> bg = {a, b, c+1}, ed = {a, b, INF};
        int lb = lower_bound(t.begin()+i+1, t.end(), bg)-t.begin();
        int ub = upper_bound(t.begin()+i+1, t.end(), ed)-t.begin();

        if(ub >= lb) sum += ub-lb;
    }

    return sum;
}

void solve(){
    int n; cin >> n;
    vi v(n); forr(x, v) cin >> x;
    vector<tuple<int, int, int>> t; 
    rep(i, 2, n) t.eb(v[i-2], v[i-1], v[i]);
    sort(all(t));

    ll ans = calc(t);
    rep(i, 0, sz(t)){
        auto [a, b, c] = t[i];
        t[i] = {c, a, b};
    }
    sort(all(t));

    ans += calc(t);
    rep(i, 0, sz(t)){
        auto [a, b, c] = t[i];
        t[i] = {c, a, b};
    }
    sort(all(t));
    ans += calc(t);

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
