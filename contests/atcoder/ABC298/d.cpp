#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

void solve(){
	queue<int> q; q.push(1);

	int Q, ans = 1; cin >> Q;
	for(int k = 0; k < Q; k++){
		int op; cin >> op;
		if(op == 1){
			int x; cin >> x;
			q.push(x), ans *= 10, ans %= MOD, ans += x, ans %= MOD;
		} else if(op == 2){
			int num = fexp(10, (int)q.size()-1)*q.front()%MOD; q.pop();
			ans -= num, ans %= MOD, ans += MOD, ans %= MOD;
		} else cout << ans << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
