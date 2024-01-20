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

const int MAX = 1e5+10;
vector<vi> v(MAX);

void solve(){
    int n; cin >> n; map<set<int>, int> mp;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--, b--;
        v[a].pb(b), v[b].pb(a);
        mp[{a, b}] = i;
    }

    vi ans(n-1, -1); bool bamboo = true;
    for(int i = 0; i < n; i++)
        if(v[i].size() > 2){
            for(int j = 0; j < 3; j++)
                ans[mp[{i, v[i][j]}]] = j;
            
            bamboo = false;
            break;
        }

    int k = (bamboo ? 0 : 3);
    for(auto& x: ans){
        if(x == -1) cout << k << endl, k++;
        else cout << x << endl;
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

