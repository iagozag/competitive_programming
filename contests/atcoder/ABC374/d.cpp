#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n; long double s, t;
vector<vector<long double>> v;

long double dist(long double a, long double b, long double c, long double d){
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

long double dp(int mask, int x, int y){
    if(mask == (1<<n)-1) return 0;

    long double mi = INF;
    for(int i = 0; i < n; i++) if(!(mask&(1<<i))){
        mi = min({mi, dist(x, y, v[i][0], v[i][1])/s+dist(v[i][0], v[i][1], v[i][2], v[i][3])/t+dp(mask|(1<<i), v[i][2], v[i][3]),
                  dist(x, y, v[i][2], v[i][3])/s+dist(v[i][0], v[i][1], v[i][2], v[i][3])/t+dp(mask|(1<<i), v[i][0], v[i][1])});
    }
    return mi;
}

void solve(){
    cin >> n >> s >> t;
    v = vector<vector<long double>>(n);
    for(auto& x: v){
        long double a, b, c, d; cin >> a >> b >> c >> d; x = {a, b, c, d};
    }

    cout << fixed << setprecision(12) << dp(0, 0, 0) << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
