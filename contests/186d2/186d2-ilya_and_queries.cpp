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

int MAX = 1e5+10; string str;
vi v(MAX);

int solve(){
    int l, r, ans = 0; cin >> l >> r; l--, r--;

    ans += v[r]-v[l];

    return ans;
}

int main(){ _
    int t; cin >> str >> t;

    for(unsigned i = 0; i < str.size(); i++)
        v[i+1] = v[i] + (str[i]==str[i+1]);

    while(t--){
        cout << solve() << endl;
    }

    exit(0);
}
