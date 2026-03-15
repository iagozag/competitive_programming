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
	int a[n], d[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> d[i];

	int L[n], R[n];
	for(int i = 0; i < n; i++){
		L[i] = i-1, R[i] = i+1;
	}

	set<int> pos; for(int i = 0; i < n; i++) pos.insert(i);
	for(int r = 0; r < n; r++){
		vector<int> dead;
		for(auto cur: pos){
			int damage = 0;
			if(L[cur] >= 0) damage += a[L[cur]];
			if(R[cur] < n) damage += a[R[cur]];

			if(damage > d[cur])
				dead.emplace_back(cur);
		}

		cout << (int)dead.size() << ' ';

		pos.clear();
		for(auto dd: dead){
			if(L[dd] >= 0) pos.insert(L[dd]);
			if(R[dd] < n) pos.insert(R[dd]);

			if(R[dd] < n) L[R[dd]] = L[dd];
			if(L[dd] >= 0) R[L[dd]] = R[dd];
		}

		for(auto dd: dead) pos.erase(dd);
	}

	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
