#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void no(){
	cout << -1 << endl;
}

void solve(){
	ll n; cin >> n;
	if(n&1){
		if(n < 27) return no();
		vector<int> ans = {1, 2, 2, 3, 3, 4, 4, 5, 5, 1, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 13, 13, 1, 12};
		int k = 14;
		while(ans.size() < n) ans.emplace_back(k), ans.emplace_back(k++);
		for(auto x: ans) cout << x << " ";
		cout << endl;
	} else{
		for(int i = 0; i < n; i++) cout << i/2+1 << " " << i/2+1 << " ", i++;
		cout << endl;
	}
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
