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

void solve(){
    ll n; cin >> n;
    vector<vl> v(2, vl(n));
    rep(i, 0, 2) rep(j, 0, n) cin >> v[i][j];

    vector<vl> prefl, prefr, preflt, prefrt; prefl = prefr = preflt = prefrt = vector<vl>(2, vl(n));
    prefl[0][0] = v[0][0], prefl[1][0] = v[1][0];
    preflt[0][0] = 0, preflt[1][0] = v[1][0];
    prefr[0][n-1] = v[0][n-1], prefr[1][n-1] = v[1][n-1];
    prefrt[0][n-1] = v[0][n-1]*(n-1), prefrt[1][n-1] = v[1][n-1]*n;

    rep(i, 1, n){
        prefl[0][i] = prefr[0][i-1]+v[0][i];
        prefl[1][i] = prefl[1][i-1]+v[1][i];
        preflt[0][i] = preflt[0][i-1]+v[0][i]*i;
        preflt[1][i] = preflt[1][i-1]+v[1][i]*(i+1);
    }

    repr(i, n-2, 0){
        prefr[0][i] = prefr[0][i+1]+v[0][i];
        prefr[1][i] = prefr[1][i+1]+v[1][i];
        prefrt[0][i] = prefrt[0][i+1]+v[0][i]*i;
        prefrt[1][i] = prefrt[1][i+1]+v[1][i]*(i+1);
    }

    ll ans = 0, t = 0, sum = 0;
    rep(i, 0, n) ans += t*v[0][i], t++;
    repr(i, n-1, 0) ans += t*v[1][i], t++;

    t = 0, sum = 0; int pos = 0;
    rep(i, 0, n){

    }


    cout << max(ans, sum) << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
