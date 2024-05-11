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

const int MAX = 1e5+1, MOD = 1e9+7;

void solve(){
    ll ra; cin >> ra;

    ll ans = 0;
    for(ll x = 0; x <= ra; x++){
        ll l = 0, r = ra, y_min;
        while(l <= r){
            ll m = l+(r-l)/2;
            if(x*x+m*m >= ra*ra) y_min = m, r = m-1;
            else l = m+1;
        }
        l = 0, r = ra+1; ll y_max;
        while(l <= r){
            ll m = l+(r-l)/2;
            if(x*x+m*m >= (ra+1)*(ra+1)) y_max = m, r = m-1;
            else l = m+1;
        }

        if(y_min == 0) y_min++;
        ans += 4*(y_max-y_min);
    }

    cout << ans << endl;
}

int main(){ _
    int ttt; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
