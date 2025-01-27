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
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;
	sort(a.begin(), a.end()), sort(b.begin(), b.end());

	vector<int> ans, sum = 0, i = 0, j = 0, qnta = n, qntb = m, k = 0;

	while((qnta and qntb > 1) or (qnta > 1 and qntb)){
		if(a[n-i-1]-a[i] >= b[m-j-1]) sum += a[n-i-1]-a[i], i++, qnta -= 2, qntb--;
		else sum += b[m-j-1]-b[j], j++, qntb -= 2, qnta--;
		ans[k++] = sum;
	}

	cout << ans.size() << endl;
	if(!ans.size()) return;

	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
