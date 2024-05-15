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

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    map<int, int, greater<int>> coins; cin >> coins[1] >> coins[5] >> coins[10] >> coins[50] >> coins[100] >> coins[500];
    int n; cin >> n;
    vi v(n); forr(x, v) cin >> x;
    rep(i, 0, n){
        forr(x, coins){
            if(v[i] < x.ff) continue;
            int mi = min(v[i]/x.ff, x.ss);
            x.ss -= mi, v[i] -= mi*x.ff;
        }
        if(v[i] != 0) return no();
    }

    return yes();
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
