#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, c, k;
vector<int> v;

void solve(){
	cin >> n >> c >> k;
	v = vector<int>(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int i = 0, j = 0, need = 0;
	while(i < n){
		while(j < n and v[j]-v[i] <= k and j-i+1 <= c) j++;
		need++, i = j;
	}

	cout << need << endl;

}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

