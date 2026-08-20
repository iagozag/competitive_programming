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
	int n, k, x; cin >> n >> k >> x;
	vector<int> v(n); for(auto& y: v) cin >> y;
	sort(v.begin(), v.end(), greater<int>());

	set<vector<int>> st;

	priority_queue<pair<int, vector<int>>> pq;
	vector<int> qnt(n); qnt[0] = k;
	pq.emplace(v[0]*k, qnt), st.insert(qnt);
	for(int i = 0; i < x; i++){
		auto [sum, tmp] = pq.top(); pq.pop();
		cout << sum << endl;

		for(int j = 0; j < n-1; j++) if(tmp[j]){
			tmp[j]--, tmp[j+1]++;
			if(!st.count(tmp)) pq.emplace(sum-v[j]+v[j+1], tmp), st.insert(tmp);
			tmp[j]++, tmp[j+1]--;
		}
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;



    while(ttt--) solve();

    exit(0);
}
