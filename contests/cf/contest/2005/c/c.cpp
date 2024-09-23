#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
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

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<string> v;
vector<vi> memo;

int dp(int i, char c){
    if(i == n) return 0;
    if(memo[i][c-'0'] != -INF) return memo[i][c-'0'];

    int cnt = 0; char newc = c;
    rep(j, 0, m) if(v[i][j] >= '0' and v[i][j] <= '4'){
        cnt--;
        if(newc == v[i][j]) newc++;
        if(newc == '5') cnt += 10, newc = '0';
    }

    return memo[i][c-'0'] = max(dp(i+1, c), dp(i+1, newc)+cnt);
}

void solve(){
    cin >> n >> m;
    v = vector<string>(n);
    rep(i, 0, n) rep(j, 0, m){
        char c; cin >> c;
        if(c == 'n') c = '0';
        else if(c == 'a') c = '1';
        else if(c == 'r') c = '2';
        else if(c == 'e') c = '3';
        else if(c == 'k') c = '4';
        v[i] += c;
    }

    memo = vector<vi>(n, vi(5, -INF));
    cout << dp(0, '0') << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
