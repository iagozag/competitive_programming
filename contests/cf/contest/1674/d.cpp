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
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;
	for(int i = 0; i < n; i++) if((n-i)%2 == 0 and i < n-1 and v[i] > v[i+1]) swap(v[i], v[i+1]);
	for(int i = 1; i < n; i++) if(v[i] < v[i-1]){ cout << "NO" << endl; return; }
	cout << "YES" << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
