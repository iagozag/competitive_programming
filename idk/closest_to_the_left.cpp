#include <algorithm>
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
    ll n, k; cin >> n >> k;
    vector<ll> va(n), vk(k);
    for(auto& x: va) cin >> x;
    for(auto& x: vk){
        cin >> x;
        
        int l = 0, r = n;
        while(l < r){
            int m = (l+r)/2;
            if(va[m] <= x) l = m+1;
            else r = m;
        }

        cout << l << endl;
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
