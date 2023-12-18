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
    int n; cin >> n;
    vi v(n), vb(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a; v[i] = a, vb[n-i-1] = a;
    }

    int i = 1; bool flag = true;
    for(auto& a: v){
        int dist = lower_bound(vb.begin(), vb.end(), i)-vb.begin();
        i++;

        if(n-dist != a){
            flag = false;
            break;
        }
    }

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
