#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n; ll x;
vector<tuple<ll, ll, ll, ll>> v;

bool good(ll m){
    ll money = x;
    for(int i = 0; i < n; i++){
        auto [a, p, b, q] = v[i];
        ll mi = LINF;

        for(int j = 0; j <= b and m-j*a >= 0; j++) mi = min(mi, p*j+q*(((m-j*a)+b-1)/b));
        for(int j = 0; j <= a and m-j*b >= 0; j++) mi = min(mi, q*j+p*(((m-j*b)+a-1)/a));
        
        money -= mi;
        if(money < 0) return false;
    }

    return true;
}

void solve(){
    cin >> n >> x;
    for(int i = 0; i < n; i++){ ll a, b, c, d; cin >> a >> b >> c >> d; v.emplace_back(a, b, c, d); }
    
    ll l = 0, r = 1e9, ans = 0;
    while(l <= r){
        ll m = l+(r-l)/2;
        if(good(m)) ans = m, l = m+1;
        else r = m-1;
    }
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
