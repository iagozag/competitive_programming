#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m; 

void yes(){
	cout << "Yes" << endl;
}

void sum(int& a, int b){
	a += b; a %= n;
	if(a == 0) a = n;
}

void solve(){
	cin >> n >> m;
	vector<pair<int, int>> edges(m);
	for(auto& [a, b]: edges){
		cin >> a >> b;
		if(a > b) swap(a, b);
	}
	sort(edges.begin(), edges.end());

	vector<int> divisors;
	for(int i = 1; i <= n/2; i++) if(n%i == 0) divisors.emplace_back(i);

	for(auto d: divisors){
		auto tmp = edges;

		for(auto& [a, b]: tmp){
			sum(a, d), sum(b, d);
			if(a > b) swap(a, b);
		}
		sort(tmp.begin(), tmp.end());

		if(tmp == edges) return yes();
	}
	cout << "No" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

