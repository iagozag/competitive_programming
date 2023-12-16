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

typedef pair<double,double> pp;

void solve(){
    pp a, b, s;
    cin >> a.f >> a.s >> b.f >> b.s >> s.f >> s.s;

    pp median = {(a.f+b.f)/2, (a.s+b.s)/2};

    double m1 = -1/((b.s-a.s)/(b.f-a.f)), m2 = (b.s-a.s)/(b.f-a.f);
    pp perp_median = {m1, -median.f*m1 + median.s};
    pp parallel_s = {m2, -s.f*m2 + s.s};

    double x = -(perp_median.s - parallel_s.s)/(perp_median.f-parallel_s.f),
           y = perp_median.f*x+perp_median.s;
    x = trunc(x*100)/100, y = trunc(y*100)/100;
    printf("%.2f %.2f\n", x, y); 
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

