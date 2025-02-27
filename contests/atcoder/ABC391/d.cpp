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
	int n, w; cin >> n >> w;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++){ int a, b; cin >> a >> b; --a, --b; v.emplace_back(b, a); }
	sort(v.begin(), v.end());
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
