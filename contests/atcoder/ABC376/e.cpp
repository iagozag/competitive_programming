#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+1, MOD = 1e9+7;
void solve(){
	int n, k; cin >> n >> k;
	vector<pair<ll, ll>> v(n);
	for(int i = 0; i < n; i++) cin >> v[i].first;
	for(int i = 0; i < n; i++) cin >> v[i].second;

	sort(v.begin(), v.end());

	ll sum = 0; priority_queue<ll> pq;
	for(int i = 0; i < k; i++) pq.push(v[i].second), sum += v[i].second;

	ll ans = v[k-1].first*sum;
	for(int i = k; i < n; i++){
		auto [a, b] = v[i];	auto t = pq.top();
		if(b < t) sum -= t-b, pq.pop(), pq.push(b);
		ans = min(ans, a*sum);
	}

	cout << ans << endl;

}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
