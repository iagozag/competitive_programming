#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
const int MAX = 2e5+10, MOD = 1e9+7;
 
int seg[4*MAX];
int n;
 
int query(int a, int b) {
	int ret = 0;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret += seg[a];
		if (b % 2 == 0) ret += seg[b];
	}
	return ret;
}
 
void update(int p, int x) {
	seg[p += n] += x;
	while (p /= 2) seg[p] = seg[2*p] + seg[2*p+1];
}
 
void solve(){
	int N; cin >> N;
	vector<tuple<int, int, int>> v(N); vector<int> st;
	int j = 0;
	for(auto& [a, b, c]: v) cin >> a >> b, st.emplace_back(a), st.emplace_back(b), c = j++;

	sort(st.begin(), st.end());
	st.erase(unique(st.begin(), st.end()), st.end());
 
	for(auto& [a, b, c]: v){
		a = (int)(lower_bound(st.begin(), st.end(), a)-st.begin());
		b = (int)(lower_bound(st.begin(), st.end(), b)-st.begin());
	}
 
 	int k = st.size();
	n = k;
 
	sort(v.begin(), v.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b){
		auto [x, y, z] = a;
		auto [x2, y2, z2] = b;
		if(x != x2) return x < x2;
		return y >= y2;
	});

	memset(seg, 0, sizeof seg);
 
	for(int i = 0; i < N; i++)
		update(get<1>(v[i]), 1);
 
	int in[N], out[N];
	memset(in, 0, sizeof in);
	memset(out, 0, sizeof out);

	for(int i = 0; i < N; i++){
		auto [a, b, c] = v[i];
		update(b, -1);
		in[c] = query(0, b);
	}
 
	for(int i = 0; i < N; i++){
		auto [a, b, c] = v[i];
		out[c] = query(b, n-1);
		update(b, 1);
	}
 
	for(auto x: in) cout << min(1LL, x) << ' ';
	cout << endl;
	for(auto x: out) cout << min(1LL, x) << ' ';
	cout << endl;
}
 
int32_t main(){ _
    int ttt = 1; // cin >> ttt;
 
    while(ttt--) solve();
 
    exit(0);
}
