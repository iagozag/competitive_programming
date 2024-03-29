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

void no(){ cout << "Sandro fails." << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 1e4+10, MOD = 1e9+7;

vector<vi> g(MAX);
vi in(MAX), vis(MAX), color(MAX);

bool cyc(int v){
    color[v] = 1;
    forr(ve, g[v]){
        if(color[ve] == 0 and cyc(ve)) return true;
        if(color[ve] == 1) return true;
    }
    color[v] = 2;
    return false;
}

void solve(){
    int n, m; cin >> n >> m;
    rep(i, 0, m){
        int a, b; cin >> a >> b; --a, --b;
        g[a].eb(b), in[b]++;
    }
    rep(i, 0, n) sort(all(g[i]));

    repr(i, n-1, 0) if(color[i] == 0 and cyc(i)) return no();

    vi ans; priority_queue<int> q;
    rep(i, 0, n) if(in[i] == 0) q.push(-i);
    while(!q.empty()){
        int v = q.top(); v -= 2*v; q.pop(), ans.eb(v);
        forr(ve, g[v]){
            in[ve]--;
            if(in[ve] == 0) q.push(-ve);
        }
    }

    forr(x, ans) cout << x+1 << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1;

    while(ttt--) solve();

    exit(0);
}
