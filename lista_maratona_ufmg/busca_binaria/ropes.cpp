#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, k;
vector<double> v;

bool is_possible(double c){
    int p = 0;
    for(auto& e: v)
        p += e/c;

    return (p >= k);
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        double a; cin >> a; v.pb(a);
    }

    double l = 0, r = 1e9;
    for(int i = 0; i < 100; i++){
        double m = l+(r-l)/2.0;

        if(is_possible(m)) l = m;
        else r = m;
    }

    cout << fixed << setprecision(20) << l+(r-l)/2.0 << "\n"; 
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
