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

int m, n, MAX = 1010;
vector<vi> a(MAX, vi(3));

pair<bool, vl> check(int x){
    int cnt = 0; vl balloons(n);
    for(int i = 0; i < n; i++){
        int qnt = a[i][0]*a[i][1]+a[i][2],
        cnt_tmp = x/qnt*a[i][1] + min((x % qnt/a[i][0]), a[i][1]);
       
        if(cnt+cnt_tmp > m) cnt_tmp = m-cnt;
        cnt += cnt_tmp, balloons[i] = cnt_tmp;

        if(cnt == m) return {true, balloons};
    }

    return {false, vl(n)};
}

void solve(){
    cin >> m >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++){ int x; cin >> x; a[i][j] = x; }

    int l = 0, r = 1e9+10; pair<ll, vl> ans;
    while(l <= r){
        int m = l+(r-l)/2; pair<bool, vl> chk = check(m);
        if(chk.f) ans = {m, chk.s}, r = m-1;
        else l = m+1;
    }

    cout << ans.f << endl;
    for(auto& x: ans.s) cout << x << " ";
    cout << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
