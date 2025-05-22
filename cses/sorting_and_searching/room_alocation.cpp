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
	int n; cin >> n;
	vector<tuple<int, int, int>> ev;

	for(int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		ev.emplace_back(a, 0, i), ev.emplace_back(b, 1, i);
	}
	sort(ev.begin(), ev.end());

	priority_queue<int> pq;
	for(int i = 1; i < MAX; i++) pq.push(-i);

	vector<int> ans(n);
	for(int i = 0; i < 2*n; i++){
		auto [a, b, c] = ev[i];
		if(b == 0){
			ans[c] = -pq.top();
			pq.pop();
		} else{
			pq.push(-ans[c]);
		}
	}

	cout << *max_element(ans.begin(), ans.end()) << endl;
	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
