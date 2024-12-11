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
	vector<int> v(200);
	int liters = 0;
	for(int i = 0; i < n; i++){ int a, b; cin >> a >> b; v[a] = b; }
	int cnt = 0;
	for(int i = 0; i < 200 and cnt < n; i++){
		if(v[i]) liters += v[i], cnt++;
		liters = max(0LL, liters-1);
	}
	cout << liters+1 << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
