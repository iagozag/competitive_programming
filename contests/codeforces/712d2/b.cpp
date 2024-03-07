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

void solve(){
    int n; cin >> n; string s, s1; cin >> s >> s1;

    vector<ii> v(n+1); v[0].ff = v[0].ss = 0; 
    rep(i, 1, n+1) v[i].ff = v[i-1].ff+(s1[i-1]=='0'), v[i].ss = v[i-1].ss+(s1[i-1]=='1');

    bool flip = false;
    repr(i, n-1, 0){
        if(!flip and s1[i]!=s[i] or flip and s1[i] == s[i]){ 
            if(v[i+1].ff != v[i+1].ss){ cout << "NO\n"; return; }
            flip = !flip;
        }
    }

    cout << "YES" << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}
