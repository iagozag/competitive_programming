#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int l, g;

void solve(){
	vector<pair<int, int>> v(g); 
	for(auto& [a, b]: v){
		cin >> a >> b;
		int prev = a;
		a = prev-b, b = prev+b;
	}
	sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b){
		if(a.first != b.first) return a.first < b.first;
		return a.second > b.second;
	});

	int need = 0, ans = 0, i = 0; priority_queue<int> pq;
	while(i < g){
		auto [a, b] = v[i];
		if(a <= need){ pq.push(b), i++; continue; }

		if(pq.empty() or pq.top() < need){ cout << -1 << endl; return; }

		need = pq.top(); pq.pop();
		ans++;
	}

	if(pq.size() and need < l and pq.top() >= l) ans++, need = pq.top();

	cout << (need < l ? -1 : g-ans) << endl;
}

int32_t main(){ _
    while(cin >> l >> g and (l or g)) solve();

    exit(0);
}
