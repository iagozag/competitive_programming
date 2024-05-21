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

int n, m;
vector<string> v; vector<vector<bool>> vis;
vector<pii> moves = {{1, 0}, {0, 1}};

bool val(int i, int j){
    return i >= 0 and i < n and j >= 0 and j < m;
}

void solve(){
    cin >> n >> m;
    v = vector<string>(n), vis = vector<vector<bool>>(n, vector<bool>(m)); 
    forr(x, v) cin >> x;
    string ans = string(n+m-1, 'z');
    queue<tuple<int,int,int>> q; q.push({0, 0, 0}); ans[0] = v[0][0];
    while(!q.empty()){
        auto [i, j, k] = q.front(); q.pop();
        if(vis[i][j]) continue;
        vis[i][j] = 1;

        if(ans[k] != v[i][j]) continue;

        for(auto [x, y]: moves){
            x += i, y += j;
            if(!val(x, y)) continue;
            ans[k+1] = min(ans[k+1], v[x][y]), q.push({x, y, k+1});
        }
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
