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
    int n; ll sum = 0; cin >> n;
    vl v(n); forr(x, v) cin >> x, sum += x;
    vi vis(n+1);
    vl pref(n); pref[0] = 0, vis[v[0]] = 1;
    rep(i, 1, n){
        vis[v[i]]++;
        if(vis[v[i]] > 1 and v[i] > pref[i-1]) pref[i] = v[i];
        else pref[i] = pref[i-1];
    }

    ll prev = 0;
    rep(i, 0, n) prev += pref[i];
    sum += prev;

    rep(i, 1, n-1) if(pref[i] != pref[i-1] and pref[i] != pref[i+1]) 
        prev -= (pref[i]-pref[i-1]), pref[i] = pref[i-1];

    repr(i, n-1, 0) prev -= pref[i], sum += prev;

    cout << sum << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
