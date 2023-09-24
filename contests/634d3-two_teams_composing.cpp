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

int n, MAX = 2e5+10;


bool is_possible(int m, map<int,int> mp){
    bool flag = false;
    for(auto& x: mp) if(x.s >= m) { x.s -= m, flag = true; break; }
    if(!flag) return false;

    int k = 0;
    for(auto& x: mp){
        if(x.s) k++;
        if(k >= m) return true;
    }

    return false;
}

void solve(){
    cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        int a; cin >> a; mp[a]++;
    }

    int l = 0, r = 2e5+10;
    while(l < r){
        int m = (l+r)/2;
        if(is_possible(m+1, mp)) l = m+1;
        else r = m;
    }

    cout << l << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
