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
	int n, k; cin >> n >> k;
	vector<pair<int,int>> v(n);
	for(int i = 0; i < n; i++) cin >> v[i].first;
	for(int i = 0; i < n; i++) cin >> v[i].second;
	int sum = 0;
	for(int i = 0; i < n; i++){
		if(v[i].first > v[i].second) swap(v[i].first, v[i].second);
		sum += v[i].second-v[i].first;
	}
	sort(v.begin(), v.end());
	
	int mi = LINF;
	for(int i = 0; i < n-1; i++){
		mi = min(mi, (abs(v[i].first-v[i+1].second)+abs(v[i].second-v[i+1].first))-(v[i].second-v[i].first+v[i+1].second-v[i+1].first));
	}

	cout << sum+max(0LL, mi) << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
