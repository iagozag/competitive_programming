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
	vector<tuple<int, int, int>> comp;
	for(int i = 0; i < n; i++){
		int a, b, c; cin >> a >> b >> c; comp.emplace_back(a, b, c);
	}

	sort(comp.begin(), comp.end(), [&](const tuple<int, int, int> a, tuple<int, int, int> b){
		auto [id1, prob1, pen1] = a;
		auto [id2, prob2, pen2] = b;
		if(prob1 != prob2) return prob1 > prob2;
		if(pen1 != pen2) return pen1 < pen2;
		return id1 < id2;
	});

	int pos = 0;
	for(int i = 0; i < n; i++){
		if(i == 0 or get<1>(comp[i-1]) != get<1>(comp[i]) or get<2>(comp[i-1]) != get<2>(comp[i])) pos = i+1;
		cout << pos << ' ';
		cout << get<0>(comp[i]) << ' ' << get<1>(comp[i]) << ' ' << get<2>(comp[i]) << endl;
		
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
