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
    int n, k; cin >> n >> k;
    bool flag = false;
    vi v(n);
    for(auto& x: v) cin >> x;

    if(v[0] == v[n-1] && count(all(v), v[0]) >= k)
        flag = true;

    int cnt = 0, idx = -1;
    for(int i = 0; i < n; i++){
        if(v[i] == v[0]) cnt++;
        if(cnt >= k){
            idx = i+1; 
            break;
        }
    }

    if(idx != -1)
        if(count(v.begin()+idx, v.end(), v[n-1]) >= k) flag = true;

    (flag) ? cout << "YES" : cout << "NO";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
