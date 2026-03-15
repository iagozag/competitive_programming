#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){
	int n, k, x, a, b, c; cin >> n >> k >> x >> a >> b >> c;
	vector<int> v(n); v[0] = x;
	for(int i = 1; i < n; i++) v[i] = (a*v[i-1]+b)%c;

	deque<int> dq;
	int l = 0, r = 0, ans = 0;
	while(r < n){
		while(r-l < k){
			while(dq.size() and dq.back() > v[r]) dq.pop_back();
			dq.push_back(v[r++]);
		}

		ans = ans^dq.front();

		if(dq.front() == v[l]) dq.pop_front();
		l++;
	}

	cout << ans << endl;
	exit(0);
}

