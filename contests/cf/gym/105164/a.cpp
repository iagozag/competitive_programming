#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10, MAX2 = 1e6+10;
const int SQ = sqrt(MAX);

typedef tuple<int, int, int, int> tp;

namespace seg {
	tp seg[4*MAX2];
	int n;

	tp build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = {0, INF, INF, -1};
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void buildd(int n2) {
		n = n2;
		build();
	}
	tp join(tp a, tp b){
		auto [qnt1, ans1, le1, ri1] = a;
		auto [qnt2, ans2, le2, ri2] = b;

		int best = min(ans1, ans2);
		if(le2 <= MAX2 and ri1 >= 0) best = min(best, le2-ri1);
		return {0, best, min(le1, le2), max(ri1, ri2)};
	}
	tp query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {0, INF, INF, -1};
		int m = (l+r)/2;
		return join(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	tp update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) {
			auto& [qnt, ans, le, ri] = seg[p];
			qnt += seg[p];
			if(qnt == 0) ans = INF, le = INF, ri = -1;
			else if(qnt == 1) ans = INF, le = l, ri = l;
			else ans = 0, le = l, ri = l;

			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = join(update(a, b, x, 2*p, l, m), 
			update(a, b, x, 2*p+1, m+1, r));
	}
};

int v[MAX];

int ans, freq[MAX2], ma = 0, cnt = 0;
multiset<int> st;

inline void insert(int p) {
	int o = v[p];
	seg::update(o, o, 1);
}

inline void erase(int p) {
	int o = v[p];
	seg::update(o, o, -1);
}

inline ll hilbert(int x, int y) {
	static int N = 1 << (__builtin_clz(0) - __builtin_clz(MAX));
	int rx, ry, s;
	ll d = 0;
	for (s = N/2; s > 0; s /= 2) {
		rx = (x & s) > 0, ry = (y & s) > 0;
		d += s * ll(s) * ((3 * rx) ^ ry);
		if (ry == 0) {
			if (rx == 1) x = N-1 - x, y = N-1 - y;
			swap(x, y);
		}
	}
	return d;
}

#define HILBERT true
vector<int> MO(vector<pair<int, int>> &q) {
	ans = 0;
	int m = q.size();
	vector<int> ord(m);
	iota(ord.begin(), ord.end(), 0);
#if HILBERT
	vector<ll> h(m);
	for (int i = 0; i < m; i++) h[i] = hilbert(q[i].first, q[i].second);
	sort(ord.begin(), ord.end(), [&](int l, int r) { return h[l] < h[r]; });
#else
	sort(ord.begin(), ord.end(), [&](int l, int r) {
		if (q[l].first / SQ != q[r].first / SQ) return q[l].first < q[r].first;
		if ((q[l].first / SQ) % 2) return q[l].second > q[r].second;
		return q[l].second < q[r].second;
	});
#endif
	vector<int> ret(m);
	int l = 0, r = -1;

	for (int i : ord) {
		int ql, qr;
		tie(ql, qr) = q[i];
		while (r < qr) insert(++r);
		while (l > ql) insert(--l);
		while (l < ql) erase(l++);
		while (r > qr) erase(r--);
		ret[i] = get<1>(seg::query(0, MAX2-1));
	}
	return ret;
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> v[i], ma = max(ma, v[i]);

	seg::buildd(MAX2);

	int q; cin >> q; vector<pair<int, int>> qu(q);
	for(int i = 0; i < q; i++) cin >> qu[i].first >> qu[i].second, --qu[i].first, --qu[i].second;

	vector<int> anss = MO(qu);
	for(auto x: anss) cout << x << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
