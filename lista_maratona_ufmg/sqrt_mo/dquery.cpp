#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7, S = 450;

struct query{
    int l, r, idx;
    query(int _l, int _r, int _idx): l(_l), r(_r), idx(_idx){}
    bool operator<(query other) const{
        return make_pair(l/S, r) < make_pair(other.l/S, other.r);
    }
};

void solve(){
    int n; cin >> n;
    vector<int> v(n); for(auto&x: v) cin >> x, --x; 

    int q; cin >> q; vector<query> qu;
    for(int i = 0; i < q; i++){ int a, b; cin >> a >> b; --a, --b; qu.emplace_back(a, b, i); }
    sort(qu.begin(), qu.end());

    int l = 0, r = -1, qnt = 0;
    vector<int> freq(1e6);
    auto add = [&](int i){
        if(!freq[v[i]]) qnt++;
        freq[v[i]]++;
    };

    auto rem = [&](int i){
        freq[v[i]]--;
        if(!freq[v[i]]) qnt--;
    };

    vector<int> ans(q);
    for(int i = 0; i < q; i++){
        auto [a, b, idx] = qu[i];
        while(l > a) add(--l);
        while(r < b) add(++r);
        while(l < a) rem(l++);
        while(r > b) rem(r--);

        ans[idx] = qnt;
    }
    for(auto x: ans) cout << x << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
