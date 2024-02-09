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
    int n; cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        int a; cin >> a; mp[a]++;
    }

    int maxi = -1, M = mp.size();
    for(auto& x: mp) if(maxi < x.s) maxi = x.s;

    (maxi == mp.size()) ? cout << maxi-1 : cout << min(maxi, M);
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
