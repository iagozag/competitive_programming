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

const int MAX = 1e5+10, MOD = 1e9+7;

void solve(){
    int n, x, sum = 0; cin >> n >> x;
    vl c(n), h(n); rep(i, 0, n) cin >> c[i] >> h[i], sum += h[i];
    sum++;

    vector<vector<ll>> memo(n+1, vl(sum, -1)); memo[0][0] = 0;
    rep(i, 0, n) rep(j, 0, sum){
        if(memo[i][j] == -1) continue;
        if(memo[i][j] >= c[i]) memo[i+1][j+h[i]] = max(memo[i+1][j+h[i]], memo[i][j]+x-c[i]);
        memo[i+1][j] = max(memo[i+1][j], memo[i][j]+x); 
    } 

    repr(i, sum-1, 0) if(memo[n][i] != -1){ 
        cout << i << endl; return; 
    }
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
