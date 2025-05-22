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
	int n, x; cin >> n >> x;
	vector<pair<int, int>> v(n);
	int k = 0;
	for(auto& y: v) cin >> y.first, y.second = k++;
	sort(v.begin(), v.end());

	if(n < 4){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	map<int, pair<int, int>> mp1, mp2;
	for(int i = 0; i < n/2; i++) for(int j = i+1; j < n/2; j++){
		mp1[v[i].first+v[j].first] = {i, j};
	}

	for(int i = n/2; i < n; i++) for(int j = i+1; j < n; j++)
		mp2[v[i].first+v[j].first] = {i, j};

	for(auto [a, b]: mp1){
		if(mp2.count({x-a})){ 
			auto [c, d] = mp2[x-a];
			cout << b.first+1 << ' ' << b.second+1 << ' ' << c+1 << ' ' << d+1 << endl;
			return;
		}
	}

	for(int i = 0; i < n/2-3; i++){
		for(int j = i+1; j < n/2-2; j++){
			int l = j+1, r = n/2-1;
			while(l < r){
				int tot = v[i].first+v[l].first+v[l].first+v[r].first;
				if(tot == x){
					cout << v[i].second+1 << ' ' << v[j].second+1 << ' ' << v[l].second+1 << ' ' << v[r].second+1 << endl;
					return;
				}
				if(tot < x) l++;
				else r--;
			}
		}
	}

	for(int i = n/2; i < n-3; i++){
		for(int j = i+1; j < n-2; j++){
			int l = j+1, r = n-1;
			while(l < r){
				int tot = v[i].first+v[l].first+v[l].first+v[r].first;
				if(tot == x){
					cout << v[i].second+1 << ' ' << v[j].second+1 << ' ' << v[l].second+1 << ' ' << v[r].second+1 << endl;
					return;
				}
				if(tot < x) l++;
				else r--;
			}
		}
	}



	cout << "IMPOSSIBLE" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
