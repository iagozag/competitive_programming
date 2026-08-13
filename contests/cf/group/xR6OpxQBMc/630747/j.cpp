#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, tot = 0; cin >> n;
    vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i], tot += v[i];
    sort(v.begin(), v.end());

    if(n == 1){ cout << 1 << endl; return; }

    int  sum = 0;
    for(int i = 0; i < n-2; i++) sum += v[i];
    v[n-1] -= sum;

    //for(int i = 0; i < n; i++) cout << v[i] << ' ';
    //cout << endl;

    if(v[n-1] <= v[n-2]+1) cout << tot << endl;
    else cout << sum*2+v[n-2]*2+1 << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

