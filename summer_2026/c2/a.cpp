#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;

	int left[n], right[n]; stack<int> st;
	for(int i = 0; i < n; i++){
		left[i] = -1;
		while(!st.empty() and v[st.top()] >= v[i]) st.pop();
		if(st.size()) left[i] = st.top();
		st.push(i);
	}

	st = stack<int>();
	for(int i = n-1; i >= 0; i--){
		right[i] = n;
		while(!st.empty() and v[st.top()] >= v[i]) st.pop();
		if(st.size()) right[i] = st.top();
		st.push(i);
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		int sz = min(v[i], right[i]-left[i]-1);
		ans = max(ans, sz);
	}

	cout << ans << endl;

	exit(0);
}
