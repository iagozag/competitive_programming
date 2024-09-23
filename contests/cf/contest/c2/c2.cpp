#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
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

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(string ans){ cout << "YES" << endl << ans << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

vi z_f(string s){
    int n = sz(s);
    vi z(n);
    int l = 0, r = 0;
    rep(i, 1, n){
        if(i < r) z[i] = min(z[i-l], r-i);
        while(i+z[i] < n and s[z[i]] == s[i+z[i]]) z[i]++;
        if(i+z[i] > r) l = i, r = i+z[i];
    }

    return z;
}

void solve(){
    string s; cin >> s;
    int n = sz(s);

    vi z = z_f(s);

    rep(i, 1, (n%2 ? n/2+1 : n/2)){
        if(i+z[i] == n){
            string ans = "";
            rep(j, i, n) ans += s[j];
            return yes(ans);
        }
    }

    return no();
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
