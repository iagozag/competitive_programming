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
	int N, Q; cin >> N >> Q;
	vector<int> v(N); for(auto& x: v) cin >> x;

	vector<vector<int>> pos(N, vector<int>(30, -1));
	for(int i = 0; i < 30; i++){
		for(int j = 0; j < N-1; j++) pos[j+1][i] = ((v[j]&(1<<i)) ? j : pos[j][i]);
	}

	vector<int> pref(N);
	for(int i = 0; i < N; i++) pref[i] = v[i]^(i ? pref[i-1] : 0);

	auto get_xor = [&](int l, int r) -> int{
		if(l > r) return 0;
		return pref[r]^(l ? pref[l-1] : 0);
	};

	for(int q = 0; q < Q; q++){
		int x; cin >> x;

		int p = N-1;
		for(int i = 29; i >= 0; i--){
			if(p == -1 or x <= v[p]){ if(p != -1 and x == v[p]) p--; break; }

			if((x&(1<<i))^(v[p]&(1<<i))){
				int ma = -1;
				for(int j = 29; j >= i; j--) ma = max(ma, pos[p][j]);

				x ^= get_xor(ma+1, p), p = ma, i++;
			}
		}

		cout << N-p-1 << ' ';

	}
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
