#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

typedef tuple<vector<int>, vector<int>, int> tp;

tp f(vector<int>& v){
	if(v.size() == 1) return {v, v, 1};

	vector<int> a, b;
	for(int i = 0; i < n; i++){
		if(i < n/2) a.emplace_back(v[i]);
		else b.emplace_back(v[i]);
	}

	tp t1 = f(a), t2 = f(b);
	vector<int> pl, pr;
	int sum = get<2>(t1)+get<2>(t2);



	return {pl, pr, sum};

}

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;
	
	auto [a, b, c] = f(v);
	cout << c << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
