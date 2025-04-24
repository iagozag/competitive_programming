#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 200010, MOD = 1e9+7;

namespace seg {
    ll seg[2*MAX];
    int n, *v;

    void build(int n2, int* v2) {
        n = n2, v = v2;
        for (int i = 0; i < n; ++i) {
            seg[n + i] = v[i];
        }
        for (int i = n - 1; i > 0; --i) {
            seg[i] = seg[2*i] + seg[2*i+1];
        }
    }

    ll query(int l, int r) {
        ll res = 0;
        l += n;
        r += n;
        while (l <= r) {
            if (l % 2 == 1) res += seg[l++];
            if (r % 2 == 0) res += seg[r--];
            l /= 2;
            r /= 2;
        }
        return res;
    }

    void update(int pos, int val) {
        pos += n;
        seg[pos] = val;
        for (pos /= 2; pos >= 1; pos /= 2) {
            seg[pos] = seg[2*pos] + seg[2*pos+1];
        }
    }

    int get_left(int a, int b, int val) {
        a += n;
        b += n;
        int res = -1;
        while (a <= b) {
            if (a % 2 == 1) {
                if (seg[a] >= val) {
                    res = a;
                    break;
                }
                a++;
            }
            if (b % 2 == 0) {
                if (seg[b] >= val) {
                    res = b;
                    b--;
                    continue;
                }
                b--;
            }
            a /= 2;
            b /= 2;
        }
        if (res == -1) return -1;
        while (res < n) {
            if (seg[2*res] >= val) {
                res = 2*res;
            } else {
                res = 2*res + 1;
            }
        }
        return res - n;
    }
};


void solve(){
	int n, k; cin >> n >> k;
	vector<int> v(n); for(auto& x: v) cin >> x;

	int l = 1, r = MAX, ans = 0;
	while(l <= r){
		int m = l+(r-l)/2;

		int cnt = 0, i = 0, j = 0;
		while(j < n and cnt < k){
			if(v[j] < MAX) seg::update(v[j], 0);

			j++;

			if(seg::get_left(0, MAX-1, 1) >= m){
				cnt++;
        		while(i < j){
        			if(v[i] < MAX) seg::update(v[i], 1);
        			i++;
        		}
			}
		}

		while(i < j){
        	if(v[i] < MAX) seg::update(v[i], 1);
			i++;
		}

		if(cnt >= k) ans = m, l = m+1;
		else r = m-1;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

	int arr[MAX]; for(int i = 0; i < MAX; i++) arr[i] = 1;
	seg::build(MAX, arr);

    while(ttt--) solve();

    exit(0);
}

