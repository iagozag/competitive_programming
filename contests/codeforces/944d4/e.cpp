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
    ll n, k, q; cin >> n >> k >> q;
    vl a(k+1), b(k+1); rep(i, 1, k+1) cin >> a[i]; rep(i, 1, k+1) cin >> b[i];

    rep(i, 0, q){
        int d; cin >> d; 
        if(d == n){ cout << b[k] << " "; continue; }

        int ub = upper_bound(all(a), d)-a.begin(); ub--;
        cout << b[ub]+(d-a[ub])*(b[ub+1]-b[ub])/(a[ub+1]-a[ub]) << " ";
    }
    cout << endl;
}

int main(){ _
    int ttt; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
