#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repr(i,n,x) for(int i=n;i>=x;i--)
#define forr(v) for(auto& x: v)
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

const int MAX = 2e5+10;

void solve(){
    string st; cin >> st; int n = st.size();
    vi prefa(n), prefb(n);
    if(st[0] == 'A') prefa[0] = 1;
    else prefb[0] = 1;

    rep(i, 1, n){
        if(st[i] == 'A') prefa[i] = prefa[i-1]+1, prefb[i] = prefb[i-1];
        else prefa[i] = prefa[i-1], prefb[i] = prefb[i-1]+1;
    } 

    int lb = lower_bound(all(prefb), prefb[n-1]) - prefb.begin(), ans = n;
    if(prefa[lb] > prefb[lb]) ans -= prefb[lb]*2;
    else prefb[lb] -= prefa[lb], ans -= prefa[lb]*2+(prefb[lb]/2)*2;

    cout << ans << endl;

}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
