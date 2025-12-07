#include <bits/stdc++.h>
using namespace std;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int main() {
	int n; cin >> n;

    vector<int> v;
    int l = 0, r = 1e9, ans = 0, cnt = 60;
    while(l <= r){
        int m = l+(r-l)/2;

        cnt--;
        cout << "> " << m << endl;
        int q; cin >> q;
        if(q == 1) l = m+1;
        else ans = m, r = m-1; 
    }

    v.emplace_back(ans);

    vector<int> vis(n);
    for(int i = 0; i < cnt; i++){
        int j = uniform(0, n-1), lim = 100;
        while(vis[j] and lim--) j = uniform(0, n-1);
        vis[j] = 1;
        cout << "? " << j+1 << endl;
        int q; cin >> q; v.emplace_back(q);
    }

    sort(v.begin(), v.end());

    int g = 0;
    for(int i = 1; i < (int)v.size(); i++) g = __gcd(v[i]-v[i-1], g);
    cout << "! " << ans-(n-1)*g << ' ' << g << endl;
}
