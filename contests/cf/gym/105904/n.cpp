#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
#define int ll

const int MAX = 1e6+10;

int32_t main(){ _
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;

	vector<int> lp(MAX); iota(lp.begin(), lp.end(),  0);
	for(int i = 2; i < MAX; i++){
		if(lp[i] == i){
			for(int j = i*i; j < MAX; j += i) if(lp[j] == j) lp[j] = i;
		}
	}

	auto fact = [&](int x) -> vector<int> {
		vector<int> f;
		while(x > 1){
			if(!f.size() or f.back() != lp[x]) f.emplace_back(lp[x]);
			x /= lp[x];
		}

		return f;
	};

	vector<int> vis(MAX), mp(MAX);
	multiset<int> st;
	for(int i = 0; i < n; i++){
		vector<int> factv = fact(v[i]);

		if(!vis[v[i]]){
			for(auto p: factv){
				if(mp[p] > 0) st.erase(st.find(mp[p]));
				mp[p]++;
				st.insert(mp[p]);
			}
			vis[v[i]] = 1;
		} else{
			for(auto p: factv){
				st.erase(st.find(mp[p]));
				mp[p]--;
				if(mp[p]) st.insert(mp[p]);
			}
			vis[v[i]] = 0;
		}

		cout << (st.size() ? *st.rbegin() : 0) << endl;
	}

	exit(0);
};
