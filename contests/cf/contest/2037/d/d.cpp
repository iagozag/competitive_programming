#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

ll n, m, k;
vector<pair<ll, ll>> intervals, powers;

void solve(){
	cin >> n >> m >> k;
	intervals = vector<pair<ll, ll>>(n);
	powers = vector<pair<ll, ll>>(m);
	for(int i = 0; i < n; i++) cin >> intervals[i].first >> intervals[i].second;
	for(int i = 0; i < m; i++) cin >> powers[i].first >> powers[i].second;

	priority_queue<ll> pq;

	int j = 0; int ans = 0; ll cur = 1, p = 1;
	for(int i = 0; i < n; i++){
		p = intervals[i].first;
		while(j < m and powers[j].first <= p) pq.push(powers[j++].second);

		while(cur <= intervals[i].second-intervals[i].first+1 and !pq.empty()){
			ans++, cur += pq.top(), pq.pop();
		}

		if(cur <= intervals[i].second-intervals[i].first+1){ cout << -1 << endl; return; }
	}

	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
