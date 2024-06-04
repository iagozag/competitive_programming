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

void no(){ cout << "NO" << endl; }
void yes(int a){ cout << a << endl; }

const int MAX = 2e5+10;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vi prefz(n), prefo(n); prefz[0] = s[0]=='0', prefo[n-1] = s[n-1]=='1';
    rep(i, 1, n) prefz[i] = prefz[i-1]+(s[i]=='0');
    repr(i, n-2, 0) prefo[i] = prefo[i+1]+(s[i]=='1');

    int i = n/2, j = i+1, ansi = -1, ansj = -1;
    while(i >= 0 or j < n){
        if(ansi != -1 and ansj != -1) break;
        if(i == 0 and prefo[0]) if(ansi == -1) ansi = i;
        if(j == n and prefz[n-1]) if(ansj == -1) ansj = j;

        if(i > 0 and (prefz[i-1] < (i+1)/2 or prefo[i] < (n-i+1)/2)) i--;
        else if(i != 0 and ansi == -1) ansi = i;
        if(j < n and (prefz[j-1] < (j+1)/2 or prefo[j] < (n-j+1)/2)) j++;
        else if(j != n and ansj == -1) ansj = j;
    }
    if(n/2-ansi <= ansj-n/2) cout << ansi << endl;
    else cout << ansj << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}
