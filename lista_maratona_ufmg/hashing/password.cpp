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

void no(){ cout << "Just a legend" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

vi z;
string s;
int n;

void z_function(){
    z = vi(n);

    int l = 0, r = 0;
    rep(i, 1, n){
        if(i < r) z[i] = min(z[i-l], r-i);
        while(i + z[i] < n and s[z[i]] == s[i+z[i]]) z[i]++;
        if(i+z[i] > r) l = i, r = i+z[i];
    }
}

void solve(){
    cin >> s; n = sz(s);
    if(n <= 2) return no();

    z_function();

    vi pref(n+1);
    rep(i, 1, n+1) pref[i] = max(pref[i-1], z[i-1]);

    int ma = -1;
    repr(i, n-1, 1) if(i+z[i] == n and pref[i] >= z[i])
        ma = max(ma, z[i]);

    if(ma == -1) return no();

    string ans = "";
    rep(i, 0, ma) ans += s[i];

    cout << ans << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
