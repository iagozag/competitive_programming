#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) (int) x.size()
#define ff first
#define ss second
#define int ll

const int MAX = 2e5 + 10;
namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n;
    vector<int> v;
	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, vector<int>& v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return LINF;
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m),query(a, b, 2*p+1, m+1, r));
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = min(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
	}

    void print(int p, int l, int r){
        prop(p, l, r);
        if(l == r) cout << l << " " << seg[p] << "\n";
        else {
            int m = (l +r)/2;
            print(p<<1, l, m), print(p << 1 | 1, m + 1, r);
        }
    }



    // primeira posicao < val em [a, b] (ou -1 se nao tem)
    int get_left(int a, int b, int val, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
        if (b < l or r < a or seg[p] >= val) return -1;
        if (r == l) return l;
        int m = (l+r)/2;
        int x = get_left(a, b, val, 2*p, l, m);
        if (x != -1) return x;
        return get_left(a, b, val, 2*p+1, m+1, r);
    }

};



int32_t main() { _
    int n, k; 
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){ cin >> v[i];}
    for(int i = 1; i < n; i ++) v[i] -= k*i;

    seg::build(sz(v), v);

    for(int i = 1; i < n; i ++) v[i] += k*i;
    for(int i = 0; i < n; i++){
        ll res = -1;
        if(i < n-1) res = seg::get_left(i+1, n-1,v[i]);
        if(i > 0 and res == -1) res = seg::get_left(0, i-1,v[i]);
        cout << (res == -1? i: res) + 1 << " ";
        
        
         if(i < n-1) seg::update(i+1, n-1, k);
        if(i > 0) seg::update(0, i-1, k);
        seg::update(i, i, -((n-1)*k));
    }
    cout << endl;

}
