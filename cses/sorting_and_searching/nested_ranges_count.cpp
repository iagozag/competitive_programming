#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> seg;
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
	vector<tuple<int, int, int>> v(N); set<int> st;
	int j = 0;
	for(auto& [a, b, c]: v) cin >> a >> b, st.insert(a), st.insert(b), c = j++;

	int k = 0; map<int, int> mp;
	for(auto x: st) mp[x] = k++;
	for(auto& [a, b, c]: v) a = mp[a], b = mp[b];

	n = k;
	seg = vector<int>(2*k);

	sort(v.begin(), v.end());
	for(int i = 0; i < N; i++)
		update(get<1>(v[i]), 1);

	vector<int> in(N), out(N);
	for(int i = 0; i < N; i++){
		update(get<1>(v[i]), -1);
		in[get<2>(v[i])] = query(0, get<1>(v[i]));
	}

	for(int i = 0; i < N; i++){
		out[get<2>(v[i])] = query(get<1>(v[i]), n-1);
		update(get<1>(v[i]), 1);
	}

	for(auto x: in) cout << x << ' ';
	cout << endl;
	for(auto x: out) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
