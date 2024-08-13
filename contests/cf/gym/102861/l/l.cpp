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

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<string> v;
vector<vector<vi>> has;
vector<vi> sum;
vector<string> q;

void dfs(int i, int j, string s, int d){
    if(i < 0 or j < 0 or i >= n or j >= m) return;
    s += v[i][j];
    sort(all(s));
    rep(qq, 0, sz(q)){
        string st = q[qq];
        if(s == st){
            int l = i, k = j, tam = sz(st); 
            while(tam--){
                if(!has[l][k][qq]) sum[l][k]++;
                has[l][k][qq] = 1;
                if(d == 0) k++;
                else if(d == 1) k--;
                else if(d == 3) l++;
                else if(d == 2) l--;
                else if(d == 6) l++, k++;
                else if(d == 7) l++, k--;
                else if(d == 4) l--, k++;
                else l--, k--; 
            }
        }
    }
    if(d == 0) dfs(i, j-1, s, 0);
    else if(d == 1) dfs(i, j+1, s, 1);
    else if(d == 3) dfs(i-1, j, s, 3);
    else if(d == 2) dfs(i+1, j, s, 2);
    else if(d == 6) dfs(i-1, j-1, s, 6);
    else if(d == 7) dfs(i-1, j+1, s, 7);
    else if(d == 4) dfs(i+1, j-1, s, 4);
    else dfs(i+1, j+1, s, 5);
}

// 0 = e
// 1 = d
// 2 = b
// 3 = c
// 4 = be
// 5 = bd
// 6 = ce
// 7 = cd

void solve(){
    cin >> n >> m;
    v = vector<string>(n);
    sum = vector<vi>(n, vi(m));
    forr(x, v) cin >> x;
    int qq; cin >> qq;
    q = vector<string>(qq); forr(x, q) cin >> x, sort(all(x));

    has = vector<vector<vi>>(n, vector<vi>(m, vi(qq)));

    rep(i, 0, n){
        rep(j, 0, m){
            string s = ""; s += v[i][j];
            dfs(i, j-1, s, 0), dfs(i, j+1, s, 1), dfs(i-1, j, s, 3), dfs(i+1, j, s, 2);
            dfs(i-1, j-1, s, 6), dfs(i-1, j+1, s, 7), dfs(i+1, j-1, s, 4), dfs(i+1, j+1, s, 5);
        }
    }

    int ans = 0;
    rep(i, 0, n) rep(j, 0, m) ans += (sum[i][j] > 1);
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
