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

int main(){
    int t, n, neg = 0, pos = 0; cin >> t;
    ll a, ans;
    vector<ll> sequence;

    for(int i = 0; i < t; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> a;
            sequence.pb(a);
            if(a < 0) neg++;
            else pos++;
        }

        int subseq_qnt = min(pos, neg);
        
        cout << ans << endl;
        
        ans = 0;
        sequence.clear();
    }

    exit(0);
}
