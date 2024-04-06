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
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    map<int,int> numbers; rep(i, 0, n){ int a; cin >> a; numbers[a]++; }

    map<int,int> mp;
    rep(i, 1, 101){
        int cnt = 0; map<int,int> num = numbers;
        forr(x, num){
            if(x.ss <= 0 or x.ff >= i) continue;
            int need = i-x.ff; if(num[need] == 0) continue;

            if(x.ff == need){
                cnt += x.ss/2, x.ss = 0;
                continue;
            }

            int mi = min(x.ss, num[need]);
            cnt += mi; x.ss -= mi, num[need] -= mi;
        }
        mp[i] = cnt;
    }

    int ma = 0;
    forr(x, mp) ma = max(ma, x.ss);
    cout << ma << endl;
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}

