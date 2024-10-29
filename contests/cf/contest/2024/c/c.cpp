#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<pair<int, int>> v(n); for(auto& [a, b]: v) cin >> a >> b;
	sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
		if(min(a.first, a.second) != min(b.first, b.second)) return min(a.first, a.second) < min(b.first, b.second);
		return max(a.first, a.second) < max(b.first, b.second);
	});

	for(auto x: v) cout << x.first << " " << x.second << " "; 
	cout << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
