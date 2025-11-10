#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

bool solve(){
	int n, m; cin >> n >> m;
	if(n == 0 and m == 0) return false;
	vector<int> deg(n);
	for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; --a, --b; deg[a]++, deg[b]++; }

	sort(deg.begin(), deg.end(), greater<int>());

	int sum1 = 0, sum2 = 0, M = -1;
	for(int i = 0; i < n; i++){
		if(deg[i] >= i) M = i, sum1 += deg[i];
		else sum2 += deg[i];
	}

	if(M != -1 and M*(M+1)+sum2 == sum1) cout << 'Y' << endl;
	else cout << 'N' << endl;

	return true;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(solve());

    exit(0);
}
