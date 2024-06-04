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

const int MAX = 1e5+10;

void wrong(){
    cout << -1 << endl;
}

void solve(){
    int n; cin >> n;
    vi v(n), mp(MAX);
    rep(i, 0, n){
        cin >> v[i], mp[v[i]]++;
    }

    int i = 0;
    while(i < n and mp[i]){
        if(!mp[i]) break;
        if(mp[i] == 1){ return wrong(); }
        i++;
    }
    if(i == n) return wrong();

    set<int> s; int j = 0;
    for(; j < n; j++){
        if(v[j] < i){
            if(mp[v[j]] > 1) s.insert(v[j]), mp[v[j]]--;
            else return wrong();
        }
        if(s.size() == i) break;
    }
    cout << 2 << endl << 1 << " " << j+1 << endl << j+2 << " " << n << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}
