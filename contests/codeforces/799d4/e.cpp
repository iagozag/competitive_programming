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

void no(){ cout << "-1" << endl; }
void yes(){ cout << "0" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, s, sum = 0; cin >> n >> s;
    vi v(n); forr(x, v) cin >> x, sum += x;
    if(sum < s) return no();
    if(sum == s) return yes();

    vi prefl(n, -1), prefr(n, -1); int prev = -1;
    rep(i, 0, n){ 
        if(v[i]) prefl[i] = prev, prev = i;
        else if(i > 0) prefl[i] = prev;
    }
    prev = -1;
    repr(i, n-1, 0){ 
        if(v[i]) prefr[i] = prev, prev = i;
        else if(i < n-1) prefr[i] = prev;
    }

    int i = 0, j, cur;
    while(v[i] != 1) i++;
    j = i+1, cur = 1;
    while(cur != s){ if(v[j]) cur++; j++; }
    j--;

    // dbgc(prefl, prefr); dbg(i, j);
    int mi = (prefr[j] != -1 ? n-prefr[j] : 0)+(prefl[i] != -1 ? prefl[i]+1 : 0);
    while(j < n){
        j++;
        while(j < n and v[j] == 0) j++;
        if(j == n) break;

        i++;
        while(i < j and v[i] == 0) i++;
        // dbg(i, j);
        mi = min(mi, (prefr[j] != -1 ? n-prefr[j] : 0)+(prefl[i] != -1 ? prefl[i]+1 : 0));
    }

    cout << mi << endl;
}

int main(){ _
    int ttt; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
