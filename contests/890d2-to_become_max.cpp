#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, k;
vector<int> v;

bool possible(int guess){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){

        }
    }

    return true;
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a; cin >> a; v.pb(a);
    }

    int l = 0, r = *max_element(v.begin(), v.end())+k;
    while(l < r){
        int m = (l+r)/2;

        if(possible(m)) l = m;
        else r = m-1;

        cout << "\nl/r/m " << l << "/" << r << "/" << m << endl;
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
