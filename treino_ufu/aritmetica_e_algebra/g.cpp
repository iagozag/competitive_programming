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

bool checkRightAngled(int X1, int Y1, int X2, int Y2, int X3, int Y3){
    int A = (int)pow((X2 - X1), 2) + (int)pow((Y2 - Y1), 2);

    int B = (int)pow((X3 - X2), 2) + (int)pow((Y3 - Y2), 2);

    int C = (int)pow((X3 - X1), 2) + (int)pow((Y3 - Y1), 2);

    return ((A > 0 and B > 0 and C > 0) and (A == (B + C) or B == (A + C) or C == (A + B)));
}

void solve(){
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    cout << (checkRightAngled(a, b, c, d, e, f) ? "sim\n" : "nao\n");
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
