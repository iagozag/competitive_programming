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
	int N, M, K; cin >> N >> M >> K;
	vector<int> a(N), b(M);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;

	for(int l = 30; l >= 0 and K; l--){
		priority_queue<pair<int, int>> pq;
		int want = (1<<l);
		for(int i = 0; i < N; i++){
			int mi = LINF;
			for(int j = 0; j < M; j++) if(mi > (a[i]&b[j])) mi = (a[i]&b[j]);
			if(a[i]-mi >= want) pq.push({a[i]-mi, i});
		}

		while(!pq.empty() and K){
			auto [x, y] = pq.top(); pq.pop();
			a[y] -= x, K--;
		}
	}

	int ans = 0;
	for(auto x: a) ans += x;
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
