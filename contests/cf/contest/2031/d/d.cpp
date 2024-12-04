#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n; vector<int> v(n); for(auto& x: v) cin >> x;

	vector<int> less(n), ans(n); vector<pair<int, int>> pq(n);
	for(int i = 0; i < n; i++) pq[i] = {v[i], i};
	sort(pq.begin(), pq.end(), [&](const pair<int, int> a, const pair<int, int> b){
		if(a.first != b.first) return a.first > b.first;
		return a.second < b.second;
	});

	int k = 0; set<pair<int, int>> st;
	for(int i = n-1; i >= 0; i--){
		st.insert({v[i], i});
		while(k < n){
			auto [a, b] = pq[k]; if(st.count({a, b})){ k++; continue; }
			if(a <= v[i]) break;
			less[b] = i, k++;
		}
	}

	for(int i = 0; i < n; i++){
		auto [a, b] = pq[i]; if(ans[b]) continue;

		ans[b] = max(a, less[b] ? ans[less[b]]: 0);
		for(int j = b+1; j < n and !ans[j]; j++) ans[j] = max(ans[j], ans[b]);
	}
	
	for(int i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
