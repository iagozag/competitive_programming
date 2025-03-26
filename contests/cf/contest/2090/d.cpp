#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10, MOD = 1e9+7;

vector<int> pr;
vector<int> lp(1e7+1);
vector<int> np(MAX);

void solve(){
	int n; cin >> n;
	int beg = pr[lower_bound(pr.begin(), pr.end(), n/2)-pr.begin()];
	cout << beg << ' ';

	int i;
	for(i = 1; i <= n and beg-i >= 1 and beg+i <= n; i++){
		cout << beg-i << ' ' << beg+i << ' ';
	}
	
	if(beg-i >= 1) for(int j = 1; j <= beg-i; j++) cout << j<< ' ';
	else for(int j = beg+i; j <= n; j++) cout << j << ' ';
	
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

	for (int i=2; i <= 1e7; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; i * pr[j] <= 1e7; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) {
				break;
			}
		}
	}

    while(ttt--) solve();

    exit(0);
}
