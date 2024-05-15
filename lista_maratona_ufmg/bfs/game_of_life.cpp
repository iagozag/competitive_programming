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

int n, m, t;
vector<string> v;

int query(int i, int j, ll p){

    return 0;
}

void solve(){
    cin >> n >> m >> t;
    v = vector<string>(n); forr(x, v) cin >> x;
    
    // code

    rep(k, 0, t){
        int i, j; ll p; cin >> i >> j >> p; --i, --j;
        cout << query(i, j, p) << endl;
    }
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
