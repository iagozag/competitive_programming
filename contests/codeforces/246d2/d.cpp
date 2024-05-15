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
    string s; cin >> s; int n = sz(s);
    vi z(n);

    int l = 0, r = 0;
    rep(i, 1, n){
        if(i < r) z[i] = min(r-i, z[i-l]);
        while(i+z[i] < n and s[z[i]] == s[i+z[i]]) z[i]++;
        if(i+z[i] > r) l = i, r = i+z[i];
    }

    map<int, int> mp; mp[n] = 1;
    rep(i, 0, n) mp[z[i]]++;

    auto it = mp.end(); it--, it--; int prev = 1;
    for(; it != mp.begin(); it--){
        it->ss += prev, prev = it->ss; 
    }

    set<ii> ans; ans.insert({n, 1});
    repr(i, n-1, 0) if(i+z[i] == n) ans.insert({z[i], mp[z[i]]});

    cout << sz(ans) << endl;
    forr(x, ans) cout << x.ff << " " << x.ss << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
