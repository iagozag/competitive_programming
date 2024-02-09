#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, a, q; cin >> n >> a >> q;
    vector<char> v(q);
    for(auto& x: v) cin >> x;

    int yes = a;
    for(auto& x: v)
        if(x == '+') yes++;
    
    bool flag = false;
    int now = a;
    if(now == n) flag = true;
    for(auto& x: v){
        if(x == '+') now++;
        else now--;

        if(now == n) flag = true;
    }

    if(flag) cout << "YES";
    else if(yes >= n) cout << "MAYBE";
    else cout << "NO";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
