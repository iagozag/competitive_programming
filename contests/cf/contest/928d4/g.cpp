#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repr(i,n,x) for(int i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ff first
#define ss second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void DBG() {
    cerr << "]" << endl;
}

void DBGC() {
    cerr << "]" << endl;
}

template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t)) cerr << ", ";
    DBG(t...);
}

template<class H, class... T> void DBGC(H h, T... t) {
    for(auto& x: h) cerr << x << " ";
    if(sizeof...(t)) cerr << "], [ ";
    DBGC(t...);
}

#ifndef _DEBUG
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 
#else
#define dbg(...) 0
#define dbgc(...) 0
#endif

const int MAX = 1e5+10;

vector<vi> g;
int color[MAX], dp[MAX][2];

void dfs(int x){
    for(auto& ve: g[x]){
        dfs(ve);
        if(color[x]&1){
            if(color[ve] == 1) dp[x][0] += dp[ve][0];
            else if(color[ve] == 2) dp[x][0] += dp[ve][1]+1;
            else dp[x][0] += min(dp[ve][0], dp[ve][1]+1);
        }
        if(color[x]&2){
            if(color[ve] == 1) dp[x][1] += dp[ve][0]+1;
            else if(color[ve] == 2) dp[x][1] += dp[ve][1];
            else dp[x][1] += min(dp[ve][0]+1, dp[ve][1]);
        }
    }
}

void solve(){
    int n; cin >> n;
    g = vector<vi>(n); memset(dp, 0, sizeof dp);
    rep(i, 1, n){
        int a; cin >> a; a--;
        g[a].pb(i);
    }

    string s; cin >> s;
    rep(i, 0, s.size())
        color[i] = s[i] == 'P' ? 1 : s[i] == 'S' ? 2 : 3;

    dfs(0);

    int ans = n+1;
    if(color[0]&1) ans = min(ans, dp[0][0]);
    if(color[0]&2) ans = min(ans, dp[0][1]);

    cout << ans << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
