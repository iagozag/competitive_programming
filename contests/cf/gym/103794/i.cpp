#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int f(vector<int> v, int k){
	priority_queue<pair<int, int>> pq;

	int sum = 0, ans = -LINF, n = v.size();
	pq.push({0, -1});
	for(int i = 0; i < n; i++){
		sum += v[i];
		while(!pq.empty() and pq.top().second < i-k) pq.pop();
		ans = max(ans, sum+pq.top().first);
		pq.push({-sum, i});
	}

	return ans;
}

void solve(){
	int n; cin >> n;
	vector<int> dup(2*n);
	vector<vector<int>> v(2);
	for(int i = 0; i < n; i++) cin >> dup[i], dup[i+n] = dup[i];
	for(int i = 0; i < 2*n; i++){
		v[i&1].emplace_back(dup[i]);
	}

	cout << max(f(v[0], n/2), f(v[1], n/2)) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
