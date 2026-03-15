#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	priority_queue<int> pq; int ma = 0;
	for(int i = 0; i < n; i++){ int x; cin >> x; ma = max(ma, x); pq.push(-x); }

	int ans = 0;
	while(pq.size() > 1){
		int x = pq.top(); pq.pop(); x *= -1;
		int y = pq.top(); pq.pop(); y *= -1;

		int mmc = lcm(x, y);
		if(__builtin_popcount(mmc/x) != 1){ cout << -1 << endl; return; }

		pq.push(-x*2);

		if(x != y){
			ans++;
			pq.push(-y);
		}	
	}

	cout << (pq.size() == 1 ? ans : -1) << endl;
}

int32_t main(){ _
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


