#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
int v[210][210];

void solve(){
	cin >> n; int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> v[i][j], ans += v[i][j];

	int mi = LINF;
	for(int i = 0; i < n; i++)
		mi = min(mi, v[i][n-i-1]);

	cout << ans-mi << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
