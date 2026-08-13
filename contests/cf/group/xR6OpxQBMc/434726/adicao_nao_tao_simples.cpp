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

string dectobin(ll a){
    string ans = "";
    while(a) ans += (a&1 ? '1' : '0'), a /= 2;
    return ans;
}

ll bintodec(string a){
    reverse(all(a));
    ll ans = 0, pot = 1;
    rep(i, 0, sz(a)){
        if(a[i] == '1') ans += pot;
        pot *= 2;
    }

    return ans;
}

void solve(){
    ll aa, bb; cin >> aa >> bb;
    string a = dectobin(aa), b = dectobin(bb);
    string x, y; x = y;
    rep(i, 0, sz(b)){
        if(b[i] == '1') x += '0', y += '1';
        else x += '0', y += '0';
    }
    string cur_sum = y;

    cout << "a, b: " << a << " " << b << endl;
    cout << "x, y: " << x << " " << y << endl;

    rep(i, 0, sz(a)){
        if(i < sz(y) and y[i] == '1') continue;
        if(i < sz(a)-1 and a[i] == cur_sum[i] and a[i+1] == cur_sum[i+1]) continue;
        if(i < sz(x)) x[i] = y[i] = '1';
        cout << "x, y: " << x << " " << y << endl;
    }

    ll xx = bintodec(x), yy = bintodec(y); 
    cout << "x, y: " << x << " " << y << endl;
    cout << xx << " " << yy << endl;
    if((xx xor yy) == bb and xx+yy == aa) cout << xx << " " << yy << endl;
    else cout << -1 << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
