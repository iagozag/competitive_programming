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

const int MAX = 110, MOD = 1e9+7;

int n, m;
ll memo[MAX][MAX][MAX];
vector<vi> v(MAX, vi(MAX));
vi pos(MAX);

ll dp(int i, int l, int r, int k){
    if(k == 0 or l > r) return 0;

    ll& p = memo[i][l][r];
    if(p != -1) return p;

    return p = max({dp(i-1, 0, pos[i+1], k-1)+max(dp(i, l+1, r, k-1)+v[i][l], dp(i, l, r-1, k-1)+v[i][r]),
                    max(dp(i, l+1, r, k-1)+v[i][l], dp(i, l, r-1, k-1)+v[i][r])});
}

void solve(){
    cin >> n >> m;
    rep(i, 0, n){
        int a; cin >> a; pos[i] = a-1;
        rep(j, 0, a){ int b; cin >> b; v[i][j] = b; }
    }
    pos[n] = -1;

    memset(memo, -1, sizeof memo);
    dp(n-1, 0, pos[0], m);

    cout << memo[0][0][pos[0]] << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
