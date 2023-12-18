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

int MAX = 3e5+10; string st;
vector<vi> g(MAX, vi(2)); vi ans(MAX, INF);

void dfs(int x){
    if(g[x][0] == -1 && g[x][1] == -1){ ans[x] = 0; return; }
    
    ans[x] = INF;
    if(g[x][0] != -1){
        dfs(g[x][0]);
        ans[x] = min(ans[x], ans[g[x][0]] + ((st[x] == 'L') ? 0 : 1));
    }

    if(g[x][1] != -1){
        dfs(g[x][1]);
        ans[x] = min(ans[x], ans[g[x][1]] + ((st[x] == 'R') ? 0 : 1));
    }
}

void solve(){
    int n; cin >> n;
    cin >> st;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b; a--, b--;

        g[i][0] = a, g[i][1] = b;
    }

    dfs(0);
    cout << ans[0] << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

