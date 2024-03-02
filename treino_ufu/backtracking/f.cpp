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
    int n; cin >> n; cin.ignore();
    vector<vector<string>> v(n);
    rep(i, 0, n){
        string s; getline(cin, s); istringstream ss(s);

        string tmp;
        while(ss >> tmp) v[i].eb(tmp);
    }

    map<pair<string,string>, pair<int, double>> mp;
    int m; cin >> m; cin.ignore();
    rep(i, 0, m){
        string s1, s2; int d1; double d2; cin >> s1 >> s2 >> d1 >> d2;
        mp[{s1, s2}] = {d1, d2};
    }

    vector<ii> values(n);
    rep(i, 0, n){
        rep(j, 0, v[i].size()-1){
            values[i].ff += mp[{v[i][j], v[i][j+1]}].ff;
            values[i].ss += mp[{v[i][j], v[i][j+1]}].ss;
        }
    }

    int idx_p = 0;
    rep(i, 1, n)
        if(values[i].ss < values[idx_p].ss) idx_p = i;

    vi ans;
    rep(i, 0, n){
        if(idx_p == i) continue;

        if(values[i].ff < values[idx_p].ff and values[i].ss <= values[idx_p].ss*1.2) ans.eb(i);
    }

    sort(all(ans), [&](const int a, const int b){
        return values[a].ss < values[b].ss;
    });

    if(ans.size()) rep(i, 0, v[ans[0]].size()) cout << v[ans[0]][i] << " \n"[i == v[ans[0]].size()-1];
    else rep(i, 0, v[idx_p].size()) cout << v[idx_p][i] << " \n"[i == v[idx_p].size()-1];
}

int main(){ _
    int t = 1;

    while(t--) solve();

    exit(0);
}
