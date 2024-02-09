#include<bits/stdc++.h>
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

int n, p;
vi a, b;
vector<pair<double,double>> sorted;

struct cmp {
    bool operator()(const std::pair<double,double> &left, const std::pair<double,double> &right) {
        if(left.s/left.f != right.s/right.f)
            return left.s/left.f < right.s/right.f;
        return left.s < right.s;
    }
};


bool check(int m){
    double sum_peop = 1, sum_mon = p;
    for(auto& x: sorted){
        
    }
    
    if(n > sum_mon) sum_mon += (n-sum_mon)*p;

    return (sum_mon <= m);
}

void solve(){
    cin >> n >> p;

    for(int i = 0; i < n; i++) { int x; cin >> x; a.pb(x); }
    for(int i = 0; i < n; i++) { int x; cin >> x; b.pb(x); }
    for(int i = 0; i < n; i++) { pair<double,double> p = {a[i], b[i]}; sorted.pb(p); }
    sort(all(sorted), cmp());

    for(auto& x: sorted) cout << x.f << " " << x.s << endl;

    int l = 0, r = 1e9;
    while(l < r){
        int m = (l+r)/2;
        if(check(m)) l = m+1;
        else r = m;
    }

    cout << l << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
