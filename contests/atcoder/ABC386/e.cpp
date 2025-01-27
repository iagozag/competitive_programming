#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, k;
int v[MAX];
int ans = 0, y = 0, swp = 0;

void choose(int x, int m, int i){
	if(m == k){ ans = max(ans, (swp ? x^y : x)); return; }
	if(i >= n) return;

	choose(x^v[i], m+1, i+1), choose(x, m, i+1);
}

void solve(){
	cin >> n >> k;
	if(k > n-k) swp = 1, k = n-k;
	for(int i = 0; i < n; i++) cin >> v[i], y ^= v[i];
	choose(0, 0, 0);
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
