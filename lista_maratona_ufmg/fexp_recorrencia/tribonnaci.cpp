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

const int MAX = 2e5+10, MOD = 1e9+9;

ll n;
vector<vl> m2 = {{2}, {1}, {0}};

vector<vl> mult(vector<vl> a, vector<vl> b){
    int sza = sz(a[0]), szb = sz(b[0]);
    vector<vl> tm(sza, vl(szb));
    rep(i, 0, sza) rep(j, 0, szb) rep(k, 0, sza) tm[i][j] += (a[i][k]%MOD)*(b[k][j]%MOD), tm[i][j] %= MOD;
    return tm;
}

vector<vl> fexp(vector<vl> m, ll k){
    vector<vl> tm(3, vl(3)); rep(i, 0, 3) tm[i][i] = 1;
    while(k){
        if(k&1) tm = mult(tm, m);
        m = mult(m, m), k >>= 1;
    }
    return tm;
}

void solve(){
    if(n <= 3){ cout << m2[3-n][0] << endl; return; }

    vector<vl> m = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    vector<vl> ans = mult(fexp(m, n-3), m2);
    cout << ans[0][0] << endl;
}

int main(){ _
    while(cin >> n and n) solve();

    exit(0);
}
