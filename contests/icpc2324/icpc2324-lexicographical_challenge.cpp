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
    string str; int k; cin >> str >> k;
    int N = str.size();
    vector<char> ans(N);

    for(int i = 0; i < k; i++){
        vector<char> c;
        int j = i;
        while(j < N) c.pb(str[j]), j += k;
        sort(all(c));

        int l = 0; j = i;
        while(l < c.size()) ans[j] = c[l], j += k, l++;
    }

    for(auto& x: ans) cout << x;
    cout << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
