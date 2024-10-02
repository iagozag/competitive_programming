#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5e5+1, MOD = 1e9+7;
int S;

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

struct query{
    int l, r, idx; ll ord;
    query() {}
    query(int a, int b, int i): l(a), r(b), idx(i), ord(hilbert(l, r)) {}
    bool operator<(query ot) const{
        return ord < ot.ord; 
    }
};

void solve(){
    int n; cin >> n;
    int v[n]; for(int i=0;i<n;i++) cin >> v[i]; 
    int q; cin >> q; S = n/sqrt(q); query qu[q];
    for(int i = 0; i < q; i++){ int a, b; cin >> a >> b; --a, --b; qu[i] = query(a, b, i); }
    sort(qu, qu+q);

    int l = 0, r = -1; stack<int> el; 
    int freq[MAX], ok[MAX]; fill(freq, freq+MAX, 0), fill(ok, ok+MAX, 0);
    auto add = [&](int x){
        freq[x]++;
        if(!ok[x] and freq[x] == 1) el.push(x), ok[x] = 1;
    };
    auto rem = [&](int x){
        freq[x]--;
        if(!ok[x] and freq[x] == 1) el.push(x), ok[x] = 1;
    };

    int ans[q]; fill(ans, ans+q, 0);
    for(int i = 0; i < q; i++){
        auto [a, b, idx, o] = qu[i];
        while(l > a) add(v[--l]);
        while(r < b) add(v[++r]);
        while(l < a) rem(v[l++]);
        while(r > b) rem(v[r--]);

        while(el.size() and freq[el.top()] != 1) ok[el.top()] = 0, el.pop();
        if(el.size()) ans[idx] = el.top();
    }

    for(int i=0;i<q;i++) cout << ans[i] << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
