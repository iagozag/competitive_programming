#include <algorithm>
#include<bits/stdc++.h>
#include <limits>
#include <utility>
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
    ll n, d; cin >> n >> d;
    vector<pair<ll,ll>> v;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.pb({a,b});
    }
    sort(all(v));

    ll sum = 0, maxi = 0;
    for(int i = 0, j = 0; i < n; ++i){
        while(j < n && v[j].f-v[i].f < d){
            sum += v[j].s, j++;
        }

        maxi = max(maxi, sum);
        sum -= v[i].s;
    }

    cout << maxi << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

