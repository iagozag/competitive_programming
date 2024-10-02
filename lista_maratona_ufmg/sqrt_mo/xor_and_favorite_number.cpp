#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e6+1, MOD = 1e9+7;

int n, m; ll SQ, k;
ll v[MAX];

ll ans; ll prefl[MAX], prefr[MAX], freql[MAX], freqr[MAX];

void insert(int p, int b) {
    freqr[prefr[p]]++, freql[prefl[p]]++;

    if(b) ans += freqr[k^v[p]^prefr[p]];
    else ans += freql[k^v[p]^prefl[p]];
}

void erase(int p, int b) {
    if(b) ans -= freqr[k^v[p]^prefr[p]];
    else ans -= freql[k^v[p]^prefl[p]];

    freqr[prefr[p]]--, freql[prefl[p]]--;
}

ll hilbert(int x, int y) {
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

vector<ll> MO(vector<pair<int, int>> &q) {
	ans = 0;
	int sz = q.size();
	vector<int> ord(sz);
	iota(ord.begin(), ord.end(), 0);

	vector<ll> h(sz);
	for (int i = 0; i < sz; i++) h[i] = hilbert(q[i].first, q[i].second);
	sort(ord.begin(), ord.end(), [&](int l, int r) { return h[l] < h[r]; });

	vector<ll> ret(sz);
	int l = 0, r = -1;

	for (int i : ord) {
		int ql, qr;
		tie(ql, qr) = q[i];
		while (r < qr) insert(++r, 1);
		while (l > ql) insert(--l, 0);
		while (l < ql) erase(l++, 0);
		while (r > qr) erase(r--, 1);
		ret[i] = ans;
	}
	return ret;
}

void solve(){
    cin >> n >> m >> k; SQ = n/sqrt(m)+1;
    for(int i = 0; i < n; i++) cin >> v[i];

    fill(prefl, prefl+MAX, 0);
    fill(prefr, prefr+MAX, 0);
    fill(freql, freql+MAX, 0);
    fill(freqr, freqr+MAX, 0);

    prefl[0] = v[0], prefr[n-1] = v[n-1];
    for(int i = 1; i < n; i++) prefl[i] = prefl[i-1]^v[i];
    for(int i = n-2; i >= 0; i--) prefr[i] = prefr[i+1]^v[i];
    vector<pair<int, int>> qu;
    for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; --a, --b; qu.emplace_back(a, b); }

    vector<ll> a = MO(qu);
    for(auto x: a) cout << x << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
