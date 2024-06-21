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
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    int ma = (n&1 ? n*m-(m-1) : n*m);
    if(((k&1) xor (ma&1)) or k < n or k > ma) return no();
    cout << "Yes\n";

    vector<string> ans(2*n+1, string(2*m+1, '+'));
    ans[0][2*m-1] = 'S', ans[2*n][2*m-1] = 'G'; 
    
    for(int i = 1; i < 2*n; i += 2) for(int j = 1; j < 2*m; j += 2) ans[i][j] = 'o';
    for(int i = 1; i < 2*n; i++) for(int j = 1+(i&1); j < 2*m; j += 2) ans[i][j] = '.';

    int dist = 1, curx = 1, cury = m, matx = 1, maty = 2*m-1;
    while(curx != n or cury != m){
        while(cury > 1 and dist+n-curx != k)
            cury--, dist += 2, ans[matx+1][maty] = '-', maty -= 2;

        ans[matx][maty-1] = '|';
        curx++, matx += 2;
        ans[matx][maty-1] = '|';

        while(cury < m) ans[matx+1][maty] = '-', cury++, maty += 2;

        if(curx == n and cury == m) break;

        curx++, matx += 2, dist += 2;
    }

    rep(i, 0, 2*n+1) ans[i][0] = '+';
    rep(i, 0, 2*m+1) ans[2*n][i] = '+';
    ans[2*n][2*m-1] = 'G';
    if(n&1) ans[2*n-1][2*m-2] = '|';

    forr(x, ans) cout << x << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
