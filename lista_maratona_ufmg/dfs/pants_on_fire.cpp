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

const int MAX = 210;

vector<vi> g(MAX);

bool dfs(int a, int b){
    if(a == b) return true;

    bool ans = false;
    for(auto& ve: g[a])
        ans |= dfs(ve, b);

    return ans;
}

void solve(){
    int n, m, k = 0; cin >> n >> m;
    map<string, int> mp;
    vector<string> stat(2);
    
    rep(i, 0, n){
        cin >> stat[0];
        rep(j, 0, 4) cin >> stat[1];
        if(!mp.count(stat[0])) mp[stat[0]] = k, k++;
        if(!mp.count(stat[1])) mp[stat[1]] = k, k++;

        g[mp[stat[0]]].pb(mp[stat[1]]);
    }

    rep(i, 0, m){
        cin >> stat[0];
        rep(j, 0, 4) cin >> stat[1];

        if(!mp.count(stat[0]) || !mp.count(stat[1])){ cout << "Pants on Fire" << endl; continue; }

        if(dfs(mp[stat[0]], mp[stat[1]])) cout << "Fact";
        else if(dfs(mp[stat[1]], mp[stat[0]])) cout << "Alternative Fact";
        else cout << "Pants on Fire";
        cout << endl;
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
