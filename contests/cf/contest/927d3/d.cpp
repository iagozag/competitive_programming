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
    int n; cin >> n;
    char c; cin >> c;
    vector<pair<int, char>> trump;
    vector<pair<int, char>> v; 
    rep(i, 0, 2*n){
        string a; cin >> a; 
        if(a[1] == c) trump.pb({a[0]-'0', a[1]});
        else v.pb({a[0]-'0', a[1]});
    }
    sort(all(v), [&](const pair<int, char> a, const pair<int, char> b){
        if(a.ss != b.ss) return a.ss > b.ss;
        return a.ff < b.ff;
    });
    sort(all(trump), [&](const pair<int, char> a, const pair<int, char> b){
        return a.ff < b.ff;
    });

    // forr(v){ dbg(x.ff, x.ss); }

    vector<vector<pair<int, char>>> ans;
    int i = 0, j = 1, k = 0;
    while(i < v.size()){
        if(j == i) j++;
        if(v[i].ff == -1){ i++; if(j == i) j++; continue; }

        while(j < v.size() and v[i].ss == v[j].ss and v[i].ff == v[j].ff) j++;
        if(j < v.size() and v[i].ss == v[j].ss) ans.pb({v[i], v[j]}), v[j].ff = -1, i++, j++;
        else if(k < trump.size()) ans.pb({v[i], trump[k]}), i++, k++;
        else{ cout << "IMPOSSIBLE\n"; return; }
    }

    int l = k+1;
    while(k < trump.size()){
        if(k == l) l++;
        if(trump[k].ff == -1){ k++; if(k == l) l++; continue; }

        while(l < trump.size() and trump[k].ff == trump[l].ff) l++;
        if(l < trump.size() and l == trump.size()){ cout << "IMPOSSIBLE\n"; return; }
        else ans.pb({trump[k], trump[l]}), k++, trump[l].ff = -1, l++;
    }

    forr(ans) cout << x[0].ff << x[0].ss << " " << x[1].ff << x[1].ss << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
