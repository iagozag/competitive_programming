#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define f first
#define s second
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

int n;
vi a, b, c;
ll memo[3][100010];

ll dp(int d, int act){
    if(d == n) return 0;

    ll& p = memo[act][d];
    if(p != -1) return p;

    if(act == 0) return p = max(dp(d+1, 1)+b[d], dp(d+1, 2)+c[d]);
    else if(act == 1) return p = max(dp(d+1, 0)+a[d], dp(d+1, 2)+c[d]);
    return p = max(dp(d+1, 0)+a[d], dp(d+1, 1)+b[d]);
}

void solve(){
    cin >> n;
    a = b = c = vi(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    memset(memo, -1, sizeof memo);

    cout << max(dp(0, 0), max(dp(0, 1), dp(0, 2))) << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

