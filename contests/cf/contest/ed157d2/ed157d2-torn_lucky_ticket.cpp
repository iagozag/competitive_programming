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

const int MAX = 2e5+10;

int sum(string s, int st, int end, int d){
    int ss = 0;
    if(d == 1) rep(i, st, end) ss += s[i]-'0';
    else repr(i, st, end) ss += s[i]-'0';
    return ss;
}

void solve(){
    int n; cin >> n;
    vector<string> v(n); rep(i, 0, n) cin >> v[i];

    int cnt[6][46]; ll ans = 0;
    forr(x, v) cnt[x.size()][sum(x, 0, x.size(), 1)]++;
    forr(x, v)
        for(int i = x.size()%2; i <= x.size(); i+=2){
            int sz = x.size()+i;
            int s1 = sum(x, 0, sz/2, 1), s2 = sum(x, sz/2, x.size(), 1);
            if(s1-s2 >= 0) ans += cnt[i][s1-s2];
        }
    forr(x, v)
        for(int i = x.size()%2; i <= x.size(); i+=2){
            int sz = x.size()+i;
            int s1 = sum(x, x.size()-1, sz/2, -1), s2 = sum(x, sz/2-1, 0, -1);
            if(s1-s2 >= 0) ans += cnt[i][s1-s2];
        }

    cout << ans << endl;
}

int main(){ _
    int t = 1;

    while(t--) solve();

    exit(0);
}
