#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
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

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 3e3+10, MOD = 1e9+7;

void solve(){
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size(); a = " "+a, b = " "+b;

    int memo[n+1][m+1]; memset(memo, 0, sizeof memo);
    rep(i, 1, n+1) rep(j, 1, m+1){
        if(a[i] == b[j]) memo[i][j] = memo[i-1][j-1]+1;
        else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
    }

    // rep(i, 0, n+1) rep(j, 0, m+1) cout << memo[i][j] << " \n"[j == m];

    string ans = "";
    int i = n, j = m;
    while(true){
        while(j-1 > 0 and memo[i][j-1] == memo[i][j]) j--;
        while(i-1 > 0 and memo[i-1][j] == memo[i][j]) i--;
        if(memo[i][j] != 0) ans = a[i]+ans, i--, j--;
        else break; 

        if(i < 0 or j < 0) break;
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
