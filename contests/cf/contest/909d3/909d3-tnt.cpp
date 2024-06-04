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

int n, mini = INF, maxi = -INF, total = -INF;

void check(int m){

}

void solve(){
    ll n, ans = 0; cin >> n;
    vl v(n), div; for(auto& x: v) cin >> x;

    for(int i = 1; i <= n/2; i++) if(n%i == 0) div.pb(i);

    for(auto& x: div){
        ll cnt = 0, sum = 0, mini = LINF, maxi = -LINF, total = 0;
        for(int j = 0; j < n; j++){
            sum += v[j], cnt++;

            if(cnt == x){
                mini = min(mini, sum);
                maxi = max(maxi, sum);
                sum = 0, cnt = 0;
            }
        }

        total = maxi-mini;
        ans = max(ans, total);
    }

    cout << ans << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

